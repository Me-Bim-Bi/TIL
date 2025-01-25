# Database

## 1. SQLite:
- User DB browser for SQLite
- Basic commands:
  
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
- Install: https://mariadb.com/kb/en/installing-and-using-mariadb-via-docker/
- Docker commands:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|docker restart <container's name>|Start the container named db |
|docker stop <container's name>|Stop the container named db |
|docker exec -it <container's name> bash |start an interactive bash shell inside a running Docker container named db|

### b. Using MariaDB
- User:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|DROP USER IF EXISTS 'maria'@'localhost'; | Delete user 'maria' if it exists. Should to delete before create a new one|
|CREATE USER 'maria'@'localhost' IDENTIFIED BY 'P@ssw0rd'; | Create user with name and password |
|GRANT ALL PRIVILEGES ON *.* TO 'maria'@'localhost' WITH GRANT OPTION;|Grant user permissions|
|FLUSH PRIVILEGES;|Reload the privilege tables in memory. Important to ensures that any changes made to user accounts or permissions take immediate effect without needing to restart the database server.|
|SHOW GRANTS FOR 'dbadm'@'localhost';|Show the user permissions|
|select user();|show the user that we used|

- Database:
  
|Commands                                 | To do                                                |
| ----------------------------------------- | -------------------------------------------------  |
|DROP USER IF EXISTS 'maria'@'localhost'; | Delete user 'maria' if it exists. Should to delete before create a new one|
|CREATE USER 'maria'@'localhost' IDENTIFIED BY 'P@ssw0rd'; | Create user with name and password |
|GRANT ALL PRIVILEGES ON *.* TO 'maria'@'localhost' WITH GRANT OPTION;|Grant user permissions|
|FLUSH PRIVILEGES;|Reload the privilege tables in memory. Important to ensures that any changes made to user accounts or permissions take immediate effect without needing to restart the database server.|
|SHOW GRANTS FOR 'dbadm'@'localhost';|Show the user permissions|
|select user();|show the user that we used|

