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

==============================================================
5 november, 2024

# Structure:
```
- #include <iostream>
- using namespace std;
- class


- viktig att veta om byte, om hur lång kan en variabel kan vara.
- int, long, float, double, cha (bara en teken). Varför man använder cha istället för string. 

- elif (python) = else if (C++)
counter+= 1 (python) = counter++ (C++) = ++counter
                        counter-- = --counter
```


# kolla igen om: getline, ignore, const double, long double, switch-case

==============================================================
# Array:
int hights[6]: arrayen allokearas på stacken ed en förbestämd storlek, detta kan aldrig ändras: 

# Iterationssatser
```
for(initializer; condition; expression)
{
    code block
}
```
Ex: for(int i = 0; i < 10; i++ )

```
while(condition)
{
    code block
}
```

````
do
{
    code block
} while (condition): condition valideras efter varje iteration
````


# Function:
- Sats: 
```
funktion_name(parameter_list)
{
    code block
    return...
}
```
- Does not return anything: use "void"
Ex: 
```
void print_hello()
{
    std::cout << "Hello!" << std::endl;
}
```

# String:
När vi skriver "Text" läggs '\0' automatiskt till i slutet
std::string
// initialization
```
string s1: default initialization; s1 is the empty string
string s2(s1): s2 is a copy of s1
string s2 = s1: equivalent to s2(s1), s2 is a copy of s1
string s3 ("value"): S3 is a copy of the string literal, not including the null.
string s3 = "value": equivalent to s3 ("value"), s3 is a copy of the string literal
string s4(n,'c'): intilialize s4 with n copies of the character 'c'
```
````
string s
os << s         : Writes s onto output stram os. Returns os.
is >> s         : Reads  whitespace-separated string form is into s. Returns is.
getline(is, s)  : Reads a line of input from is into s. Returns is.
s.empty()       : Returns true if s is empty; otherwise returns false.
s.size()        : Returns the number of characters in s.
s[n]            : Returns a reference to the char at position n in s; positions start at 0.
s1 + s2         : Returns a string that is the concatenation of s1 and s2.
s1 = s2         : Replaces characters in s1 with a copy of s2
s1 == s2        : The strings s1 and s2 are equal if they contain the same characters
s1 != s2        : Equality is case-sensitive
<, <=, >, >=    : Comparisons are case-sensitive and use dictionary ordering
````
// assignment
name = "Alice";
name2 = std::string("Bob");

Convert string to integer: 
int number = std::stoi(numberString)
long longNumber = std::stol(numberString)
numberString = std::to:string(-10);

std::getline(std::cin, name); // läser från cin till nästa newline
std::cin >> name; // cin läser bara till nästa whitespace!!!

# rand()
v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014