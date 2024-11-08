# Module 1
## Del 1:

## A. Övningsuppgifter - Variabler, datatyper och uttryck

### 1. Ge exempel på 3 primitiva datatyper i C++:
- Primitive data type: Primary: Integer (int, short unsigned short, unsigned int, long long, unsigned long long), character(cha), Bollean (bool), Floating Point (float), Double floating point (double), void, wide character (signed char) (Built in datatypes)
- Extern kunskap: Non-primitive data type:
    - Derived: function, array, pointer, reference (Built in type)
    - User Defined: class, structure, union, enum, typedef

### 2. Är std::string en primitv datatyp?
Nej, det är en "class" in C++ standart library. 

### 3. Vad blir resultatet av 10/4 i C++? 
- 2 för att 10 och 4 är integer typ

### 4. Vad blir resultatet av 12.0/5 i C++? 
- 2.4 för att 12.0 är float typ

### 5. Vad blir
    ```
     A: true || false? => True
     B: true && false? => False
     C: true && false || true? => 
    ```
````
Operatorer (ungefär vad man förväntar sig...)
• Aritmetiska operatorer + - * / %
• Tilldelning =
• Sammansatta tilldelningar += -= *= /= %=
• Jämförelse == != < <= > >=
• Logiska && (and) || (or) ! (not)
• Increment/Decrement ++ --
• prefix/postfix operators
    ° int i = 0, j = 0
    ° j = ++i; // j = 1, i = 1: prefix
    ° j = i++; // j = 1, i = 2: postfix
````

### 6. Visa tre olika sätt att öka innehållet i en heltalsvariabel med värdet 1.
for(int i = 0; i <= 100; i++)
for(int i = 0; i <= 100; ++i)
for(int i = 0; i <= 100; i+=1)

### 7. Kan man omvandla (type cast) ett heltal till ett flyttal i C++? 
- Ja.
- Ex:
```
int main()
{
    int test_number = 10;
    float float_number = static_cast<float>(test_number);
    
    return 0;
}
```

### 8. Vad blir resultatet av static_cast<int>(5.78) (alternativt (int)5.78)?
- 5

### 9. Vad kommer str innehålla efter std::string str; ?
- tom sträng och har en längd på 0


### 10. Vad betyder ! (utropstecken)?
- Betyder "not" 

### 11. Hur skriver man för att avgöra om strängen i variabeln str1 är densamma som strängen i variabeln str2? 
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1; string str2;
    str1 = "toi la thanh";
    str2 = "toi ten la thanh";
    if (str1 == str2)
    {
        cout << "str1 är samma som str2" << endl;
    }
    else
    {
        cout << "str1 är inte samma som str2" << endl;
    }
    return 0;
}
```
### 12. Hur skriver man om man ska skapa en sträng som ska innehålla ett visst bestämt antal förekomster av ett visst tecken, där tecknet finns i variablen char c och antalet finns i variablen int nrOf? Om ex-vis nrOf innehåller 7 och nrOf inehåller 'F', ska det resultera i strängen "FFFFFFF".

````
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;
    char c = 'F';
    int nr0f = 7;
    
    string new_string(nr0f, c);

    cout << "The new string is: " << new_string << endl;


    return 0;
}
````  
### 13. Om rand() ger ett heltal som är 0 eller större. Hur kan du då skriva för att få ett heltal inom intervallet
```
A: [0..20] heltal = rand() % 21
B: [10..20] heltal = rand() % 11 + 10
C: [-10..10] heltal = rand() % 21 - 10
```

### 14. Användaren ska mata in en sträng som motsvarar ett registreringsnummer och som omfattar exakt 6 tecken (ex-vis ABR129). Hur skriver du för att inmatningen ska ske till variabeln? Du kan anta att variabelnamnet är regNr.
````
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string regNr;
    cout << "Please insert the registernumber " << endl;
    cin >> regNr;
    if (regNr.length() == 6)
    {
        cout << "It's a valid registernumber." << endl;
    }
    else
    {
        cout << "Invalid input data" << endl;
    }
}
````
### 15. Användaren ska mata in en sträng som motsvarar en gatuadress vilken omfattar både gatans namn och nummer (ex-vis Prinsgatan 45). Hur skriver du för att inmatningen ska ske till variabeln? Du kan anta att variabelnamnet är address.
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string gatan; string address;
    cout << "Insert the name of road " << endl;
    getline(cin, gatan);
    int number;
    cout << "Insert the address number " << endl;
    cin >> number;
    cout << "Address is " << gatan << " " << number << endl;
    return 0;
}
```

### 16. Vad är det för problem med följande kodavsnitt?
```
std::string name;
int year;
std::cout<<"Birth year: "; cin>>year;
std::cout<<"Name: "; getline(std::cin, name);
std::cout<<name<<" was born in "<<year<<std::endl;
```
- getline has not :std::. I do not know if the C++ file has got 'using namespace std' before or not. 
- have 'cin' before but do not have cin.ignore so the program steps over the step that the user will insert the name
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    int year;
    cout<<"Birth year: "; cin>>year;
    cout<<"Name: " << endl;
    cin.ignore(100,'\n'); // Tömmer inströmmen cin på max 100 tecken eller till radbrytning ('\n').
    getline(cin, name);
    cout<<name<<" was born in "<<year<<endl;
    return 0;
}
```
### 17. Vad blir det för utskrift när följande kodavsnitt exekveras?
```
int i = 5;
int k = i++;
int m = ++k;
std::cout<<k<<" "<<m<<std::endl;
```
- 6 6
- k = i++ => k = i = 5. After that, i = i + 1 = 6
- m = ++k => k = 5 + 1 = 6. After that, m = k = 6
### 18. Vad blir det för utskrifter när följande kodavsnitt exekveras?
```
int i = 10;
float f = 12.5f;
int res = f + i;
std::cout<<res<<" "<<i + f<<std::endl;
```
- 22 22.5
- res = int(22.5) = 22. 
- i + f = 22.5
