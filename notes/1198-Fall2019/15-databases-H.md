# CSCE 155H 
## Fall 2019 - Databases

* Data is fundamental
* In C: `int`, `double`, `char *`
* In Java: `Integer`, `String`
* In C: structures, in Java: classes: collect pieces of data together to form larger *entities*
* Entities also have *relationships*: composition
* But: programs are ephemeral: short lived
* We need a way for our data to survive or *persist* across multiple runs  of a program or programS: *persistence* (saving)
* Data formatting (so far): 
  * CSV: comma separated values
  * XML: eXstensible Markup Language
  * JSON: JavaScript Object Notation
  * EDI: Electronic Data Interchange

* Disadvantages:
    * To find a particular record or records requires processing the entire file
    * There is no easy way for multiple programs to access the same file at the same time (file locks)
    * No format enforcement: repetition of data, no integrity enforcement, etc.

## Solution: RDBMS (Relational Database Management System)

* Data is stored in *tables*
* Tables have columns which are individual pieces of data
* Tables have rows which correspond to a full record of data
* Data in different tables can be related to each other
* Example Author/Book: An author may have written multiple books: one-to-many relationship
  * One-to-many relations: one record in table A can refer to multiple records in table B through a foreign key
  * A is referred to as the parent table, B is the child table
  * The foreign key is placed in the child table and refers back to the parent table
* Example: what if a book can have multiple authors?
  * Many-to-many relation: one record in table A cna refer to multiple records in table B and vice versa
  * Generally, this requires an intermediate, "join table"

* Databases provide many nice features:
    * Security
    * Data storage can now be done with a remote database server instead
    * Enforce data integrity and relations: you cannot create a book record (say) without first creating an author record; you cannot put a string value into a numerical column
    * Constraints: suppose an author's last name is *required*; the database will enforce that constraint
    * Multiuser/parallel access/etc.
    
#### ACID Principles

    * RDBMS provide access to data through *transactions*
    * Atomicity - a transaction is an all-or-nothing operation: either the entire transaction is successful or none of it is
    * Consistency - a database will always remain in a consistent state: before a transaction occurs, all rules you've defined will be followed; and after a transaction is successful (committed) all rules will be followed, but in between rules may be temporarily broken
    * Isolation - No transaction steps on the toes of another transaction
    * Durability - once a transaction is committed, it remains so

## CRUD

* Databases provide access to data through the Structured Query Language (SQL) (not ISUD)
* Create - Inserting new records in a database
* Retrieve - Selecting existing records out of the database
* Update - Updating current records in the database
* Destroy - Removing/deleting records in a database



