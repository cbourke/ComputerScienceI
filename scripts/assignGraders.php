#!/usr/bin/php
<?php

class Person {

  private $name = null;
  private $login = null;

  public function __construct($login, $name = null) {
    $this->login = trim($login);
    $this->name = $name;
  }

  public function getLogin() {
    return $this->login;
  }

  public function getName() {
    return $this->name;
  }

  public function __toString() {
    return sprintf("%-14s %s", $this->login, $this->name);
  }

  public static function comparePersons($a, $b) {
    return strcmp($a->getLogin(), $b->getLogin());
  }

}

class Course {

  private $students = array();
  //non-grading instructors
  private $tas = array();
  private $graders = array();

  public function __construct($taLogins = array(), $graders = array(), $mailListFile = "./mail.list") {
    if(!file_exists($mailListFile)) {
      printf(STDERR, "Unable to open mail.list file: %s...\n", $mailListFile);
      exit(1);
    }
    $handle = fopen($mailListFile, "r");

    while(!feof($handle)) {
      $line = fgets($handle);
      if(strlen(trim($line)) > 0) {
        $tokens = explode(" ", $line);
        $name = "";
        for($i=1; $i<count($tokens); $i++) {
          if(strlen(trim($tokens[$i])) > 1) {
	          $name .= "$tokens[$i] ";
	        }
        }
        $login = trim($tokens[0]);
        $p = new Person($login, trim($name));
        if( in_array($login, $taLogins) ) {
          $this->tas[] = $p;
        } else if( in_array($login, $graders) ) {
          $this->graders[] = $p;
        } else {
          //student
          $this->students[] = $p;
        }
      }
    }
  }

  public function __toString() {
    $result = "TAs/Instructors (".count($this->tas).")\n";
    $result .= "=================\n";
    foreach($this->tas as $t) {
      $result .= "$t\n";
    }
    $result .= "\nGraders (".count($this->graders).")\n";
    $result .= "-----------------\n";
    foreach($this->graders as $g) {
      $result .= "$g\n";
    }
    $result .= "\n\nRoster (".count($this->students).")\n";
    $result .= "=================\n";
    foreach($this->students as $s) {
      $result .= "$s\n";
    }
    return $result;
  }

  public function getStudents() {
    return $this->students;
  }

  public function getTas() {
    return $this->tas;
  }

  public function assignGrading() {
    //strategy: randomly assign students to graders evenly
    $students = $this->students;
    $graders = $this->graders;
    shuffle($students);
    shuffle($graders);
    $studentsPerGrader = floor( count($students) / count($graders) );
    $assignment = array();
    $i = 0;
    foreach($graders as $grader) {
      $assigned = array();
      for($j=0; $j<$studentsPerGrader; $j++) {
        $assigned[] = $students[$i];
        $i++;
      }
      $assignment[$grader->getLogin()] = $assigned;
    }
    //evenly assign left over students
    foreach($graders as $grader) {
      if($i<count($students)) {
        array_push($assignment[$grader->getLogin()], $students[$i]);
        $i++;
      }
      usort($assignment[$grader->getLogin()], "Person::comparePersons");
    }
    return $assignment;
  }

  public function assignGradingToString() {
    $assignment = $this->assignGrading();
    $min = floor( count($this->students) / count($this->graders) );
    $max = ceil( count($this->students) / count($this->graders) );    
    $result = "Assigned Grading:\n";
    $result .= sprintf("Number of graders:  %3d\n", count($assignment));
    $result .= sprintf("Number of students: %3d\n", count($this->students));
    $result .= sprintf("Each grader will grade %d - %d students\n", $min, $max);
    foreach($assignment as $grader => $graded) {
      $result .= sprintf("%s (%d assigned)\n", $grader, count($graded));
      foreach($graded as $s) {
        $result .= "\t" . $s . "\n";
      }
    }

    return $result;
  }

}

//TODO: update these logins to exclude them from grading assignments
$instructors = array("cbourke", "inst2");
$gtas        = array("gta1", "gta2");
$courseLeaders = array("cl1", "cl2");
$graders = array("grader1login", "grader2login");

$nonGraders = array_merge($instructors, $gtas, $courseLeaders);

if($argc == 1) {
  $c = new Course($nonGraders, $graders);
} else {
  $c = new Course($nonGraders, $graders, $argv[1]);
}
print $c;
$assignment = $c->assignGradingToString();
print $assignment;

?>
