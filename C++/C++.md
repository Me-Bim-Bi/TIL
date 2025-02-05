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
- unsigned int: positiv heltal
==============================================================
# Array:
int hights[6]: arrayen allokearas på stacken ed en förbestämd storlek, detta kan aldrig ändras: 
int hights[6] = {0}: alla elementer i arrayen är lika med 0
size(hights): storlek på arrayen (number of elements in the array)
sizeof(hights): number of bytes in the array

````
int values[5] = {0, 1, 2, 3, 4, 5};
cout << "\nIteration med range for << endl;
sum = 0;
for (int value : values) {
    sum += value;
}
cout << "Sum = " << sum << endl;
````

- int graddning[CAP]{0}: alla får värdet 0

# Iterationssatser
```
for(initializer; condition; expression)
{
    code block;
}
```
Ex: for(int i = 0; i < 10; i++ )
for (int i = 0, j = 4; i < 5; i++, j--)

```
while(condition)
{
    code block;
}
```

````
do
{
    code block;
} while (condition): condition valideras efter varje iteration
````

# Selektion
## if-else:
```
if (condition)
{
    code block;
}
else if (condition)
{
    code block;
}
else
{
    code block;
}
```
```
char c = 'q'
switch (c){
    case 'a':
        break;
    case 'q':
        break;
}
```
In C++, both switch and if statements allow conditional branching, but they are used in different scenarios and have different syntax. Here’s a breakdown of their differences:

1. Usage
if statement: Can be used with a wide range of conditions, including complex logical expressions. It supports conditions involving any data type, including strings, floats, and complex comparisons.
switch statement: Works only with discrete values, specifically integers, char, or enum types in C++. It doesn't work with floating-point numbers, strings, or complex conditions.
2. Syntax and Structure
if statement:
cpp
Copy code
if (condition1) {
    // code block if condition1 is true
} else if (condition2) {
    // code block if condition2 is true
} else {
    // code block if all conditions are false
}
switch statement:
cpp
Copy code
switch (variable) {
    case value1:
        // code block if variable == value1
        break;
    case value2:
        // code block if variable == value2
        break;
    default:
        // code block if none of the cases are matched
}

- declare many variables at the same time: int sum = 0, value = 0;
- cout and cin at the same line: cout << "aloha "; cin >> name;
3. Performance
switch can be more efficient for multiple discrete values as it often compiles into a jump table, which may provide faster execution.
if statements are evaluated sequentially from top to bottom, so they may be slower if there are many conditions, especially if the matching condition is towards the end.
4. Flexibility
if is more flexible, allowing conditions that are not just equalities. You can use greater than, less than, logical AND
# Function:
- Sats: 
````
return_type function_name(parameter_list)
{
    code block
    return...
}
````

- Does not return anything: use "void"
- Med defaltvärde: måste komma sist i parameterlistan: Ex: int add(int a, int b = 1)
- Överlagring (Overloading)
    - Samma funktionsnamn men olika parameterlista: det kan funka. Dator kollar och hittar någonting som passar och använder det (kan unik). Även samma namn med void och str, int... det gör ingenting
    ````
    void func(int nr, string str)
    void func(string str)
    void func()
    void func(int nr1, int n2)
    string func()
    ````
    - Olika parameterlistor:
        - Olika antal parametrar
        _ Olika datatyper
        - Inte bara olika parameternamn!
    - Inte olika returyper
- Ctrl + "." => fixa felet för mig
- Behöver inte att namn är samma namn när man ropar. Man får välja att dopas det på samma eller olika nan
- Man kan skapa en fil med alla name, variabel... sedan länkar dem till main function. 
- Man måste ha både: funktiondeklarationer och funktionsdefinitioner
Ex: 
```
void print_hello()
{
    std::cout << "Hello!" << std::endl;
}
```
# Mer functioner
- referensparameter: ändra argument
```
void func(int nr, int &nr1, const string& str) 
int nr: bara kopiera
int &nr: alias, nytt namn eller samma namn, kan ändra innehållet
const string& str: alias, nytt namn eller samma namn, kan int ändra innehållet
```
(& kan stå med variebel eller ...variebel type), undvika att kopiera någonting som är stor
```
i main fil eller annan fil:
int number = 4
int value = 5
func (number, value)
```
- värdeparameter: bara kopiera, inte ändra argument
void func(int nr, int nr1, const str)

