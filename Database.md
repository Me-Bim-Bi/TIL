# DATABASE

## Content:
1. SQLite
2. MariaDB
3. Database transaction
4. Procedure and trigger 
5. Function
6. Index
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
    - `amount NUMERIC(4, 2)` type numeric: invole 4 number with two number after     

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

    - CONCAT and GROUP CONCAT:
    `SELECT CONCAT('Hello', ' ', 'World');``=> `Hello World``
    `SELECT GROUP_CONCAT(name SEPARATOR ', ') FROM employees;``=> `John, Alice, Bob, Charlie`

1. CONCAT():
The CONCAT() function in SQL combines multiple strings into a single string. It does not handle multiple rows, just combines values from a single row.

Example:
Suppose we have a table like this:

id	name	category
1	Item A	Category 1
2	Item B	Category 1
3	Item C	Category 2
sql
Copy
Edit
SELECT CONCAT(name, ' - ', category) AS result
FROM items;
Result:
result
Item A - Category 1
Item B - Category 1
Item C - Category 2
Here, CONCAT() simply combines the name and category columns for each row into a new string.

2. GROUP_CONCAT():
The GROUP_CONCAT() function is used to concatenate values from multiple rows into a single string, with an optional separator. It is generally used with GROUP BY to combine values within a group.

Example:
Now, suppose we want to concatenate the name values for all items in Category 1:

sql
Copy
Edit
SELECT category, GROUP_CONCAT(name ORDER BY name ASC) AS concatenated_names
FROM items
GROUP BY category;
Result:
category	concatenated_names
Category 1	Item A, Item B
Category 2	Item C
GROUP_CONCAT() concatenates the name values for each category into one string.

The result for Category 1 is Item A, Item B because these two items belong to that category.

3. GROUP_CONCAT(DISTINCT CONCAT(...)):
The combination of GROUP_CONCAT() with DISTINCT inside a CONCAT() function allows you to concatenate unique values. In other words, if there are duplicate values in the rows, DISTINCT ensures that only unique values are included in the concatenated result.

Example:
Let’s consider we have a table with duplicates:

id	name	category
1	Item A	Category 1
2	Item B	Category 1
3	Item A	Category 1
4	Item C	Category 2
Now, let’s use GROUP_CONCAT(DISTINCT CONCAT(...)):

sql
Copy
Edit
SELECT category, GROUP_CONCAT(DISTINCT CONCAT(name, ' (', id, ')') ORDER BY name ASC) AS unique_names
FROM items
GROUP BY category;
Result:
category	unique_names
Category 1	Item A (1), Item B (2)
Category 2	Item C (4)
DISTINCT ensures that only unique name values are included in the result.

For Category 1, even though Item A appears twice, it is only included once in the result, giving Item A (1) and Item B (2).

How Each Works:
CONCAT():

Works for combining strings from a single row.

Example: "Item A - Category 1".

GROUP_CONCAT():

Combines values from multiple rows into a single string.

Example: "Item A, Item B" for multiple items in the same group.

GROUP_CONCAT(DISTINCT CONCAT(...)):

Combines values from multiple rows while ensuring uniqueness of the concatenated values.

Example: "Item A (1), Item B (2)" for unique items in a group.

Use Cases:
CONCAT(): When you want to combine multiple columns into a single column for one row.

GROUP_CONCAT(): When you want to list values from multiple rows into a single string (e.g., all items in a category).

GROUP_CONCAT(DISTINCT CONCAT(...)): When you want to list only unique values from multiple rows, and you're concatenating multiple pieces of information into a string.

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

JOIN Type	Kết quả
INNER JOIN	Chỉ lấy dữ liệu có kết quả khớp ở cả hai bảng.
LEFT JOIN	Lấy toàn bộ dữ liệu từ bảng trái, nếu không có khớp, bảng phải là NULL.
RIGHT JOIN	Lấy toàn bộ dữ liệu từ bảng phải, nếu không có khớp, bảng trái là NULL.
FULL OUTER JOIN	Lấy tất cả dữ liệu từ cả hai bảng, nếu không có khớp, giá trị sẽ là NULL.

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
|`mysqldump -u maria -p --routines --result-file=eshop.sql eshop`|back-up with procedures and functions|




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

==========//==========//==========//==========//==========//==========//==========

## 4. Procedure and trigger
### a. A CRUD-based web client with an HTML form that allows users to create new rows in the database, delete them, edit them, and view them.
- Install body-parser to extract the data that comes in the posted form `npm install body-parser --save`
- C: create.
    - Example about create an acount
    ```
    in view/.ejs file: use method post to receive the data that comes in the posted form.

    <form class="label-left" method="post">
        <fieldset>
            <legend>Create account</legend>

            <label for="id">Id</label>
            <input id="id" type="text" name="id">

            <label for="name">Name</label>
            <input id="name" type="text" name="name">

            <label for="balance">Balance</label>
            <input id="balance" type="number" name="balance">

            <input type="submit" name="doit" value="Create">
        </fieldset>
    </form>

    in router/.js file: use the body-parser to extract the data that comes in the posted form
    const bodyParser = require("body-parser");
    const urlencodedParser = bodyParser.urlencoded({ extended: false });
    router.post("/create", urlencodedParser, async (req, res) => {
        await bank.createAccount(req.body.id, req.body.name, req.body.balance);
        res.redirect("/bank/balance");
    });

    in sql/bank/.sql form: create a procedure to create an account in database
    --
    -- Create procedure for insert into account
    --
    DROP PROCEDURE IF EXISTS create_account;
    DELIMITER ;;
    CREATE PROCEDURE create_account(
        a_id CHAR(4),
        a_name VARCHAR(8),
        a_balance DECIMAL(4, 2)
    )
    BEGIN
        INSERT INTO account VALUES (a_id, a_name, a_balance);
    END
    ;;
    DELIMITER ;


    in src/bank.js file: call the procedure to create an account in database        
    /**
    * Create a new account.
    *
    * @async
    * @param {string} id      A id of the account.
    * @param {string} name    The name of the account holder.
    * @param {string} balance Initial amount in the account.
    *
    * @returns {void}
    */
    async function createAccount(id, name, balance) {
        let sql = `CALL create_account(?, ?, ?);`;
        let res;

        res = await db.query(sql, [id, name, balance]);
        console.log(res);
        console.info(`SQL: ${sql} got ${res.length} rows.`);
    }
    ```
- R: read
    - Example about show the acount when we type the account number on the link, like: bank/account/1111 show information of Adam's account.
    ```
    in route/.js file:
    router.get("/account/:id", async (req, res) => {
    let id = req.params.id;
    let data = {
        title: `Account ${id} ${sitename}`,
        account: id
    };

    data.res = await bank.showAccount(id);

    res.render("bank/account-view", data);
    });
    
    in src/bank.js file:
    **
    * Show details for an account.
    *
    * @async
    * @param {string} id A id of the account.
    *
    * @returns {RowDataPacket} Resultset from the query.
    */
    async function showAccount(id) {
        let sql = `CALL show_account(?);`;
        let res;

        res = await db.query(sql, [id]);
        //console.log(res);
        console.info(`SQL: ${sql} got ${res.length} rows.`);

        return res[0];
    }

    in view/.js file:
    <td><a href="/bank/account/<%= row.id %>"><%= row.id %></a></td>
    ```
- U: update
    - Update account: 
        - Create route, use `req.params.id`, render to the .ejs file `res.render("Bank/account-edit", data);`
        - Create procedure edit_account in .sql file
        - Create funtion editAccound in src/.js file to call the procedure edit_account
        - Create .ejs file, note about `readonly value` to avoid the user can edit this value.
    
- D: delete
- Always use POST when we update the database. If we had use GET for updates, it would have exposed a security risk. Only use get to retrieve data, use post to edit data after retrieving the data.
```
router.get("/delete/:id", async (req, res) => {
    let id = req.params.id;
    let data = {
        title: `Delete account ${id} ${sitename}`,
        account: id
    };

    data.res = await bank.showAccount(id);

    res.render("bank/account-delete", data);
});

