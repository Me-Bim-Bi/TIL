# Database

## Content:
1. SQLite:
2. MariaDB:
3. Node.js:
4. JavaScript:
5. JavaScript connect to MySQL:
6. ER modellering


===============================================================================

## 1. SQLite:
- User DB browser for SQLite
- **Basic commands:**
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|`CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT);`| Create a table named test, if it was not exists in database with two elements: id and name.|
|`DROP TABLE IF EXISTS test;`| Drop a test table if it was exists in database |
|`SELECT name FROM sqlite_master WHERE type = 'table' AND name='test';`| Check the positions of table if it exists in database. Returns None if the table does not exist in the database |
|`select * from burger b join order_burger ob on b.id = ob.burger_id join orders o on ob.order_id = o.id join items i on ob.items_id = i.id where o.id = ?`|Join data in table burger with tabler order_burger, table items with table order_burger based on burger_id, order_id, items_id |
|`INSERT INTO burger (id, name) VALUES (1, "cheese burger")`| Insert a row in table burger with two elements: id = 1 and name = cheese burger|
|`('SELECT id FROM items WHERE name = ? AND type = ? AND action = ?',(item_name, item_type, action))`| pull data of item_name, item_type, action based on items_id|
|`('INSERT INTO order_burger (order_id, burger_id, items_id) VALUES (?, ?, ?)',(order_id, burger_id, item_id))`|insert input data to database|
|`with sqlite3.connect('orders.db') as conn:...`|use this code to open database so that database will be closed outside "with"|

==========//==========//==========//==========//==========//==========//==========

## 2. MariaDB:
### a. Installing and using MariaDB via Docker:
- **Install:** https://mariadb.com/kb/en/installing-and-using-mariadb-via-docker/
- **Docker commands:**
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|`docker restart <container's name>`|Start the container named db |
|`docker stop <container's name>`|Stop the container named db |
|`docker exec -it <container's name> bash`|start an interactive bash shell inside a running Docker container named db|

### b. Using MariaDB
- **User**:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|`DROP USER IF EXISTS 'maria'@'localhost';`|Delete user 'maria' if it exists. Should to delete before create a new one|
|`CREATE USER 'maria'@'localhost' IDENTIFIED BY 'P@ssw0rd';`|Create user with name and password |
|`GRANT ALL PRIVILEGES ON *.* TO 'maria'@'localhost' WITH GRANT OPTION;`|Grant user permissions|
|`FLUSH PRIVILEGES;`|Reload the privilege tables in memory. Important to ensures that any changes made to user accounts or permissions take immediate effect without needing to restart the database server.|
|`SHOW GRANTS FOR 'dbadm'@'localhost';`|Show the user permissions|
|`select user();`|show the user that we used|
|`mysql -u maria -p`|Connect to the database with the user maria|


- **Database**:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|`DROP DATABASE IF EXISTS skolan;`|Delete database named 'skolan' if it exists.|
|`DROP DATABASE skolan;`|Delete database named 'skolan'. An error message will be shown if the database does not exist|
|`CREATE DATABASE IF NOT EXISTS skolan;`|Create a databse named 'skolan' if it does not exist|
|`CREATE DATABASE skolan;`|Create a databse named 'skolan'. An error message will be shown if the database exists|
|`SHOW DATABASES;`|Show all databases|
|`SHOW DATABASES LIKE "%skolan%";`|show all databases with name that contain 'skolan'|

- **Reset database**: You must be prepared for data loss due to accidental deletion, lost device, change of device, etc., no one can predict. To do this:
  - You first need to save all your code in different files.
  - Create a reset file, for example: reset-part-1.sql.
  - Connect to the database via user (if you lose the user, create a new one from root).
  - Enter the command: source [file name]; . Ten ten. You have your data back. Congrats!
   