- defaultargument
void func (int nr = 20)
- överlagring: Samma funktionsnamn men olika parameterlista

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
os << s         : Writes s onto output stream os. Returns os.
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

'' => tecken
"" => string

std::getline(std::cin, name); // läser från cin till nästa newline
std::cin >> name; // cin läser bara till nästa whitespace!!!

# rand()
v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014

# omvänla variabel
(float)grading[1] => ändra ingenting i minnet, bara tar upp värdet och vändlar det till float och använder det.
cout << fixed << setprecision (2) << gpa: set gpa so that have 2 numbers after point (8.01)
# Hantera med filerna:
behöver inte skapa många project:
soursce file => add => new item => C++ file
markera att det file, properties. excluded from build, choose "Yes" om vi inte vill att det ska vara med i projekt. 

med C++, använder alltid inte run programer. use: Build, compile, kolla 1 file som vi skrev på rätt sätt, syntax är rätt. Det bildern til ny fil (som in output. . länkar allt objekfilerna til ett objekt program). Det skapar ett fil .exe => det ska vi köra när vi ....

start with debugging. 

# Noterat under lektionen: 
- cin => läsa till den nästa '\n' så när vi har många input => läsa och ta med dem det läsa till minne cho nen khi doc xong thi doan doc do biet mat, de lai moi dau cach. Khi cin tiep theo doc thi chi con moi dau cach nay thoi, tom sträng  => cin.ignore()
- getline() läsa men ta inte med dem till minne

- khi goi 1 function, co the add luon 1 string. Ex: 
voide show(string phrase)
=> show ("Lakke kula");


- const: kan inte ändra på

==========
# 13 November 2024

## Dator, kretsar och minne:
- 1 byte = 8 bits. Varje byta har en adress i minnet. 
- allokera och avllokera någonting på heapen.

## Peka and arrays:
- Stack allocations: (int  myInt = 5;) : stackallokeringar "växer" tillsammans i minnet 
- Heap allocations: medan här (int* myInt = new int(5);) är våra pekare lokala variabler som pushas till stacken, precis som våra tidigare variable. Efter det måste man "delete" avallokerar minnet (delete myInt;)

- Vad händer om man inte avllokera minnet? Vi har taapat adresser till våra heap-allokerade variable = minnesläcker. Man kan inte återanvända...? full i minnet
````
cout << "Pointers:" << endl;
int a = 10;
int * pointer_a = nullptr;
pointer_a = &a;

cout << "a = " << a << endl;
cout << "pointer_a = " << pointer_a << endl;
cout << "a via pekaren = " << *pointer_a << endl;

*pointer_a++;: //det betyder bara att man ökar 4 bytes. Peka utanför istället.
USE IT: (*pointer_a)++;
cout << "a = " << a << endl;
cout << "pointer_a = " << pointer_a << endl;
cout << "a via pekaren = " << *pointer_a << endl;
````
- pointer and arrays
````

int numbers [5] = { 0, 1, 2, 3, 4 };
    int* array_pointer = numbers;
    cout << "Array[0] = " << *array_pointer << endl; //Array[0] = 0
    cout << "Array[1] = " << *(array_pointer + 1) << endl; //Array[1] = 1
    cout << "Array[2] = " << *(array_pointer + 2) << endl; //Array[2] = 2

    cout << "Array[1] = " << *(++array_pointer) << endl; //Array[1] = 1
    cout << "Array[2] = " << *(++array_pointer) << endl; //Array[2] = 2
    cout << "Array[3] = " << *(++array_pointer) << endl; //Array[3] = 3

