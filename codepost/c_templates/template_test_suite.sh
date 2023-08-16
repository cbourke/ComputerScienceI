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
#  - cmocka outputs the number of tests failed (0 for all pass)
#  - our convention:
#    - by default it will report number of failed tests (0 all pass)
#    - via CLA "-reportPass" it will report the total passed
#    Thus we run it twice and capture both values

numExpected=18
executeCmd='./colorUtilsTester'
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
  TestOutput "Correctness" "Student Test Suite" false "$message"
elif [ $numPass -lt $numExpected ]; then
  message="$output
Result: FAIL, $numPass tests passsed, but expected at least $numExpected"
  TestOutput "Correctness" "Student Test Suite" false "$message"
else
  message="Result: PASS, $numPass tests passsed"
  TestOutput "Correctness" "Student Test Suite" true "$message"
fi