router.post("/delete", urlencodedParser, async (req, res) => {
    //console.log(JSON.stringify(req.body, null, 4));
    await bank.deleteAccount(req.body.id);
    res.redirect(`/bank/balance`);
});
```
|       Method       |        When to use        |      Example Routes       |
| --------------------- | ----------------------------------------- | ----------------------------- |
| `GET`   | Retrieve or display data                                   | `/balance`, `/acount/:id`, `/edit/:id`|
| `POST`   | Modify, create or delete data                                  | `/create`, `/edit`, `/delete`|


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

    DELIMITER ;; //change delimiter of SQL to ";;" to make a diferent with the normal SQL

    CREATE PROCEDURE small_proc()
    BEGIN
        SELECT NOW() AS "Current time"; //Compound statements
    END
    ;; 

    DELIMITER; //change delimiter of SQL to ";" 
    ```
- Called using CALL. Example: `CALL small_proc();`
- Show procedue using: `SHOW PROCEDURE STATUS LIKE '%money';` => show status of all procedures that ends with "money"
- Show how a procedure was created: `SHOW CREATE PROCEDURE move_money \G;`
- Compound Statement Syntax in Stored Programs
- Stored procedures, triggers, and functions all use compound statements.
- Begins with BEGIN and ends with END, with programming code, variables, and SQL combined in between.
- Avoid naming conflicts between local variables and column/table names (e.g., test_proc, p_balance).
- Common constructs inside compound statements:
    - LOOP, REPEAT/UNTIL, WHILE
    - CASE/WHEN/ELSE
    - LEAVE/RETURN
    - CURSOR/OPEN/FETCH/CLOSE
    - CONDITION/HANDLER/SIGNAL