- **Table**:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|`DROP TABLE IF EXISTS larare;`|Delete table named 'larare' if it exists.|
|`CREATE TABLE larare(akronym CHAR(3),avdelning CHAR(4),fornamn VARCHAR(20),efternamn VARCHAR(20),kon CHAR(1),lon INT,fodd DATE,PRIMARY KEY (akronym));`|Creat a table with primary key (unique) is 'akronym'|
|show tables;|show all tables in database|
|`SELECT * FROM larare;`|Show all the tables contents|
|`ALTER TABLE larare ADD COLUMN kompetens INT;`|add a new column in the exist table named kompetens with the data type INT (integer).|
|`ALTER TABLE larare DROP COLUMN kompetens;`|delete column named kompentens in the exist table|
|`ALTER TABLE larare ADD COLUMN kompetens INT DEFAULT 1 NOT NULL;`|in the exist table, add a new column named kompetens with the data type INT (integer). Sets the default value of the column to 1. If a new row is inserted into the table without explicitly providing a value for kompetens, the database will automatically assign the value 1. Ensures that the column cannot contain NULL values. Every row must have a valid integer value for the kompetens column.|
|`DELETE FROM larare **WHER**E fornamn = 'Hagrid';`|delete rows from the larare table where the value in the fornamn column matches 'Hagrid'|
|`DELETE FROM larare **WHERE** lon != 'NULL' **LIMIT** 2;`|delete rows from the larare table where the lon column does not have a NULL value, with a limit of 2 rows being deleted|
|`delete from larare;`|delete all rows from the larare table, but it will not remove the table itself|
|`select * from larare where fornamn like'%o%';`|show all columns from the larare table, filters the rows where the first name contents 'o'|
|`select fornamn, efternamn, lon FROM larare ORDER BY efternamn DESC;`|show the first name, last name and salary from table larare orders the results by the efternamn (last name) column in descending order|
|`update larare set lon = lon + 4000 where fornamn = 'Minerva';`|update table larare so that increases the salary information by 4000 for the row that the forst name is 'Minerva'|
|`SELECT SUM(lon) FROM larare;`|show sum of column "lon" in table "larare"|
|`select max(lon) from larare;`|show the max valude in column "lon" in table "larare"|
|`select min(lon) from larare;`|show the min valude in column "lon" in table "larare"|
|`SELECT AVG(kompetens) FROM larare;`|count and show the average valule in column "kompetens" from table "larare"|
|`SELECT avdelning, kompetens, SUM(lon) as Summa FROM larare GROUP BY avdelning, kompetens ORDER BY Summa DESC;`|show the table with columns: avdelning, kompetens, Summa (the sum of column "lon") from table "larare", grouped by department (avdelning) and skill (kompetens), and sorts the results in descending order based on total salary (Summa)|
|`SELECT avdelning,ROUND(AVG(lon)) AS Snittlon,COUNT(lon) AS Antal FROM larare GROUP BY avdelning HAVING Snittlon > 35000 ORDER BY Snittlon DESC;`|average salaries and the number of employees per department, filtering departments where the average salary is greater than 35,000, and sorts the results in descending order by average salary|
|`SELECT CONCAT(fornamn, ' ', efternamn, ' (', LOWER (avdelning), ')') AS NamnAvdelning FROM larare LIMIT 3;`|formats and retrieves names of employees (teachers) from the larare table, ensuring that department names are displayed in lowercase. The query also limits the output to 3 rows.|
|`SELECT fornamn, fodd, CURDATE() AS `Dagens datum`,CURTIME() AS `Klockslag` FROM larare;`|retrieves the first name (fornamn) and birth year (fodd) of individuals from the larare table, along with the current date and time|
|`SELECT fornamn, fodd FROM larare WHERE YEAR(fodd) < 1950 AND YEAR(fodd) > 1939;`|Show the teachers borns in the 40s|
|`CREATE VIEW v_namn_alder AS SELECT CONCAT(fornamn, ' ', efternamn, ' (', LOWER(avdelning), ')') AS namn TIMESTAMPDIFF(YEAR, fodd, CURDATE()) AS alder FROM larare; SELECT * FROM v_namn_alder;`|create and use a view named v_namn_alder, which formats names and calculates ages for individuals in the larare table. After creating the view, the second query retrieves all data from it|

