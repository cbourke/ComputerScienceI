
## Unit Testing

  * A *unit* is a piece of code (usually a function) that can be tested
  * A unit test is an input-output pair that is known to be correct
  * We unit test by feeding the input into our unit (function) and comparing the result to the *known correct* output
  * If they match, that unit test passes
  * If they do not match, that unit test fails
  * a collection of unit tests is known as a *test suite*
  * IF a future bug is reported, then you have a new unit test to debug and test with!
  * A future change or fix that breaks other unit tests is known as a *regression*
  * The more tests you have the higher certainty you have that your code is correct
  * NO amount of tests will ever guarantee that your code is 100% correct!
  * Make sure that you have good "code coverage":
    * You want to test corner cases
    * Edge cases, extreme cases, etc.
    * Randomized tests
  * A *false positive* is when a test case is wrong but the code is correct
  * A *false negative* there is a bug but your tests do not indicate it: most likely because you didn't write your test case correctly
    * You come up with the expected input/output BEFORE you code
    * TDD = Test Driven Development
