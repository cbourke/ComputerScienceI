#######################################################################################
# This file will be run from main.sh. Create test results by calling the following function:
# TestOutput <categoryName [string]> <testName [string]> <result[boolean]> <log[string]>
######################################################################################

# The default output messages on CodePost are terrible, they expose
# regex patterns to students who will be confused and befuddled by
# this magic.  Intead, we define:
#  Expected output (to compare their output for visual inspection)
#  Individual *parts* or portions that *must* appear in their output
#     (formatted in a human/student readable format)
#  Individual *patterns* that CodePost would otherwise use to pass/fail
#     a test case; regular expressions are supported and they are  case
#     insensitive and ignore whitespace variations

#codepost does not capture stderr; if we expect it, then we must manually redirect
executeCmd='./EXECUTABLE'
input=''
#full, formatted expected output (for the failure message)
expectedOutput="FOO"
#individual, formatted output part(s) each expected to be part of the
# output (for the failure message)
expectedParts=(
  "FOO"
  "BAR"
  "BAZ"
)
# patterned (regex) versions of the expected output; each pattern
# must be in the output result or the test will fail (casing and
# whitespace are ignored)
expectedPatterns=(
  "FOO"
  "BAR"
  "BAZ"
)

#####################################################################
# interactive input, we echo and pipe:
#result=$(echo $input | $executeCmd)
## Alternative: CLAs
result=$($executeCmd $input 2>&1)

## Format the message
comparison="
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
+-----------------+
| Expected Output |
+-----------------+
$expectedOutput
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
+-----------------+
| Your Output     |
+-----------------+
$result
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
"
# return true if the first string contains the second
# ignoring whitespace and casing; regexp are supported
# as this uses grep
# Ex: if contains_ignore_whitespace "foobar" "foo";
contains_ignore_whitespace() {
  #strip all whitespace from a and b
  local str="$1"
  str=${str//[[:space:]]/}
  local substr="$2"
  substr=${substr//[[:space:]]/}
  grep -q -i -e "$substr" <<< "$str"
}

#PASS only if all patterns are present
allPass=true
addendum=""

#for expectedPattern in "${expectedPatterns[@]}"
#for i = 0..
for i in "${!expectedPatterns[@]}"; do
  pattern=${expectedPatterns[$i]}
  if ! contains_ignore_whitespace "$result" "$pattern"; then
    allPass=false
    addendum="$addendum
  -Your output does not appear to contain '${expectedParts[$i]}'"
  fi
done

if [ "$allPass" = true ]; then
  addendum="Result: SUCCESS, Your output appears to contain all necessary elements."
  message="$comparison$addendum"
  #echo "$message"
  TestOutput "Correctness" "Test XXX" true "$message"
else
  addendum="Result: FAIL$addendum"
  message="$comparison$addendum"
  #echo "$message"
  TestOutput "Correctness" "Test XXX" false "$message"
fi
