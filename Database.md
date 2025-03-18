# DATABASE

## Content:
1. SQLite:
2. MariaDB:
3. Database transaction

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

- _Should use this way to create an user:_ to be not affected by the ip adress that we use in container or not
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|`DROP USER IF EXISTS 'maria'@'localhost'; DROP USER IF EXISTS 'maria'@'%';`|Delete user 'maria' if it exists. Should to delete before create a new one|
|`CREATE USER 'maria'@'%' IDENTIFIED BY 'P@ssw0rd';`|Create user with name and password |
|`GRANT ALL PRIVILEGES ON *.* TO 'maria'@'%' WITH GRANT OPTION;`|Grant user permissions|

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
  - Enter the command: source [file name]; . Ten ten. You have your data back. Congrats!
   
- **Table**:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|`DROP TABLE IF EXISTS larare;`|Delete table named 'larare' if it exists.|
|`CREATE TABLE larare(akronym CHAR(3),avdelning CHAR(4),fornamn VARCHAR(20),efternamn VARCHAR(20),kon CHAR(1),lon INT,fodd DATE,PRIMARY KEY (akronym));`|Creat a table with primary key (unique) is 'akronym'|
|`SHOW CREATE TABLE <table_name>;`|show how a table is created|
|`SHOW CREATE TABLE <table_name> \G;`|show how a table is created line by line|
|`show tables;`|show all tables in database|
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

- **Inside a table**:
    - Can use `AUTO_INCREMENT` to automatically generate a unique value for a column when a new record is inserted into a table.
    - `FOREIGN KEY (kurskod) REFERENCES kurs(kod)`to link kurskor i kurstillfalle table med kod i kurs table. If you want to delete a table, you have to start dropping the one that doesn't have any other table linked to it. In this case, we need to drop kurstillfallet table forst, then kurs table.

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
- **Join the tables**:
```
SELECT
    CONCAT(k.namn, ' (', k.kod,')') AS Kursnamn,
    CONCAT(a.fornamn, ' ', a.efternamn, ' (', a.akronym, ')') AS Larare,
    a.alder AS Alder
FROM v_larare_alsta AS                  //Use the 'v_larare_alsta' table and alias it as 'a'
    JOIN kurstillfalle AS kt            //join with the kurstillfalle table
        ON a.akronym = kt.kursansvarig  //match rows based on the 'akronym' field in 'a' and 'kursansvarig' field in 'kt'
    JOIN kurs AS k
        ON k.kod = kt.kurskod
ORDER BY alder DESC, k.namn ASC
;
```
- The different between JOIN, OUTER JOIN, LEFT/RIGHT OUTER JOIN
  
|       JOIN Type       |       Includes Non-Matching Rows?         |       From Which Table?       |
| --------------------- | ----------------------------------------- | ----------------------------- |
| `JOIN / INNER JOIN`   | ❌ No                                     | Only matching rows. If there is no mathch, the row is not shown|
| `LEFT OUTER JOIN`     | ✅ Yes                                    | All from the left table. Show NULL if there is no connection. For example: the teachers who are not in charge of any course => show "NULL" in column "Kurskod" for those teachers |
| `RIGHT OUTER JOIN`    | ✅ Yes                                    | All from the right table. Show NULL if there is no connection. For example: the teachers who are not in charge of any course => show "NULL" in column "Kurskod" for those teachers|
| `OUTER JOIN`          | ✅ Yes                                    | All from the table, even if there is no matching row in the other table |

- **LOAD DATA INFILE**:
```
LOAD DATA LOCAL INFILE 'kurs.csv'   //load data from file named kurs.csv
INTO TABLE kurs                     //to the table named kurs
CHARSET utf8                        //specifies the character encoding used in the file. In this case, it's utf8
FIELDS                              //This defines how the fields (columns) in the CSV file are separated and how the fields enclosed by. 
    TERMINATED BY ','               //In this case, the fields are separated by commas (',')
    ENCLOSED BY '"'                 //In this case, the fields are enclosed by double quotes (")
LINES                               //This defines how rows in the CSV file are separated.
    TERMINATED BY '\n'              //In this case, rows are separated by newline characters ('\n')
IGNORE 1 LINES                      //This tells MySQL to skip the first line of the CSV file, typically because it contains column headers rather than data
;
```
```
LOAD DATA LOCAL INFILE 'kurstillfalle.csv'
INTO TABLE kurstillfalle
CHARSET utf8
FIELDS
    TERMINATED BY ','
    ENCLOSED BY '"'
LINES
    TERMINATED BY '\n'
IGNORE 1 LINES
    (kurskod, kursansvarig, lasperiod);`//Ignore column id
