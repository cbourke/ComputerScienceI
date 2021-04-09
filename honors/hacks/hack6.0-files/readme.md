
# Installing and Using JUnit 5 in Eclipse

## Installing 

First, we need to add the JUnit library to your project.

1. Right-click your project in the Project Explorer
2. Select "Build Path" and then "Add Libraries..."
3. Select JUnit then "Next"; make sure to select JUnit 5 and click "Finish"

You should be able to copy any provided JUnit source code
into your project now.  

## Using JUnit

To run a JUnit test suite, simply open the testing file and hit the
"play" button as you would a normal program.  Eclipse will 
automatically compile a report of the number of tests passed or
failed along with any messages provided for failed test cases.

Note that there is no `main` method in a JUnit test suite.  Instead, 
JUnit uses "reflection" to automatically find unit tests (methods 
identified by the `@Test` annotation) and run them.  

## Other Items

### Manually Installing

If for some reason JUnit 5 is not available as an option, you can download
and install it manually in your project.  

* On the JUnit website, https://junit.org/junit5/ click the "Platform" tag
  under the "Latest Release" section
* Click the download icon for "junit-platform-console-standalone" and select
"jar" (this should download a file named `junit-platform-console-standalone-1.7.0.jar`)
* Create a `lib` folder in your Eclipse project and drag/drop/copy the downloaded
jar file to this directory.
* Right click the copied jar file and select "Build Path" and then "Add to Build Path"


### Project Setup

In larger Java projects it is typical to keep source code and 
testing code in separate locations.  With JUnit this is usually 
done by putting source code in a `src/main/java` folder and JUnit 
test code in a `src/test/java` folder.  In addition, JUnit tests are 
usually located in the same package structure as the classes 
they are testing.

To setup your Eclipse project this way:
1. Right-click your project and select "Build Path" and select "New Source Folder"
2. Create the source folder `src/main/java` (repeat this for `src/test/java`) 
3. Move any code you might have had in the original `src` folder to the appropriate new folder