````
- Dynamic allocation with pointers
```
int* intPointer = new int(5);
    cout << "intPointer = " << intPointer << endl; //intPointer = 0x600002e84000
    cout << "Value at intPointer = " << *intPointer << endl; //Value at intPointer = 5

    int* intArrayPointer = new int [5] { 1, 2, 3, 4, 5 };
    cout << "intArray[0] = " << *intArrayPointer << endl; //intArray[0] = 1
    cout << "intArray[0] = " << intArrayPointer[0] << endl; //intArray[0] = 1
```
- Deallocation (delete) (if dynamic allocation with pointers)
```
delete intPointer;
delete[] intArrayPointer;
```
I
- References
```
int value = 10;

int& valueRef = value;
cout << "value = " << valueRef << endl; //value = 10
valueRef++; 
value++;            //När man ökar value ökar valueRef med.
cout << "value = " << valueRef << endl; //value = 12
```
- string* iceCreams = nullptr; => pekar på null eller pekar på ingen någonstans
- iceCreams = new string [nrOfIceCreams]: nytt minne är en array some har string of nrOfIceCreams. Minnen hittar plats för dem och de behöver inte ligga nära varandra, bara hitta lediga platser.
- gradings = new int[nrOfIceCreams] {0}

```
You said:
what different between const int value and const int* value
ChatGPT said:

ChatGPT
The distinction between const int value and const int* value lies in what is declared constant and how the const qualifier applies. Let's break it down:

1. const int value:
This declares a constant integer.
The value of the integer itself is constant, meaning it cannot be modified after initialization.
Example:
cpp
Copy code
const int value = 42;
value = 10; // Error: cannot modify a const variable
Here, value is a constant integer whose value cannot change.
2. const int* value:
This declares a pointer to a constant integer.
The integer being pointed to is constant, meaning you cannot modify the value through the pointer. However, the pointer itself is not constant, so you can make it point to a different constant integer.
Example:
cpp
Copy code
int a = 42;
int b = 50;
const int* value = &a;

*value = 10; // Error: cannot modify the value through the pointer
value = &b;  // Allowed: the pointer itself is not constant
Here:

The data (*value) is constant and cannot be changed through the pointer.
The pointer (value) can change to point to another constant integer.
Key Differences:
Aspect	const int value	const int* value
Const qualifier applies to	The integer itself	The value pointed to, not the pointer
Modification of value	Not allowed	Not allowed through the pointer
Reassignment	Not applicable (not a pointer)	Pointer can point to another address
Example Usage:
Use const int when you need a read-only integer.
Use const int* when you want a pointer that can point to constant data.
If you need a pointer that cannot be reassigned either, you can use const int* const. For example:

cpp
Copy code
const int a = 42;
const int* const ptr = &a;

ptr = &b;      // Error: pointer itself is constant
*ptr = 10;     // Error: cannot modify the value pointed to
```

## Header filer:
- Välja man att skapa en "Hearder file" in Microsoft Visuo Studio
- Använd: #include "headerfile_name.h" in main.cpp, 
```
I header file:
# ifndef MATH_HPP
# define MATH_HPP
//declaration
...
#endif MATH_HPP

I source files (aka, källfiler) (main och funktions filer):

#include "math.hpp"
// Definition
...

```
- Header file: #include <fstream>
- Läsa från fil: std::ifstream;
- Skriva till fil: std:ofstream;
- Öpnna fil för läsning: std::ifstream input_file("file_name.txt");
- Läsa från fil- jämför med cin:
    - string some_string;
    - input_file >> some_string;
- Öppna fil för skriving:
    - std::ofstream output_file("file_name.txt");
    - std::ofstream output_file("file_name.txt", ofstream::out | ofstream::app);
- Skriva till fil- jämför med cout:
    - string some_string;
    - output_file >> some_string;