**- SQL Query Execution Order**:
When a SQL query is executed, the clauses are processed in a specific sequence, often different from their written order. The logical execution order is as follows:
```
FROM: Identifies the source tables.
WHERE: Filters rows before grouping.
GROUP BY: Groups the filtered rows based on specified columns.
HAVING: Filters the groups created by GROUP BY based on aggregated values.
SELECT: Specifies the output columns.
ORDER BY: Sorts the final result.
```

==========//==========//==========//==========//==========//==========//==========

## 3. Node.js:
### a. Install:
https://nodejs.org/en/download
### b. Using node.js:
- **Docker command**:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|`docker start node, docker exec -it node sh`|run node|
|`node`|Use node|
|`docker run -it --name node -v "/Users/chuhathanh/Workspaces/Thanhs Workspaces/databas/:/database" --entrypoint sh node:22-alpine`|Create and mount the container 'node' with a folder|

==========//==========//==========//==========//==========//==========//==========

## 4. JavaScript:
### a. Dealing with events:
- JavaScript runs on a single thread and uses the event loop to handle asynchronous operations. The program executes synchronous lines of code first, while asynchronous operations (such as reading files, calling APIs) are processed after the Stack is empty. Since the program does not wait for asynchronous operations to complete, if the appropriate mechanism is not used, the results may not be processed properly.
- Therefore, people use callbacks to get the results of code that requires longer processing time than other lines of code. However, this leads to problems when there are too many callbacks nested within each other and leads to callback hell, which is difficult to read, difficult to understand, difficult to maintain, and prone to errors.
- Promises help:
    - Reduce callback hell by chaining asynchronous operations with .then() instead of nesting callbacks.
    - This makes the code cleaner and easier to maintain.
    - Promises also help handle errors better with .catch() instead of having to check each callback for errors. 
- While Promises make code easier to read, errors that occur in the .then() chain need to be .catch(), and if not handled properly, errors can be missed or difficult to trace. That's where async/await comes in:
    - async/await makes code easier to read, looks synchronous, but is actually asynchronous.
    - Easier to handle errors with try...catch instead of .catch().
    - Easier to debug, since errors appear directly as in synchronous code.
- In short, async/await is the best solution in most cases, but Promises are still useful when handling multiple tasks in parallel (Promise.all()).
- async/await is a tool used to work with asynchronous tasks, such as database queries, HTTP requests, or file reading/writing. It helps you process the results of asynchronous tasks in a synchronous way, avoiding the program being "blocked" while waiting for those tasks to complete.

### b. JavaScript syntax:
- One popular code standard is the JavaScript Standard Style: https:://standardjs.com/.

### c. Commands:
| Commands | Description |
| ----------------------------------------- | ------------------------------------------------- |
| `"use strict";` | Ensures that the code is interpreted in strict mode. |
| `module.exports = Dice;` | Specifies which part of the module should be exported. |
| `let Dice = require("./dice.js");` | Imports the `Dice` module in Node.js. |
| `console.log();` | Outputs messages to the console. |
| `const d = new Date();` | Creates a new Date object. |
| `let day = d.getDate();` | Retrieves the current day of the month. |
| `console.info("The date today is: " + day);` | Logs the current date to the console. |
    
==========//==========//==========//==========//==========//==========//==========

## 5. JavaScript connect to MySQL:
### a. Install:
- https://npmjs.com/package/mysql
- https://npmjs.com/package/promise-mysql
- https://www.npmjs.com/package/cli-table3
  
### b. Using:
|     Commands     |     Description     |
| ----------------------------------------- | ------------------------------------------------- |
|     `npm init`     | Create a `package.json` file |
|     `npm install mysql promise-mysql`     |install two packages via npm: mysql (This is the official MySQL client library for Node.js, allowing you to connect to and interact with a MySQL database.) and promise-mysql (This is a wrapper around the mysql package that provides a Promise-based API, making it easier to work with asynchronous operations using async/await.)|

