#######################################################################################
# This file will be run from main.sh. Create test results by calling the following function:
# TestOutput <categoryName [string]> <testName [string]> <result[boolean]> <log[string]>
######################################################################################

# this could be done in a loop if multiple source files are present
# however, a single test should be created for each part to communicate
# which source files have warnings or issues
source="FILE.c"
#compile redirecting stderr to stdout
result=$(gcc -w $source 2>&1)

#if result is not empty
if ! [[ -z "$result" ]]; then
  message="Your code does not appear to compile:
$result"
  #echo "$message"
  TestOutput "Build Tests" "Compiler Output" false "$message"
else
  message="Your code compiles with no errors."
  #echo "$message"
  TestOutput "Build Tests" "Compiler Output" true "$message"
fi
