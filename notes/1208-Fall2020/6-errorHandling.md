
# CSCE 155E - Computer Science I
## Error Handling
### Fall 2020

* Programs always have potential for errors
* Some errors can be unexpected
* Many errors *can* be anticipated and protected against
  * We can anticipate and write code to *handle* those errors
  * Or we can let the errors be *fatal*
* In C our general strategy will be *defensive programming*
  * Identify potential errors that could cause problems
  * Write code to *look before you leap*: check for potential error conditions before you perform potentially dangerous operations
  * You then (in some way) report an error back to the calling function
  * We'll do this through integer values called *error codes*
  * By convention zero will be associated with no error
  * Non-zero (positive) values will be associated with various different types of errors
  * Now that we have pass-by-reference functions, we can use the return value to communicate error codes back to the calling function!
* Common mistakes:
  * You do NOT echo/print an error message inside a function!
  * You do *not* generally make errors inside a function fatal (you don't call `exit()`)
  