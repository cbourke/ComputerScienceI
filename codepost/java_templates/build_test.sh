#######################################################################################
# This file will be run from main.sh. Create test results by calling the following function:
# TestOutput <categoryName [string]> <testName [string]> <result[boolean]> <log[string]>
######################################################################################

# this could be done in a loop if multiple source files are present
# however, a single test should be created for each part to communicate
# which source files have warnings or issues
baseClass="CLASS"
package="unl.soc"
classPath="./unl/soc/CLASS.class"
#compile redirecting stderr to stdout
result=$(javac -nowarn -cp . -d . $baseClass.java 2>&1)

#if result is not empty
if [[ ! -z "$result" ]]; then
  message="Your code does not appear to compile or compiles with warnings:
$result"
  #echo "$message"
  TestOutput "Build Tests" "Compiler Output" false "$message"
elif [[ ! -f "$classPath" ]]; then
  message="Your code appears to have compiled but the class file cannot be found; be sure you are using the expected package: $package"
  #echo "$message"
  TestOutput "Build Tests" "Compiler Output" false "$message"
else
  message="Your code compiles with no errors or warnings."
  #echo "$message"
  TestOutput "Build Tests" "Compiler Output" true "$message"
fi