- void readIceCreamsFromFile(const string& fileName)


# If-throw (in function), try-chatch (in main):
- In function:
````
voide my_function(bool valid)
{
    if (!valid)
        throw "Something when wrong!";
}

````
- In main:
```
int main()
{
    try
    {
        my_function(false);
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
    }
}
```
ctrl + '.'
# filer
- Resource Files => add item => Utility => Text file
- i file som man ska läsa filen skriver man #include<fstream>



default parametet
bool för att kolla filen
- test 1 i taget. ändra det till comment sedan 


- File text inne resource file och den fösta rad bör bli number av rad som vi ska ha i filen.

===============
20 Nov 2024
# Klasser och objekt
- Med objektorienterad: fokus på att skapa egna datatyper (klasser) som matchar "saker" och "begrepp" i det aktuella problemområdet. 
- objekt är en instans av en klasss medans klasser är grupp av variebler och funktioner och är dataytyper.
- Funktioner hos ett objekt påverkar i regel BARA det objektet, inte de andra objektet. Läraren: varje anka är ett objekt. 
- Medlem av klasser: man får välja vilkea medlemmar som ska vara privata eller publika. Om man inte väljer blir det medlem privat. 
    - Medlemsvariabler
    - Medlemsfunktioner

- Klassdiagram:
    - man skiver:   - med privatevariable/function
    -               + med publicvariable/function
    -               0..* när man menar att det från 0-många objekt
                    när man pekade använder man ->
````
Coords* myCoords2 = new Coords { 5, 6 };
myCoords2 -> x = 7;
myCoords2 -> y = 8;
delete myCoords2;
````
- Man deklarerar också klasser och alla funktionser på header file och definiterar dem på .cpp file, som vanligt.
````
class MyClass
{
    float first;
    float second;
public:
    float GetAverage();
}
````
````
float MyClass::GetAverage()
{'float sum = 0;
sum += this -> first;
sum += this -> second;
return sum / 2.0f;
}
````

- Skapa klass:
    - Klass Dice
        - Egenskap: value: private
        - Function: roll(): 

- Create new item as Class. Create automatic .cpp and .hpp file
- getValue method ska inte ändra något utan bara hämtar värdet.
- this: 'r en pekare som har adressen till objektet själv'
- bara byta ur namnet => void
- string är ett klass, inte bara ett primitive data type.

=======================
# 22 november 2024 - Lab 


- những dòng kẻ ý nghĩa là quan hệ vs nhau. Manysystem biết dataype BuddyBook nhưng ko quen Buddy. BuddyBook quen Buddy và cả MenySystem. Ex: compisboken. 
- string är ett klass så name här är parameter så det måste vara const: void setName(const string& name);
- setName => getName igen för att ha en ny värde.
- öka ålder: använder growAge(): this -> age++
- man vill konvetera ett heltal till sträng: to_string(heltal)
## medlemmar
- Variabler
- Funktioner
- Speciella klassmedlemmar:
    - Konstruktor: kallas när objekt skapas, ska initiera objektet, har alltid samma namn som klass själv.
    - Destruktor: kallas nör objektet förströrs, ska sätta objektet i ett förstörbart skick, har samma namn som klassen, men med ~ innan.
    - Operatorer: tillåter oss att definiera egna beteenden för operatorer.