- Why Use Stored Procedures?
    - ✅ Handle complex logic within the database.
    - ✅ Abstract database implementation behind an API.
    - ✅ Enable unit testing of database operations.
    - ✅ Ensure the right type of code is written by the right expertise.
    - ✅ Maintain separation of concerns.
- Disadvantages of Stored Procedures
    - ❌ Database-specific code.
    - ❌ Compatibility issues across different database systems.
    - ❌ Requires a proper development, testing, and debugging environment.
- Example: Build a procedure to transfer money between two accounts.

```
DROP PROCEDURE IF EXISTS move_money;

DELIMITER ;;

CREATE PROCEDURE move_money(
    from_account CHAR(4),
    to_account CHAR(4),
    amount NUMERIC(4, 2)
)

BEGIN

    DECLARE current_balance NUMERIC(4, 2);

    START TRANSACTION;

    -- Get the current balance of the sender
    SELECT balance INTO current_balance FROM account WHERE id = from_account;

    IF current_balance - amount < 0 THEN
        ROLLBACK;
        SELECT 'Amount on the account is not enough to make transaction.' AS message;
    ELSE
        UPDATE account
            SET
                balance = balance + amount
            WHERE
                id = to_account;

        UPDATE account
            SET
                balance = balance - amount
            WHERE
                id = from_account;

        COMMIT;
    END IF;

    SELECT * FROM account;
END
;;

DELIMITER ;
```
- Note that if we do not use `IN`, MySQL will implicitly treat parameters as `IN` by default.

```
CREATE PROCEDURE move_money(
    IN from_account CHAR(4),
    IN to_account CHAR(4),
    IN amount DECIMAL(9,2)
)
```

|Parameter Type                     | Description                                  |
| --------------------------------- | -------------------------------------------- |
| `IN` | (Default) Input-only parameter. The procedure gets a copy of the value and cannot modify it. |
| `OUT` | Output parameter. The procedure can modify it and return a value. |
| `INOUT` | Input-Output parameter. The procedure can read and modify the value. |

- It can be better with LEAVE:
```
DROP PROCEDURE IF EXISTS move_money;

DELIMITER ;;

CREATE PROCEDURE move_money(
    IN from_account CHAR(4),
    IN to_account CHAR(4),
    IN amount DECIMAL(9,2)
)
BEGIN
    DECLARE current_balance DECIMAL(9,2);
    DECLARE exit_handler CONDITION FOR SQLEXCEPTION ROLLBACK;
    
    -- Label för att kunna använda LEAVE
    DECLARE exit_point BEGIN

    START TRANSACTION;

    -- Hämta nuvarande saldo
    SELECT balance INTO current_balance FROM account WHERE id = from_account;

    -- Kontrollera om saldot är tillräckligt, annars avbryt direkt
    IF current_balance < amount THEN
        ROLLBACK;
        SELECT 'Insufficient funds for the transaction.' AS message;
        LEAVE exit_point;
    END IF;

    -- Utför transaktionen
    UPDATE account
    SET balance = balance - amount
    WHERE id = from_account;

    UPDATE account
    SET balance = balance + amount
    WHERE id = to_account;

    COMMIT;

    END exit_point;  -- Avslutar blocket

    -- Visa uppdaterade konton
    SELECT * FROM account;
END
;;

DELIMITER ;

```
- Example of using mix procedure and .js file:
    - Create procedure show_balance in the database
    - Make route to link with the function in .js file that will querry the sql = CALL show_balance