- **Var, let and const**:
    - ✅ Use const if the value does not need to change.
    - ✅ Use let if the value can change within the scope of {}.
    - ❌ Avoid using var because the scope is unsafe and prone to errors.

- **Math**:
  
|     Commands     |     Description     |
| ----------------------------------------- | ------------------------------------------------- |
|     `Math.random()`     | Always returns a float number lower than 1 |
|     `Math.random() * (max-min) + min`     |Returns a float number lower than (max - min) and more than and equal min|
|     `Math.round()`     | Round the result|
|     `Math.floor(Math.random() * max`     | Returns a random integer from 0 to max|
|     `Math.floor(Math.random() * max) + 1`     | Returns a random integer from 1 to max|

- **Print output to console**:

|     Commands     |     Description     |
| ----------------------------------------- | ------------------------------------------------- |
|     `console.info();`     |The same as console.log(), but semanticcally meant for info. May have an "info" label or different styling in some browsers.|
|     `console.log()`     |Usually use for general debugging and printing variables|

    - Example of print output to console:
    ```
    message = `I'm thinking of number ${thinking}.\n`
        + `Youre guess is ${guess}.\n`
        + `You guessed right? `
        + (thinking === guess);
    console.info(message);
    ```
- **Class and module**:
    - Class:
        - Uses constructor to initialize objects.
        - Supports inheritance using extends.
        - Uses super to call parent class methods.
        - Private methods (#method()) introduced in ES2020.
    - Module:
        - Uses export to make functions, variables, or classes available for import.
        - Uses import to bring in exported data from other modules.
        - Supports both named exports and default exports.
        - Helps in organizing code efficiently across multiple files.
    - When to Use Class vs. Module?

        |     Requirement       |     Use Class     |     Use Module     |
        | --------------------- | ------------------|--------------------|
        |Need objects with properties and methods	|✅	|❌|
        |Need inheritance from a parent class	|✅|	❌|
        |Need to split code into multiple files	|❌|	✅|
        |Need to avoid variable name conflicts	|❌|	✅|
        |Need object-oriented programming (OOP)	|✅	|❌|

### c. Examples about javascript and javascript connect to MySQL
- Example 1: 
```
/**
 * Main function.
 *
 * @async
 * @returns void
 */