;
```

- **UNION:**

```
SELECT
    *
FROM kurstillfalle
WHERE               //find and show all information in table kurstillfalle that kursanvarig match with the teachers that work for "DIDD" apartment
    kursansvarig IN (
        SELECT
            akronym
        FROM larare
        WHERE
            avdelning = 'DIDD'
    )
;
```

- **UNION:**

```
(
    SELECT akronym, avdelning FROM larare WHERE avdelning = 'DIDD'
)
UNION //Show akronym, avdelning from table larare that have apartment named "DIDD" and "DIPT". The result start with "DIDD", then "DIPT"
(
    SELECT akronym, avdelning FROM larare WHERE avdelning = 'DIPT'
)
;
```

- Back-up the database: use mariadb-dump or mysqldump
  
|Commands                                 | To do                                                |
| --------------------------------------- | ---------------------------------------------------- |
|`which mariadb`|Check where the command located |
|`which mysqldump`|Check where the command located|
|`mysqldump -u maria -p skolan`|create a back-up of the database named skolan|
|`mysqldump -u maria -p --result-file=skolan.sql skolan`|save the back-up commands to the file named skolan.sql|
|`use skolan1`, `source skolan.sql`|back-up everything to the database named skolan1|

==========//==========//==========//==========//==========//==========//==========

## 3. Database transaction: all or nothing
### a. Storage Engines
CSV, Archive, Blackhole: these storage engines handle data differently. For example, Blackhole functions like /dev/null—anything inserted into it disappears.

### b. Transactions: 
- A transaction in SQL is a sequence of operations that depend on each other. If any part of the transaction fails, the entire transaction can be rolled back to maintain consistency. This ensures that the system either applies all changes or none, preventing partial updates that could cause inconsistencies.
    - START TRANSACTION or BEGIN: Initiates a new transaction.
    - COMMIT: Finalizes the transaction, making changes permanent.
    - ROLLBACK: Cancels the transaction, undoing all changes made within it.
    - SET autocommit: Enables or disables automatic commitment of each individual SQL statement.

### c. ACID Properties
- ACID is a set of properties ensuring reliable database transactions:
    - A (Atomicity): A transaction must be all or nothing—it is executed as a single unit. If one part fails, the entire transaction is rolled back.
    - C (Consistency): The transaction moves the database from one valid state to another, ensuring constraints, cascades, and triggers remain valid.
    - I (Isolation): Transactions execute independently, meaning one transaction cannot see the partial results of another ongoing transaction.
    - D (Durability): Once committed, a transaction's changes persist even in the event of a system crash.

### d. Transaction Log
- A transaction log records all changes before applying them (write-ahead logging). It logs:
    - The transaction type
    - Affected database objects
    - Previous and new values
    - Undo/redo information

### e. Transaction Access Mode
- Transaction_characteristic: Defines how the system handles transactions.

### f. Isolation Levels
- Isolation levels balance performance and data consistency when multiple transactions interact simultaneously:
    - READ UNCOMMITTED: Transactions can read uncommitted changes made by other transactions (lowest isolation, high risk of dirty reads).
    - READ COMMITTED: Transactions only see committed changes.
    - REPEATABLE READ: Ensures consistent reads within a transaction.
    - SERIALIZABLE: The strictest level—transactions are executed sequentially to ensure complete isolation.

### g. Read Phenomena
- Dirty Reads: Reading data that has been modified but not committed.
- Non-Repeatable Reads: A transaction reads the same row twice but gets different results due to another transaction's changes.
- Phantom Reads: A query returns different results when executed multiple times due to new rows being inserted or deleted by other transactions.

### h. Locking & Deadlocks
- Locking: Ensures data integrity by preventing multiple transactions from modifying the same data simultaneously.
- Deadlocks: Occur when transactions wait indefinitely for each other to release locks, preventing further progress. Proper transaction management helps avoid deadlocks.

### i. Transactions in MySQL (npm mysql)
- Best practices for handling transactions in Node.js with MySQL: Enable multiple queries: `multipleStatements: true`
- Use helper functions for START TRANSACTION, COMMIT, and ROLLBACK to manage transactions efficiently.
<<<<<<< HEAD

==========//==========//==========//==========//==========//==========//==========

## 4. Procedure and trigger
### a. A CRUD-based web client with an HTML form that allows users to create new rows in the database, delete them, edit them, and view them.
C: create
R: read
U: update
D: delete

### b. Timestamps in the Database: Row Status
- Implement timestamps when creating the table. 
```
DROP TABLE IF EXISTS t1;