### d. Triggers:
- Triggers are automatic database actions that execute when an INSERT, UPDATE, or DELETE operation occurs.
    - New row values: NEW.id, NEW.column
    - Old row values: OLD.id, OLD.column
        - Example: Create a procedure to transfer money between two accounts and track when changes occur.
        - Example: Logging Balance Updates with a Trigger

        ```
        --
        -- Example
        -- 
        DROP TABLE IF EXISTS account;
        CREATE TABLE account
        (
        `id` CHAR(4) PRIMARY KEY,
        `name` VARCHAR(8),
        `balance` DECIMAL(4, 2)
        );

        DELETE FROM account;
        INSERT INTO account
        VALUES
        ('1111', 'Adam', 10.0),
        ('2222', 'Eva', 7.0)
        ;

        --
        -- Procedure move_money()
        --
        DROP PROCEDURE IF EXISTS move_money;

        DELIMITER ;;

        CREATE PROCEDURE move_money(
        from_account CHAR(4),
        to_account CHAR(4),
        amount NUMERIC(4, 2)
        )
        MAIN:BEGIN
        DECLARE current_balance NUMERIC(4, 2);

        START TRANSACTION;

        SELECT balance INTO current_balance FROM account WHERE id = from_account;
        SELECT current_balance;

        IF current_balance - amount < 0 THEN
        ROLLBACK;
        SELECT 'Amount on the account is not enough to make transaction.' AS message;
        LEAVE MAIN;
        END IF;

        UPDATE account 
        SET
            balance = balance + amount
        WHERE
            id = to_account;

        UPDATE account 
        SET
            balance = balance - amount
        WHERE
            id = from_account;

        COMMIT;
        SELECT * FROM account;
        END
        ;;

        DELIMITER ;

        CALL move_money('1111', '2222', 1.5);

        --
        -- Log table
        --
        DROP TABLE IF EXISTS account_log;
        CREATE TABLE account_log
        (
        `id` INTEGER PRIMARY KEY AUTO_INCREMENT,
        `when` TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        `what` VARCHAR(20),
        `account` CHAR(4),
        `balance` DECIMAL(4, 2),                            -- max value is 99.99
        `amount` DECIMAL(4, 2)                              -- max value is 99.99
        );

        SELECT * FROM account_log;

        --
        -- logga med triggers
        --
        DROP TRIGGER IF EXISTS log_balance_update;

        CREATE TRIGGER log_balance_update
        AFTER UPDATE
        ON account FOR EACH ROW
        INSERT INTO account_log (`what`, `account`, `balance`, `amount`)
        VALUES ('trigger', NEW.id, NEW.balance, NEW.balance - OLD.balance);

        CALL move_money('1111', '2222', 1.5);

        SELECT * FROM account_log;
        ```

    - Example about using Trigger to avoid user update the data in table account. User can insert, delete but not update. The system will show the error message if the user do this.
    ```
    --
    -- Trigger with compound statement and user defined errors
    --
    DROP TRIGGER IF EXISTS trigger_test2;

    DELIMITER ;;

    CREATE TRIGGER trigger_test2
    BEFORE UPDATE
    ON account FOR EACH ROW
    BEGIN
        SIGNAL SQLSTATE '45000' SET message_text = 'My Error Message'; --SQLSTATE '45000' is a general error code in MySQL that is reserved for user-defined errors 
    END
    ;;
    
    DELIMITER ;
    ```
- Use Cases of Triggers:
    - Enforcing business rules (e.g., ensuring data integrity)
    - Logging and auditing (e.g., tracking data changes)
    - Automating complex processes (e.g., sending notifications)

