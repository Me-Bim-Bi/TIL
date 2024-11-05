# 1.11.2024
## 1. Structure:
- Must have one functions named 'main'
- A function definition has four elements: a return type, a function name, a (possibly empty) parameter list enclosed in parenthesses, and a function body. 
    ```
    int main ()     \\ a function name (an empty list of parameters)
    {               \\ function body
        return 0;   \\ function body    \\ a return type  
    }               \\ function body
    ```
- The C++ file: .cc, .cxx, .cpp, .cp, and .C.
- The libraty defines 4 IO objects:
    - input: cin (see in) - referred to as the standart input
    - output: cout (see out) - is known as the standart output
    - cerr (see err) - standart error  
    - clog (seelog) - general informattion about the execution of program

### Lession 1:
#include <iostream> // tell the compiler that we want to use the iostream library
int main()          // the main function name and type of ...?
{
   std::cout << "Enter two numbers:" << std::endl; 
   int v1 = 0, v2 = 0;
   std::cin >> v1 >> v2;
   std::cout << "The sum of " << v1 << " and " << v2
            << " is " << v1 + v2 << std::endl;
    return 0;
}

## Comment:
- Update comment when you change something
- A single-line comment begins with a double slash (//) and ends with a newline, can include any text. 
- A comment pair users two delimiters (/* and */), can include any text without (*/). 
Ex1: 
````
/* something
* something
* something
* something
*/
int main ()
{
    // Create main function to blah blah blah
    std::cout << "abc xyz" << std::endl;
}
````
Ex2:
````
WRONG:
#include <iostream>
int main ()
{
    std::cout << "Please insert two numbers " << std::endl;
    /* This is a block comment.
    /* nested block comment*/
    * End of block comment*/
}
````
````
RIGHT:
#include <iostream>
int main ()
{
    std::cout << "Please insert two numbers " << std::endl;
    // /* This is a block comment.
    // /* nested block comment*/
    // * End of block comment*/
}
````