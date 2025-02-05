# Database

## 1. SQLite:
- User DB browser for SQLite
- **Basic commands:**
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT); | Create a table named test, if it was not exists in database with two elements: id and name.|
|DROP TABLE IF EXISTS test; | Drop a test table if it was exists in database |
|SELECT name FROM sqlite_master WHERE type = 'table' AND name='test';| Check the positions of table if it exists in database. Returns None if the table does not exist in the database |
|select * from burger b join order_burger ob on b.id = ob.burger_id join orders o on ob.order_id = o.id join items i on ob.items_id = i.id where o.id = ? |Join data in table burger with tabler order_burger, table items with table order_burger based on burger_id, order_id, items_id |
|INSERT INTO burger (id, name) VALUES (1, "cheese burger") | Insert a row in table burger with two elements: id = 1 and name = cheese burger|
|('SELECT id FROM items WHERE name = ? AND type = ? AND action = ?',(item_name, item_type, action)) | pull data of item_name, item_type, action based on items_id|
|('INSERT INTO order_burger (order_id, burger_id, items_id) VALUES (?, ?, ?)',(order_id, burger_id, item_id))|insert input data to database|
|with sqlite3.connect('orders.db') as conn:...|use this code to open database so that database will be closed outside "with"|

## 2. MariaDB:
### a. Installing and using MariaDB via Docker:
- **Install:** https://mariadb.com/kb/en/installing-and-using-mariadb-via-docker/
- **Docker commands:**
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|docker restart <container's name>|Start the container named db |
|docker stop <container's name>|Stop the container named db |
|docker exec -it <container's name> bash |start an interactive bash shell inside a running Docker container named db|

### b. Using MariaDB
- **User**:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|DROP USER IF EXISTS 'maria'@'localhost'; |Delete user 'maria' if it exists. Should to delete before create a new one|
|CREATE USER 'maria'@'localhost' IDENTIFIED BY 'P@ssw0rd'; |Create user with name and password |
|GRANT ALL PRIVILEGES ON *.* TO 'maria'@'localhost' WITH GRANT OPTION;|Grant user permissions|
|FLUSH PRIVILEGES;|Reload the privilege tables in memory. Important to ensures that any changes made to user accounts or permissions take immediate effect without needing to restart the database server.|
|SHOW GRANTS FOR 'dbadm'@'localhost';|Show the user permissions|
|select user();|show the user that we used|

- **Database**:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|DROP DATABASE IF EXISTS skolan; |Delete database named 'skolan' if it exists.|
|DROP DATABASE skolan;|Delete database named 'skolan'. An error message will be shown if the database does not exist|
|CREATE DATABASE IF NOT EXISTS skolan;|Create a databse named 'skolan' if it does not exist|
|CREATE DATABASE skolan;|Create a databse named 'skolan'. An error message will be shown if the database exists|
|SHOW DATABASES;|Show all databases|
|SHOW DATABASES LIKE "%skolan%";|show all databases with name that contain 'skolan'|

- **Table**:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|DROP TABLE IF EXISTS larare;|Delete table named 'larare' if it exists.|
|CREATE TABLE larare
(akronym CHAR(3),avdelning CHAR(4),fornamn VARCHAR(20),efternamn VARCHAR(20),kon CHAR(1),lon INT,fodd DATE,PRIMARY KEY (akronym));|Creat a table with primary key (unique) is 'akronym'|
|show tables;|show all tables in database|
|SELECT * FROM larare;|Show all the tables contents|
|ALTER TABLE larare ADD COLUMN kompetens INT;|add a new column in the exist table named kompetens with the data type INT (integer).|
|ALTER TABLE larare DROP COLUMN kompetens;<|delete column named kompentens in the exist table|
|ALTER TABLE larare ADD COLUMN kompetens INT DEFAULT 1 NOT NULL;|in the exist table, add a new column named kompetens with the data type INT (integer). Sets the default value of the column to 1. If a new row is inserted into the table without explicitly providing a value for kompetens, the database will automatically assign the value 1. Ensures that the column cannot contain NULL values. Every row must have a valid integer value for the kompetens column.|
|DELETE FROM larare WHERE fornamn = 'Hagrid';|delete rows from the larare table where the value in the fornamn column matches 'Hagrid'|
|DELETE FROM larare WHERE lon != 'NULL' LIMIT 2;|delete rows from the larare table where the lon column does not have a NULL value, with a limit of 2 rows being deleted|
|delete from larare;|delete all rows from the larare table, but it will not remove the table itself|
|select * from larare where fornamn like'%o%';|show all columns from the larare table, filters the rows where the first name contents 'o'|
|select fornamn, efternamn, lon FROM larare ORDER BY efternamn DESC;|show the first name, last name and salary from table larare orders the results by the efternamn (last name) column in descending order|
|update larare set lon = lon + 4000 where fornamn = 'Minerva';|update table larare so that increases the salary information by 4000 for the row that the forst name is 'Minerva'|

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
## 3. Node.js:
### a. Install:
https://nodejs.org/en/download
### b. Using node.js:
- **Docker command**:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|docker start node, docker exec -it node sh |run node|
|node|Use node|
|docker run -it --name node -v "/Users/chuhathanh/Workspaces/Thanhs Workspaces/databas/:/database" --entrypoint sh node:22-alpine|Create and mount the container 'node' with a folder|


