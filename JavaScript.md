# JAVASCRIPT
## 1. Dealing with events:
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
    
==========//==========//==========//==========//==========//==========//==========

## 2. JavaScript syntax:
- One popular code standard is the JavaScript Standard Style: https:://standardjs.com/.

- **Common syntax**:

| Commands | Description |
| ----------------------------------------- | ------------------------------------------------- |
| `"use strict";` | Ensures that the code is interpreted in strict mode. |
| `module.exports = Dice;` | Specifies which part of the module should be exported. |
| `let Dice = require("./dice.js");` | Imports the `Dice` module in Node.js. |
| `console.log();` | Outputs messages to the console. |
| `const d = new Date();` | Creates a new Date object. |
| `let day = d.getDate();` | Retrieves the current day of the month. |
| `console.info("The date today is: " + day);` | Logs the current date to the console. |

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
|     `console.log();`     |Usually use for general debugging and printing variables|
|     `console.warn("Invalid command");`     |Print warning|

    - Example of print a message to console:
    ```
    message = `I'm thinking of number ${thinking}.\n`
        + `Youre guess is ${guess}.\n`
        + `You guessed right? `
        + (thinking === guess);
    console.info(message);
    ```
    - Example about check and convert data with Date format:
    ```
    function teacherAsTable(res) {
    res.forEach(teacher => {
        if (teacher.fodd instanceof Date) { //check if teacher.fodd is Date format
            teacher.fodd = teacher.fodd.toISOString().split('T')[0]; // Formats to YYYY-MM-DD, keep the result before "T"
            //toISOSstring is the method converts a Date object into a string in ISO 8601 format
            //which looks like: YYYY-MM-DDTHH:mm:ss.sssZ, so that T  date and time
        }
    });
    console.table(res);
}
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

    
==========//==========//==========//==========//==========//==========//==========

## 3. JavaScript connect to MySQL:
### a. Install:
- https://npmjs.com/package/mysql
- https://npmjs.com/package/promise-mysql
- https://www.npmjs.com/package/cli-table3 : to have a nice table
- https://www.npmjs.com/package/console.table : to have a nice table
  
### b. Using:
|     Commands     |     Description     |
| ----------------------------------------- | ------------------------------------------------- |
|     `npm init`     | Create a `package.json` file |
|     `npm install mysql promise-mysql`     |install two packages via npm: mysql (This is the official MySQL client library for Node.js, allowing you to connect to and interact with a MySQL database.) and promise-mysql (This is a wrapper around the mysql package that provides a Promise-based API, making it easier to work with asynchronous operations using async/await.)|
|     `npm install console.table --save`     | Install console.table module |


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
## substring: 
- Source: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/substring
- Extracts characters from indexStart up to but not including indexEnd. In particular:
    - If indexEnd is omitted, substring() extracts characters to the end of the string.
    -  If indexStart is equal to indexEnd, substring() returns an empty string.
    - If indexStart is greater than indexEnd, then the effect of substring() is as if the two arguments were swapped; see example below.
- Syntax: 
```
substring(indexStart)
substring(indexStart, indexEnd)
```
- Parameters
    - indexStart: The index of the first character to include in the returned substring.
    - indexEnd: Optional: The index of the first character to exclude from the returned substring.
- Return value: A new string containing the specified part of the given string.
- Exempel: const anyString = "Mozilla";
```
console.log(anyString.substring(0, 1)); // "M"
console.log(anyString.substring(1, 0)); // "M"

console.log(anyString.substring(0, 6)); // "Mozill"

console.log(anyString.substring(4)); // "lla"
console.log(anyString.substring(4, 7)); // "lla"

console.log(anyString.substring(0, 7)); // "Mozilla"
console.log(anyString.substring(0, 10)); // "Mozilla"
```
```
const text = "Mozilla";

// Takes 4 last characters of string
console.log(text.substring(text.length - 4)); // prints "illa"

// Takes 5 last characters of string
console.log(text.substring(text.length - 5)); // prints "zilla"
```

## if sats
- Source: https://www.w3schools.com/js/js_if_else.asp
- Syntax: 
```
if (condition) {
  //  block of code to be executed if the condition is true
}
```
