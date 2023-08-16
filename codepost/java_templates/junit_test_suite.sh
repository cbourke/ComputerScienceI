#######################################################################################
# This file will be run from main.sh. Create test results by calling the following function:
# TestOutput <categoryName [string]> <testName [string]> <result[boolean]> <log[string]>
######################################################################################

# Convention: exit code
# This script is intended to run self-contained test suites, either
# ad-hoc or cmocka suites.
#
# The exit code is used to determine pass/failure of the codepost.io
# test.
#  - our convention:
#    - by default it will report number of failed tests (0 all pass)
#    - via CLA "-reportPass" it will report the total passed
#    Thus we run it twice and capture both values

numExpected=100
#we don't run the standalone, we just use it; we want the
# ability to report number of passed/failed tests as exit codes...
executeCmd='java -cp .:./junit-platform-console-standalone-1.9.2.jar unl.soc.TestWrapper unl.soc.ColorUtilsTests'
input=''
## Alternative: CLAs
output=$($executeCmd $input 2>&1)
numFail=$(($?))
input='-reportPass'
output=$($executeCmd $input 2>&1)
numPass=$(($?))

if [ $numFail -gt 0 ]; then
  message="$output
Result: FAIL, $numFail tests failed"
  TestOutput "Correctness" "JUnit Test Suite" false "$message"
elif [ $numPass -lt $numExpected ]; then
  message="$output
Result: FAIL, $numPass tests passsed, but expected at least $numExpected"
  TestOutput "Correctness" "JUnit Test Suite" false "$message"
else
  message="Result: PASS, $numPass tests passsed"
  TestOutput "Correctness" "JUnit Test Suite" true "$message"
fi
