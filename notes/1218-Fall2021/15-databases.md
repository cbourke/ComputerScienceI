# Computer Science I 
## Fall 2021 - Databases


* Data is fundamental
* In C: `int`, `double`, `char *`
* Entities: structures (`struct`s): collections of data (records)
* Relations between entities: composition (one structure can be *composed* of anther structure(s))
* But: programs are short lived ("ephemeral")
* We need a way to "save" data from one program to another
* Data needs to be *persisted*
* Storing data so far: in files
  * CSV: Comma Separated Value or "flat files"
  * XML: eXstensible Markup Language: represents data as a tree-hierarchy using semantic markup
  * JSON: JavaScript Object Notation
  * EDI: Electronic Data Interchange

* Disadvantages:
  * To find a particular record or records requires processing the entire file
  * There is no easy way for multiple programs to access the same file at the same time (file locks)
  * No format enforcement: repetition of data, no integrity enforcement, etc.

## Solution: RDBMS (Relational Database Management System)

* Data is stored in *tables*
* Each "table" contains columns (individual pieces of data)
* Each table has rows (individual records)
* A database defines *relations* between tables
* Example: Author/Book tables
* Relations:
  * One-to-many relationship: one record in table A can relate to one or more (many) records in table B
  * Many-to-many relationship: multiple records in table A can relate to multiple records in table B
  * Many to many: one record in table A can relate to many records in table B AND one record in table B can relate (back) to many records in table A
* One author may have written many books: one-to-many relation from the author table to a book table
* What about the relationship from the book table to the author table?  Many-to-one relation
* What if you wanted to model the situation where one book could be written by multiple authors?  Many-to-many relationship
* In an RDBMS, records are identified with a Primary Key and
* Relationships between records are identified with a Foreign Key

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

* Database provide access through the Structured Query Language (SQL)
* Create - inserting new records into a table
* Retrieve - selecting data out of a table or tables
* Update - modifying current data in the database
* Destroy - removing a record in a table (or tables)