CREATE TABLE t1 (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    value CHAR(2),
    created TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- Records when a row is created
    updated TIMESTAMP DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP, -- Records when a row is updated; if not updated, it remains NULL
    deleted TIMESTAMP DEFAULT NULL -- A soft delete mechanism: does not actually delete the row but marks it as hidden.
                                   -- Useful for keeping order history until the customer confirms the order or returns an item.
);
```

- Soft delete: Instead of permanently deleting a row, it is marked as deleted:
```
UPDATE t1 SET deleted = NOW() WHERE id = 3;
```

- Show rows that have been updated: `SELECT * FROM t1 WHERE updated IS NOT NULL;`
- Implement a "published" timestamp to control when a row should be considered published.
    - For example, a row can be scheduled to be published next Saturday => The application logic can compare the current date with the scheduled publish date to determine whether the row should be displayed.


### c. Stored Procedure:
- Programming in the Database: Database programming involves more than just writing SQL queries; it includes various features like APIs, variables, stored procedures, triggers, and functions.
- Variables in SQL Scripts:

|      Feature       |       Global Variable         |       Advanced Variable (Session/User-Defined)       |
| ------------------ | ------------------------------| ---------------------------------------------------- |
| Scope   | Global (system-wide)                    | Limited to session/procedure|
| Persistence   | Remains after session ends        | Exists only during session/procedure|
| Usage   | System settings, configurations         | Temporary storage, dynamic queries|
| Example   | DB	MySQL, SQL Server               | MySQL, PostgreSQL, Oracle (PL/SQL)|
| Scope   | Global (system-wide)                    | Limited to session/procedure|

- Stored Procedure: a stored procedure is a small program or routine that can be called to execute database code, including SQL statements and common programming constructs such as variables, if-statements, loops, and more.

- Defined as a database object using CREATE, DROP, and ALTER.
    ```
    DROP PROCEDURE IF EXIXST small_proc;

    DELIMITER ;;

    CREATE PROCEDURE small_proc()
    BEGIN
        SELECT NOW() AS "Current time"; //Compound statements
    END
    ;;

    DELIMITER;
    ```
- Called using: `CALL small_proc();`
- Compound Statement Syntax in Stored Programs
- Stored procedures, triggers, and functions all use compound statements.
- Begins with BEGIN and ends with END, with programming code, variables, and SQL combined in between.
- Local variables: Exist within the scope of the compound statement.
- Avoid naming conflicts between local variables and column/table names (e.g., test_proc, p_balance).
- Common constructs inside compound statements:
    - LOOP, REPEAT/UNTIL, WHILE
    - CASE/WHEN/ELSE
    - LEAVE/RETURN
    - CURSOR/OPEN/FETCH/CLOSE
    - CONDITION/HANDLER/SIGNAL
- Why Use Stored Procedures?
    ✅ Handle complex logic within the database.
    ✅ Abstract database implementation behind an API.
    ✅ Enable unit testing of database operations.
    ✅ Ensure the right type of code is written by the right expertise.
    ✅ Maintain separation of concerns.
- Disadvantages of Stored Procedures
    ❌ Database-specific code.
    ❌ Compatibility issues across different database systems.
    ❌ Requires a proper development, testing, and debugging environment.
- Example: Build a procedure to transfer money between two accounts.
    
- Triggers are automatic database actions that execute when an INSERT, UPDATE, or DELETE operation occurs.
    - New row values: NEW.id, NEW.column
    - Old row values: OLD.id, OLD.column
        - Example: Create a procedure to transfer money between two accounts and track when changes occur.
        - Example: Logging Balance Updates with a Trigger
        ```
        CREATE TABLE account_log (
        id INTEGER PRIMARY KEY AUTO_INCREMENT,
        `when` TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        `what` VARCHAR(20),
        `account` CHAR(4),
        `balance` DECIMAL(10,2),
        `amount` DECIMAL(10,2)
        );

        INSERT INTO account_log (what, account, amount)
        VALUES
            ('move_money_from', from_account, -amount),
            ('move_money_to', to_account, +amount);

        DROP TRIGGER IF EXISTS log_balance_update;

        CREATE TRIGGER log_balance_update
        AFTER UPDATE
        ON account FOR EACH ROW
        INSERT INTO account_log (`what`, `account`, `balance`, `amount`)
        VALUES ('trigger', NEW.id, NEW.balance, NEW.balance - OLD.balance);
        ```
    

=======
