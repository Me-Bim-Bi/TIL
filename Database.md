# Database

## Content:
1. SQLite:
2. MariaDB:
3. Node.js:
4. JavaScript:
5. JavaScript connect to MySQL:


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
### b. Using:
| Commands | Description |
| ----------------------------------------- | ------------------------------------------------- |
| `npm init` | Create a `package.json` file |
| `npm install mysql promise-mysql` |install two packages via npm: mysql (This is the official MySQL client library for Node.js, allowing you to connect to and interact with a MySQL database.) and promise-mysql (This is a wrapper around the mysql package that provides a Promise-based API, making it easier to work with asynchronous operations using async/await.)|
| `npm install cli-table3` | install an NPM package that helps format tabular data in a structured way for displaying in the terminal |

### c. Examples about javascript connect to MySQL
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
