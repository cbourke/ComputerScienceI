#!/usr/bin/php
<?php

$taLogins = array("cbourke", "login1", "login2");

function filterTAs($line) {
  $x = trim($line);
  global $taLogins;
  if( empty($x) ) {
    return false;
  }
  foreach($taLogins as $l) {
    if(strncmp($l, $line, strlen($l)) == 0) {
      return false;
    }
  }
  return true;
}

$f = file_get_contents($argv[1]);
$names = preg_split("/((\r?\n)|(\r\n?))/", $f);
$students = array_filter($names, "filterTAs");
shuffle($students);

//print_r($students);

for($i=0; $i<count($students)-1; $i+=2) {
  $p = floor($i / 2) + 1;
  printf("Pair %d\n", $p);
  printf("  %s \n", $students[$i]);
  printf("  %s \n", $students[$i+1]);
}

//if there is an odd-man out:
if( count($students) % 2 === 1 ) {
  printf("Odd Student Out:\n");
  printf("  %s \n", $students[count($students)-1]);
}


?>