- Commands:
|Commands                                 | To do                                                |
| --------------------------------------- | ---------------------------------------------------- |
| `SHOW TRIGGERS;` | Show all triggers in database |
| `SHOW TRIGGERS LIKE 'account' \G;` | Show all triggers in database that link to the 'account' table in the vertical format|
| `SHOW TRIGGERS FROM dbwebb \G;` | List all triggers in the dbwebb database and displays their details in a vertical format|
| `DROP TRIGGER IF EXISTS trigger_test1;` | Drop a trigger named trigger_test1 |
| `SHOW CREATE TRIGGER <trigger_name>` | Show how did we creat this trigger |
| `SHOW CREATE TRIGGER <trigger_name> \G` | Show how did we creat this trigger in the vertical format |

- Note:
    - When you DROP a table, the triggers associated with the table disappear. 
    - In an INSERT trigger, the value of NEW, for an AUTO_INCREMENT, is set to 0 and not the value that the key gets when the row is inserted into the table.
    - If a BEFORE trigger fails, the intended operation is not performed.
    - AN AFTER trigger is only executed after all BEFORE triggers have been executed and after the rows have been processed with INSERT, UPDATE or DELETE.

==========//==========//==========//==========//==========//==========//==========

## 5. Function:
- UDF: Write in C++ and then link to the database server.
- Function as a stored routine:
- Example 1:
```
--
-- Function for grading an exam A-F, FX.
--
DROP FUNCTION IF EXISTS grade;
DELIMITER ;;

CREATE FUNCTION grade(
score INTEGER
)
RETURNS CHAR(2)
DETERMINISTIC                   -- Always returns the same result when a set of parameters is passed in
BEGIN
IF score >= 90 THEN
    RETURN 'A';
ELSEIF score >= 80 THEN
    RETURN 'B';
ELSEIF score >= 70 THEN
    RETURN 'C';
ELSEIF score >= 60 THEN
    RETURN 'D';
ELSEIF score >= 55 THEN
    RETURN 'E';
ELSEIF score >= 50 THEN
    RETURN 'FX';
END IF;
RETURN 'F';
END
;;

DELIMITER ;


SELECT 
    *,
    grade(score) AS 'grade'
FROM exam
ORDER BY grade;

```
- Important: Function characteristics: You need to specify a characteristic for them. This is done by stating whether they are `DETERMINISTIC` or `NOT DETERMINISTIC`; `CONTAINSSQL` or `NO SQL` or `READ SQL DATA` or `MODIFIES SQL DATA`

- Example 2:
```
DROP FUNCTION IF EXISTS time_of_the_day;
DELIMITER ;;           

CREATE FUNCTION time_of_the_day()
RETURNS DATETIME
NOT DETERMINISTIC NO SQL            -- Does not return the same result when a set of parameters is passed in. In this case, it returns the current time
BEGIN
    RETURN NOW();
END
;;

DELIMITER ;
```

- Commands:
|Commands                                 | To do                                                |
| --------------------------------------- | ---------------------------------------------------- |
| `SHOW FUNCTION STATUS;` | Show all function's status |
| `SHOW FUNCTION STATUS LIKE 'account' \G;` | Show all function with name 'account' in the vertical format|
| `SHOW FUNCTION STATUS WHERE Db = 'dbwebb' \G;` | List all function in the dbwebb database and displays their details in a vertical format|
| `DROP FUNCTION IF EXISTS score;` | Drop a function named score |
| `SHOW CREATE FUNCTION <function_name>` | Show how did we creat this function |
| `SHOW CREATE FUNCTION <function_name> \G` | Show how did we creat this function in the vertical format |

==========//==========//==========//==========//==========//==========//==========

## 6. Index
- It's very usefull to speed up data retrieval.
- When to use an Index:
    - With searching, filtering, or joining on a column.
    - When we sort or group by a column.
    - Foreign keys: Often need indexes for performance on joins.
    - For performance optimization on large tables.
- Commands:
|Commands                                 | To do                                                |
| --------------------------------------- | ---------------------------------------------------- |
| `CREATE INDEX index_points ON course(points)` | Create index with numberic value |
| `SHOW INDEX FROM course;` | Show all index on table course|
| `DROP INDEX full_name ON course;` | Drop index full_name on table course|
| `DROP INDEX full_name ON course;` | Drop index full_name on table course|

