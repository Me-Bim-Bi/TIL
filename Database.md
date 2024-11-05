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