```
    - The comment provides documentation for the function, explaining that it's the main function of the program, that it's asynchronous (async), and that it doesn't return any value (void). 
    - It is mainly for human readers and tools that generate documentation from code comments.
    - This type of documentation is helpful for maintaining and understanding the code, especially when it's part of a larger project or when the code is being worked on by multiple developers.

- Example 2:
```
for (const row of res) {
        str += "| ";
        str += row.akronym.padEnd(10);
        str += "| ";
        str += (row.fornamn + " " + row.efternamn).padEnd(20);
        str += "| ";
        str += row.avdelning.padEnd(10);
        str += "| ";
        str += row.lon.toString().padStart(8);
        str += " |\n";
```
    - In the code you provided, the numbers 10, 20, and 8 are used as arguments to the padEnd() and padStart() methods, which control how strings are padded to a certain length. 
    - These methods help format the output by ensuring that the strings have consistent lengths when displayed. 

- Example 3: Module for read data from the keyboard
```
// Read from commandline
const readline = require("readline"); //imports the buit-in Node.js module `readline, which allows interaction with the command line
const rl = readline.createInterface({ //creates an instance of the `readline`interface, enabling reading from and writing to the terminal
    input: process.stdin,            //reads input from the keyboard
    output: process.stdout          //writes output to the console
});

// Promisify rl.question to question
const util = require("util");

rl.question[util.promisify.custom] = (arg) => { //takes an argument (the question string) and returns a Promise
    return new Promise((resolve) => {
        rl.question(arg, resolve);    //calls the original `rl.question`and resolves the answer using the provided callback. Allows ´rl.question`to be used asynchoronously with await
    });
};

const question = util.promisify(rl.question); //converts `rl.question` into a Promise-based function

module.exports = { question }; //export the question module.
```

==========//==========//==========//==========//==========//==========//==========

## 6. ER Modeling:
### a. Database Modeling - Phases and Steps:
- Three phases: Conceptual modeling, logical modeling, physical modeling.
- Ten steps:
  - _Conceptual_:
      - 1.Describe the database in text: Update it if there are errors.
      - 2.Identify entities: Highlight key entities in the text.
      - 3.Create a relationship matrix: List all relationships and represent them in a matrix to better define their connections.
      - 4.Draw a simplified ER diagram: Include entities and relationships.
      - 5.Add cardinality: For example, "one movie can have many actors."
      - 6.Define attributes and candidate keys: Answer the question, "What makes a movie unique?" (e.g., movie ID).
  - _Logical_:
      - 7.Convert to a relational model: Break down many-to-many relationships.
      - 8.Define primary and foreign keys: Adjust the diagram by introducing primary keys (PK) and foreign keys (FK) along with additional attributes.
  - _Physical_:
      - 9.Create SQL DDL for tables.
      - 10.List the functions the database should support (API).
Diagrams can be created using different tools like paper, draw.io, or Dia Diagram Editor—choose the one that fits best.
Many-to-many relationships must be broken down into separate tables (e.g., a movie with three actors results in three rows).
Document everything as clearly as possible.

### b. Conceptual Modeling:
- **ER Modeling**:
    - Entities as boxes: Represent objects in the database using **rectangles**.
    - Relationships: Depict connections between entities. Answer key questions: What is the nature of the relationship? (e.g., a person and a house can have relationships like "lives in" or "owns").
What is the cardinality? (e.g., 1-1 means one-to-one, N-M means many-to-many, and N-1 means a person can live in one house, but a house can have multiple residents). Relationships are represented as **diamonds between rectangles.**
    - Total participation: If every entity instance must have a relationship, use **double lines istället för single line to connect the entity to the relationship**.
    - Attributes: Represented as **ovals connected to the corresponding entities**.
    - Unique attributes (candidate keys) **are underlined**.
    - Attributes on relationships: If a relationship has an attribute, it is drawn as **an oval connected to the diamond**. Example: A person lives in a house and has a "move-in year" attribute—this belongs to the "lives in" relationship.
    - Self-referencing relationships: If entities relate to themselves (e.g., people can be friends with other people), represent it with **a diamond above the entity with two connections to itself**.
    - Composite attributes: If an attribute consists of multiple sub-attributes (e.g., a phone number can have a country code and a local number), draw it as **an oval (country code, local number) connected to another oval (phone number)**.
    - Multivalued attributes: If an entity can have multiple values for an attribute (e.g., a person can have multiple phone numbers), represent it with **a double oval**.
    - Derived attributes: Values that are not stored but computed when needed (e.g., age derived from birthdate) are drawn as **an oval with dashed lines**.
    - Weak entity types: Example: An apartment can contain multiple rooms. Room names (e.g., "kitchen," "living room") are not globally unique, but combining them with the apartment number makes them unique.
Indicate weak entities by underlining the apartment number and using **dashed lines for the room name.**
- **Transforming relationships into entities**:
    - Some relationships can be turned into entities.
    - Example: Instead of a many-to-many "watched" relationship between "person" and "movie," introduce a "viewing" entity. This allows tracking details like how many times a person has watched a movie. **Use a rectangle instead of a diamond** to represent the new entity.
- **Extended ER Diagrams**: Subclasses and inheritance: Entities can be specialized into subclasses (e.g., a "person" can be a "student," "teacher," or "astronaut").
- Once the conceptual model is complete, it needs to be translated into the relational model.

  