## inkapsling, information hiding
## konstruktor, destruktor
- Det är väldigt viktig att skapa ett defaul konstruktor för att föt exemple när man skapa ett objekt som pekar på nullptr sedan ger det value: aBuddy = new Buddy[3] => program kraschar och visar felet
## private (-), public(+), (protected(#))
## Klassdiagram
## operatoröverlagring
## konstanta medlemsfuntioner
- med funktion: ligger efter ()
- med variebler: ligger innan string/int
## pekare
- när man skiver: Buddy* cBuddy = nullptr; => ligger det på Stack med pyttelitte plats
- när man skiver: cBuddy = new Buddy ("Ulf", 13, 132.0f) => kommer det från Stack till Heap.
- när man skiver: Buddy* eBuddy[2]{nullptr} => ligger det på stack. och det står att det finns 2 plats i stack. eBuddy[0] = new Buddy(); då kommer det till Heap.
- lägger den rad som man ska kolla på minneläcken
- delelte objekt. Bara efter det, allt kommer till Stack så har vi resultet av allt.
- pekar 2 pointer: vi allokerar allt på Heapen. Det finns också pyttelitte plats på stack i början men sedan allt växter på Heap till när vi tar bort allt.
## Kopieringskonstruktor
- Kopierar dynamiskt allokerat minne
- Undviker då pekare till samma minne
````
class ClassA
{
    int a, b;
    int* p;
    int* array[2];
public:
    ClassA(const ClassA& other): a(other.a), b(other.b), p(new int(*other.p))
    {
        for (int i = 0; i < std::size(this->array);++i)
        {
            this->array[i] = new int(*other.array[i]);
        }
    }
}
````


=======================
# klassrelationer (komposition)

# klassdiagram (notation)

# skapa kopior av objekt

# pekare och dyn.minnesallok

# dereferering

string::bpos: betyder att det inte finns den strängen.

=======================
# 5 December 2024 ARV

- Copy-konstrucktorn exekveras när vi vill har: BuddyBook bBook = aBook; eller BuddyBook cBook(aBook); => också kopiera konstruktorn.

```
void somthing(BuddyBook someBook) {...}
```

```
Buddy bBook = aBook; // kopering objekt.
something(bBook); //kopiering konstrucktorn
aBook = bBook; //ett objekt som måste vara förendras för att bli samma som ett annat objekt. Tilldelnings operatiorn
```


- Om man skiva så här:
```
Box::Box(float height, float width, float (length)
{
this-width;
this->length;
```
så "height" kommer till default konstruktor Shape.

det finns alltid ett kopiering konstruktor, 
- Om subklassen har inte någon function som till exempel heter descriptions men basklassen har man => program kommer upp til basklass och hämta infomation här istället när man ropar funktion description i subklassen.
### Vituella
- Virturella: för att göra en funktion virtuell (kan man har i basklasser men använder i subklasser)
- Man behöver bara skriva "override" eller "virtual" på .h filen, inte .cpp filen.
- "override" och "virtual" är ju barn-föräldrar relation. Man kan skriva bara "virtual" men kan inte bara "override" (måste ha "virtual" också)
- 

### Vecto
- Vecto: syntax: 
```
vecto<datatype>name_vecto
vecto<int>height

vector<int> width(5): vecto med 5 elementer
vector<int> long(5, 10): vecto med 5 elementer och alla elementerna har värde 10.
Med de två sätter här får man oskså push_back när det behövs.

height.push_back(153) \\add element in vecto

\\kolla alla elementer i vecto genom index
for(int i = 0; i < height.size(); i++)
{
    cout << x << endl;
}

\\kolla alla elementer i vecto med for each
for(int x: height)
{
    cout << x << endl;
}

\\kolla alla elemeter i vecto genom iterator
for (vector<int>::iterator it = height.begin(); it != height.end(); i++)
{
    cout << *it << endl; \truy cap den gia tri ma vecto tro vao. con tro thong minh.
}
height.begin(): den första element
height.end(): den elementen efter den sista element

\\kolla alla elementer i vecto genom auto
for(auto it = height.begin(); it != height.end(); ++it)
{
    cout << *it << endl;
}

```


func(int*& a)
sant sant falskt falskt med de pm dynamist objekt ABCD


bilden med planet one two three
A, B: copiering constructor
C, F är ok
D, E: nej


self-check: tilldelning, vill inte köra tilldelning. 
if(*this == other) nej
if(this != &other) okej

Ball aball = theBall => copy constructor

bara C

