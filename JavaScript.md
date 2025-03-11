# JavaScript

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
