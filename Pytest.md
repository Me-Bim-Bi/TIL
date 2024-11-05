# Test och debug

## Pytest notes:
- Need to set up logging. Very helpful for debug. Print out to console with command: app.logger.info("Burger: %s", burger). Don't need to write ""Burger: %s"," but it's easier to read when it have many row will be printed to console.
- Run pytest from terminal: pytest <pytest file name>
   + Use "@pytest.fixture" for beginning a function if want to define a reusable setup for testing
   + A test function start with "test"
   + Set up a function to connect to the database in an other folder: def db_connection()
   ```
     db_path = os.path.join(os.path.dirname(__file__), '..', 'MenuStore', 'orders.db')
    con = sqlite3.connect(db_path)
    cur = con.cursor()
    yield cur
    con.close()
    ```
## Debug section:
```
- October 2, 2024
- Problem:
insert to items values (20, "No add items", items, add)
Execution finished with errors.
Result: near "to": syntax error
At line 1:
insert to
- Debug Session: Checked the def done in BurgerOrderer
- Solution: Edit "insert to" to "insert into", now works.
- References: https://www.sqlitetutorial.net/sqlite-insert/
```