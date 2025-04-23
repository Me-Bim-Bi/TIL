# WEEK 1 - Linjärsökning, binärsökning, tidskomplexitet, insertionsort och selectionsort
## Serminatoriet
Linjärsökning: går genom alla 
Binärsökning
- Vi jobbar bara med heltal


A. Linjärsökning kan vara snabbare än binärsökning vid sökning i en sorterad sekvens/array med minst 300 element: Om det är de första eller andra elementer... så kanske. 
    Falsk. log....

B. Linjärsökning kräver att sekvensen/arrayen är sorterad. Falsk.
C. Om ett element som söks inte finns i sekvensen/arrayen kommer binärsökning alltid att vara snabbare med att inse detta. Sant.
D. Om innehållet i en array är (indexering fr.o.m 0) 13  34  36  40  44  51  56  65   76   78   89  92 
          a) krävs 3 jämförelser för att hitta elementet 56 med binärsökning: 51, 76, 56 => Sant
          b) krävs 8 jämförelser för att hitta elementet 76 med linjärsökning:  9 => Falsk
          c) krävs 4 jämförelser för att hitta elementet 34 med binärsökning: 51, 36, 13, 34 => Sant
          d) krävs 10 jämförelser för att inse att elementet 77 inte finns med linjärsökning: 12 => Falsk
          e) krävs 3 jämförelser för att inse att elementet 77 inte finns med binärsökning: => 51, 76, 77 inte finns där så kommer vi kolla ingen 76 => Falsk
E.  Vid binärsökning i en sekvens/array innehållande n element och krävs i värsta fallet k jämförelser. Om n blir fyra gånger så stort kommer det att krävas k+4 jämförelser: => Falsk 




Tidskomplexitet
 
Vad betyder T(n) = O(f(n))? Vilken är definitionen av O?
Vad betyder T(n) = Ω(f(n))? Vilken är definitionen av Ω?
Vad betyder T(n) = Θ(f(n))? Vilken är definitionen av Θ?
Vilket/vilka av alternativen nedan är sanna om f(n) = 3.6n2 + 45.8log2n och g(n) = 16n2 + 678 och h(n) = 54.7nlog2n + 23.8n + 79
g(n) = O(nlog2n)    Falsk
g(n) = O(n3)        Sant
h(n) = O(nlog2n)    Sant
h(n) = Ω(n)         Sant
f(n) = Ω(n2)        Sant        
f(n) = Θ(n2)        Sant
Visa att T(n) = n2 + 4n + 1 är O(n2) 
Visa att T(n) = nlog2n + 12n + 65 är Ω(n)
Visa att T(n) = n3 + n = Θ(n3)
Vad är T(n) för följande pseudokod-avsnitt
A)                          B)                          C)
                              end = n*n             A är en array 
i=0                         i=0                        for i=0 to n-1
res = 1                   res = 0                     index = i
while i<n               while i<end             for k = i+1 to n
     res = res*i          res = res+i                     if A(k)<A(index)
     i=i+1                   i++                                        index = k
return res              return res                swap A[i] and A[index]


Insertionsort
Vilken är "principen"?
Hur sorteras följande sekvenser? 
60 40 70 30 80 10 50 90 40
90 80 70 60 50 40 30 20 10
10 20 40 30 60 50 70 80 90 
Hur många jämförelser utförs i ovan sekvenser vid sorteringen?
Vad innebär det för ett generellt värde n på antalet?
Vilken tidkomplexitet har insertionsort i värsta fallet?
Selectionsort
Vilken är "principen"?
Hur sorteras följande sekvenser? 
60 40 70 30 80 10 50 90 40
90 80 70 60 50 40 30 20 10
10 20 40 30 60 50 70 80 90 
Hur många jämförelser utförs i ovan sekvenser vid sorteringen?
Vad innebär det för ett generellt antal n?
Vilken tidskomplexitet har selectionsort i värsta fallet?
Kan någon av de båda sorteringsalgoritmerna vara bättre(snabbare) än den andra vid sortering av array med samma innehåll? Motivera

## Övning

Sida

av 3
ZOOM
Sökning, tidskomplexitet insertionsort och selectionssort
1. Vilken tidskomplexitet har linjärsökning i värsta/sämsta fallet? => O(n)
- I bästa fall hittar man elementet direkt (första platsen) → O(1)
- I genomsnitt måste man gå igenom hälften av elementen → O(n)
- I värsta fallet finns inte elementet i listan, eller ligger sist → O(n)

2. Vilken tidskomplexitet har binärsökning i värsta/sämsta fallet? => =(log2n)
- Bästa fall: Elementet finns mitt i → O(1)
- Värsta fall: Elementet finns inte eller är i ytterkant → O(log n)

3. Vilket krav ställs på den sekvens av element som binärsökningen ska genomföras på? Sorterad

4. Kan linjärsökning vara snabbare än binärsökning? Motivera ditt svar? Ja.Om det element som söks är placerat först.

5. Anta en sorterad array med 350 element (indexerad fr.o.m 0) och att det element som söks finns
i den tredje fjärdedelen av arrayen. Vilka index motsvarande startindex, slutindex samt mittindex
kommer binärsökning att generera för den delsekvens som motsvarar den aktuella fjärdedelen? 
- Step 1: 0, 349, 174
- Step 2: 0, 223, 112 (175, 349, 262) 
- Step 3: 0, 87, 43 (175, 262, 218) 

6. Om tidskomplexiteten för en algoritm är T(n) kvadratisk, dvs cn2
, och det vid exekvering med
1000 element tog 2 mikrosekunder. Vilket är då värdet på ’c’? 2/1000^2 = 2 * 10^-6
7. Anta att det tar 3 ms att exekvera linjärsökning i värsta fallet i en array innehållande 3000 
element.
a. Hur lång tid förväntas det då ta om antalet ökas till 12000?
i. ca 4 ms
ii. ca 6 ms
iii. ca 12 ms => sant
b. Om det vid en annan exekvering tog 9 ms, hur många element innehöll i så fall arrayen? => 9000
8. Anta att det tar 3 ms att exekvera binärsökning för värsta fallet i en array innehållande 3000
element.
a. Om det vid en annan exekvering tog 9 ms, hur många element innehöll i så fall arrayen? => 3000^3
b. För vilket antal element, dvs värde på n, kommer det att ta 1 ms? => 3000^1/3 = 14
9. Uttryck n3
/5+21n2
-14n+3 i Θ-notation => n^3 => växte snabbaste
10. Är 2 n+1 = O(2n  => ja )? Är 2 2n = O(2 n )? => nej, 2^2n är mycket snabbare än O(2^n)
11. Visa att f(n) = 12n3 + 4n2 – 12 = O(n3
)
12. Analysera och bestäm tidkomplexiteten O(f(n)) för pseudokod-avsnitten nedan
a. result = 1
for i = 0 to 100
result = result*(i+n)
b. result = 0
for i = 2n down to 0
result = result + i
c. result = 0
for i=0 to n
for k=i to n
result = result + A[k]
A[i] = result
result = 0
d. for i=1 to n
k = i-1
temp = A[i]
while k>=0 AND temp < A[k]
k--
A[k+1] = temp
e. result = 0;
if number MOD 2 == 0
for i=0 to n
result = result + i
else
result = number*number
13. Vilken tidskomplexitet har Selectionsort i värsta fallet? => O(n^2)
14. Visa hur innehållet i arrayen nedan sorteras med insertionsort resp selectionsort
a)
b)
15. Anta funktionen f(n) =7n3 – 5n2 + 20n. Nedan följer några påståenden avseende hur funktionen
växer beroende på n.
a. f(n) = O(n4
) Korrekt
b. f(n) = O(n2
)
c. f(n) = Ω(n2
) Korrekt
d. f(n) = Ω(n) Korrekt
e. f(n) = Θ(n3
) Korrekt
f. f(n) = Θ(n)
Vilket/vilka av dessa är korrekt/korrekta?
16. Vi exekvering av en algoritm uppmättes följande resultat. Vilket tidskomplexitet har algoritmen?
n Tid i ms
100 0.000002
1000 0.000022
10000 0.000222
100000 0.002205
1000000 0.022711
17. Vi exekvering av en algoritm uppmättes följande resultat. Vilket tidskomplexitet har algoritmen?
n Tid i ms
100 0.000006
1000 0.000371
10000 0.03322
100000 3.33
1000000 NA
56 31 8 96 77 13 45 31 29 56
23 45 56 40 62 66 78 63 83 89



=================
# Vecka 2

Seminarium A2
Omfattar primärt tillbakablick på Divide-and-Conquer, Rekursion, Mergesort, Quicksort och dessutom lite mer kring partitioneringsprincip för quicksort samt Heapsort (och definition av Heap).

## Divide-and-conquer

- Vad innebär denna teknik?
- Hur relaterar det till rekursion? 

## Mergesort
- Princip
- Pseudokod om merge-algoritmen är given
- Hur sorteras 
    - **After mergesort(), kör man merge() där lår man ihop 2 sorterad listor och sorterar den igen.**
    - 22  11  10  63  74  55  48  33
    - 22  5  11  19  55  63  74  10  48  33 7 13
- Tidskomplexitet: T(n) = n(log(n))
- Stabil? In-place? inte


## Quicksort
Princip
Pseudokod om partitioneringslagoritmen är given
```
Quicksort(a, start, slut)
    if (start < slut)
        pivot = partition(a, start, slut)
        Quicksort(a, start, pivot -1 )
        Quicksort(a, pivot +1, slut)
        

```



Pivot-element
Partitionering
Att bestämma pivot-element -> olika alternativ
Visa hur följden sorteras om pivot elementet alltid är det sista och partitioneringen utförs enligt kurslitteraturen
48  63  19  26  88  89  12  53  9  4  66  83  92  45 
11  22  33  44  55  66  77  88  99 
Tidskomplexitet: nlog(n) men kanske bara...O(n)
Stabil? In-place? kan vara stabil om man inte valjer pivot felt.

## Heap, Heapsort, 
(max)-Heap (anta att indexeringen i arrayen bärjar på 0)
Struktur och regel
Utgå från en array med innehållet 35 56 47 25 98 20 34 42 15 och omvandla detta till en max-heap genom att arbeta "bottom-up".
gå från vänster till höger och fylla på trädet. Sedan gör man med "bottom-up"

Ta därefter bort det största värdet.
På vilket index finns 56?
På vilket index finns 15?
På vilket index finns föräldern till 20?
På vilka index finns vänster barn respektive höger till 42?
På vilka index finns föräldern, vänster barn respektve höger barn till elementet på index k?

## Heapsort
Princip 
Visa hur följden 73  48  19  26  88  39  12  53  19  4  66  83  92  28 sorteras med heapsort
Tidskomplexitet: n.log(n) för att bygga trädet
Stabil? Nej. Inplace? 
d-heap: mer än 2 barn på trädet. dn+1 dn+2 => barn. (4-1)/d => räkna föräldra

==========================
# Vecka 3
## Seminarium A3
Omfattar primärt Countingsort, Radixsort samt tillbakablick/repetition Heapsort och eventuellt viss repetition av innehållet i Del A.

### 1. Countingsort
Princip (olika bearbetningssteg): A är den listan/arrayen som behöver sortera. Skapa 2 listor/array C och D. Max[A] = k. C[0->k+q]. C[A[i]] = C[A[j]+1]. B[C[A[j]]] = A[j]
Vi gör något exempel: 
```
A:  5  4  0  5  5  4  2  0  1

Steg1:
A:  5  4  0  5  5  4  2  0  1
C:  0  0  0  0  0  0

Steg 2:
A:          5  4  0  5  5  4  2  0  1
B:
C:          2  1  1  0  2  3
Index C:    0  1  2  3  4  5 


Steg3:
A:          5  4  0  5  5  4  2  0  1
B: 
C:          2  3  4  4  6  9
Index C:    0  1  2  3  4  5 


Steg 4:
A:          5  4  0  5  5  4  2  0  1
B:          0  0  1  2  4  4  5  5  5
C:          0  2  3  4  4  6    (Minska med 1 först innan man stoppar det på array B)
Index C:    0  1  2  3  4  5 
```

Tidskomplexitet **O(k+n) (k = max)**
Stabil? Ja. **(om man sorterar det bak ifrån bara).**
In-place? Nej, för att det krävs extra minne.

### 2. Bucketsort: 
O(n) i sitt medel/förväntade fall. Delar upp datan i "hinkar" sedan använder elementen som nycklar/index. 
Stabil om den inre sorteringsalgoritmen är stabil. 
Inte in-place, extra minne baseras på k.
Värstafalls O(n^2)

### 3. Radixsort
Princip och ”krav” på nycklarna som ska sorteras: datan är heltal. Sorterar varje siffa för sig: hundra tal, tio tal, en tal... Går från minst signifikanta siffran till den mest signifikanta siffran. Oftast används buckets eller countingsort som subrutin. 
Hur kan countingsort utnyttjas? sorterar varje siffa för sig
Vi gör något exempel
Tidskomplexitet: O(d(n+k))
Stabil? Ja. In-place? Nej.
Bättra val än CountingSort om värdena skalar kvadratiskt gentemot antalet element.
```
A:          02  14  07  10
Index C:    0  1  2  3  4  5  6  7 
C:          1  0  1  0  1  0  0  1

A:          02  14  07  10
Index C:    0  1  2  3  4  5  6  7 
C:          1  1  2  2  3  3  3  4
B:          10  02  14  07


A:          02  14  07  10
Index C:    0  1  
C:          2  2
B:          02  07  10  14

A:          02  14  07  10
Index C:    0  1  
C:          2  4
B:          02  07  10  14
```

### 4. Heapsort
Repeterar kort. När man byggar en max-heap kollar man ner-upp och bytter plats om de behövs.
Vi gör eventuellt något exempel
Radixsort vs Heapsort
d(k+n)  s n(logn)
d=4, k=10, n=500 => Radixsort:T(n)= 2040
                    Heapsort: T(n) = 500(log(500)) = 500.9 = 4500


### 5. Vilken/Vilka är stabila? 
Insertionsort, mergesort, bucketsort, counting sort, radixsort.
Om n=500 och nycklarna är heltal inom [0..9999] vilken av algoritmerna är då teoretiskt ”snabbast”?

6 element eller mindre => insertionsort är snabbare än dem andra.
Hybridsorteringen väljer Mergesort när elementer mer än 6. När kommer elementer mindre än 6 => kör man insertionsort. Sedan samlar man med Merge.

===============
## Seminarium A3: Tillägg (repetition Del A)
1. Bestäm Θ-notationer för funktionerna
```
g(n) = 34.5n2 + 16nlogn + 12 => O(n2)
h(n) = 53.7 => O(1)
f(n) = 4.5 + 8.7logn => O(log n)
```
f(n) = 4.5 + 8.7logn + 5n=> 5n växer snabbare än 8.7log n => O(n)


2. Visa att g(n) = 2n2 + 4n + 10 = Θ(n2) 
```
n >= 4: 4n <= n^2
        10 < n^2 
        2n^2 + 4n + 10 < 4n^2

2n^2 + 4n + 10 >= 1*n^2 
=> g(n) = 2n2 + 4n + 10 = Θ(n2)
```

3. Vid exekvering (värsta fallet) av en algoritm med T(n) =  Ο(n3) tog det 0.5 ms när n=2000. Hur lång tid kommer det då att ta om n ökas till 4000? => 4ms

4. Vid exekvering (värsta fallet) av en algoritm med T(n) =  Ο(log2n) tog det 1 mikrosekund när n=100. Vid en annan exekvering (värsta fallet) av samma algoritm tog det 4 mikrosekunder. Hur var n vid detta tillfälle? => 100^4

5. Anta sekvensen 10 15 22 28 34 45 50 58 60 73 79 85 93 och sökning av elementet 66 utförs enligt algoritmen för binärsökning. Hur många kontrollen/jämförelser görs mot elementet i sekvensen under denna sökning och vilka element kommer att jämföras med 66? 
```
steg 1: 50 => höger
steg 2: 73 => vänster
steg 3: 58 => höger
steg 4: 60 => inte finns 66.
=> 4 jämföras och det är 60 som jämföras med 66.
```

6. Skriv pseudokod för rekursiv binärsökning:
```
BinarySearch(A, x)
low = 0
high = length[A]-1
while low <= high
    mid = (low + high)/2
    if x == A[mid]
        return mid
    if x < A[mid]
        high = mid - 1
    else if x > A[mid]
        low = mid + 1
return -1
```

7. Vilket är värsta fallet för linjärsökning och vilken tidskomplexitet gäller för detta fall? O(n) när den som vi söker ligger i sista plats

8. Visa hur sekvensen 60  20  30  90 10  70 bearbetas om sortering utförs enligt algoritmen 
```
insertionsort: 
60  20  30  90  10  70
20  60  30  90  10  70
20  30  60  90  10  70
20  30  60  90  10  70
10  20  30  60  90  70
10  20  30  60  70  90
```

```
selectionsort: 
10  20  30  90  60  70
10  20  30  90  60  70
10  20  30  90  60  70
10  20  30  60  90  70
10  20  30  60  70  90
```

9. Visa hur sekvensen 60  20  30  90 10  70 40 bearbetas om sortering utförs enligt algoritmen
```
mergesort
60  20  30  90 10  70  40
60  20  30           |        90  10  70  40

60   |    20  30     |      90  10  |    70  40
60   |   20  30      |    10  90    |  40  70
20  30  60           |       10  40  70  90 
10  20  30  40  60  70  90
```

```
quicksort (pivot sista elementet och partitionering enligt Lomutos)
60  20  30  90  10  70  40
20  30  10  40  60  90  70
10  20  30  40  60  70  90
```
```
heapsort
90  60  70  20  10  30  40
40  60  70  20  10  30  90
70  60  40  20  10  30  90
30  60  40  20  10  70  90
60  30  40  20  10  70  90
10  30  40  20  60  70  90
40  30  10  20  60  70  90
20  30  10  40  60  70  90
30  20  10  40  60  70  90
10  20  30  40  60  70  90
```
10. Vilken är tidskomplexiteten O(f(n)) i bästa, genomsnittliga och värsta fallet för quicksort, motivera bästa och värsta fallet? Värsta fallet O(n^2), dålig pivot. Bästa, genomsnittliga: O(nlogn)

11. Skriv pseudokod för heapsort givet algoritmen heapify(A, fromIndex, endIndex) som hanterar att placeras elementet på fromIndex på rätt plats så att innehållet i arrayen A fr.o.m fromIndex motsvarar max-heapar, där förutsättningen är att elementen fr.om fromIndex +1 redan är max-heapar.
```
Heapsort(A)
    for i = Length(A)/2 to 1
        Heapify(A, i, Length(A))
    for i = Length(A) to 1
        Swap(A[1], A[i])
        Heapify(A, 1, i-1)
        
Heapify(A, i, n)
    max = i
    leftchild = 2 * i
    rightchild = 2 * i + 1

    if (leftchild <= n) and (A[leftchild] > A[max])
        max = leftchild
    if (rightchild <= n) and (A[rightchild] > A[max])
        max = rightchild

    if (max != i)
        Swap(A[i], A[max])
        Heapify(A, max, n)
```

=============================
# Vecka 4
## Seminarium B1
- Omfattar primärt  Länkade listor samt Stack och Kö.

### 1. Länkade listor

- Ett altenativ till arrayer för att lagra data. Data-objekt (noder) länkas ihop istället för att ligga fi följd i minnet.

✅ 1. Länkade listor
🔸 Länkalternativ:
Enkellänkning: Varje nod har en pekare till nästa nod.
Dubbellänkning: Varje nod har två pekare – en till nästa nod och en till föregående.

🔸 Klasstyp för att representera list-element:
plaintext
Copy
Edit
class Node:
    data        // det som ska lagras
    next        // pekare till nästa list-element

    constructor(data, next):
        this.data = data
        this.next = next
🔸 Uppbyggnad:
Start-element: Pekare till det första elementet i listan (vanligtvis kallad head)

Slut-element: Det sista elementet vars next är null

Cirkulär lista: Det sista elementets next pekar tillbaka på det första elementet (head), vilket skapar en sluten cirkel

✅ Pseudo-kod för enkellänkad lista
1. Lägg till ett element först i listan
plaintext
Copy
Edit
function insertFirst(head, data):
    newNode = Node(data, head)
    return newNode
Tidskomplexitet: O(1)

2. Bestäm antalet element i listan
plaintext
Copy
Edit
function countElements(head):
    count = 0
    current = head
    while current != null:
        count = count + 1
        current = current.next
    return count
Tidskomplexitet: O(n)

3. Lägg till ett element på en viss position
plaintext
Copy
Edit
function insertAt(head, position, data):
    if position == 0:
        return insertFirst(head, data)

    current = head
    index = 0
    while current != null and index < position - 1:
        current = current.next
        index = index + 1

    if current == null:
        error("Position out of bounds")

    newNode = Node(data, current.next)
    current.next = newNode
    return head
Tidskomplexitet: O(n)

4. Ta bort ett element från listan givet positionen
plaintext
Copy
Edit
function removeAt(head, position):
    if head == null:
        error("List is empty")

    if position == 0:
        return head.next

    current = head
    index = 0
    while current != null and index < position - 1:
        current = current.next
        index = index + 1

    if current == null or current.next == null:
        error("Position out of bounds")

    current.next = current.next.next
    return head
Tidskomplexitet: O(n)



### 2. Stack 

Operationer
#### 2.1. Alternativ på intern datastruktur: 

En stack kan implementeras med:

Array (statisk storlek) – snabb tillgång men begränsad kapacitet.

Dynamisk array (t.ex. vector i C++) – flexibel storlek.

Länkad lista – dynamisk, effektiv för minnesanvändning.


#### 2.2. Tidskomplexitet för operationerna
🔸 Tidskomplexitet för operationerna (generellt):

Operation	Tidskomplexitet
push(x)	O(1)
pop()	O(1)
peek() eller top()	O(1)
isEmpty()	O(1)

#### 2.3. 
Anta att du har tillgång till ADT:n Stack och att följande operationer utförs på en från början tom stack 

push(V), push(X), push(R), push(Z)
output result of peek() => Z
push(H)
output result of peek() => H
pop(), pop()
output result of peek() => R
pop()
output result of peek() => X

Vilken utskriften erhålls av ovan pseudokod om output result of resulterar i utskrift?

#### 2.4. Använd ADT:n Stack för att vända om innehållet i en array givet arrayen och dess kapacitet. Skriv bearbetningen i pseudokod.

- Antag:

    - arr är en array av storlek n

    - stack är en tom stack
```
function reverseArray(arr, n):
    stack = Stack()

    // Push all elements to stack
    for i = 0 to n - 1:
        stack.push(arr[i])

    // Pop elements back into array
    for i = 0 to n - 1:
        arr[i] = stack.pop()
```


### 3.Kö

- Operationer
🔸 ADT-operationer:

Operation	Beskrivning
enqueue(x)	Lägger till ett element längst bak i kön
dequeue()	Tar bort och returnerar elementet längst fram
peek() / front()	Returnerar det första elementet utan att ta bort det
isEmpty()	Returnerar true om kön är tom

#### 3.1 Alternativ på intern datastruktur
- Array (cirkulär array) – snabba operationer, kräver spårning av front och rear.

- Dynamisk array (t.ex. vector) – flexibel storlek, men kräver skiftning vid dequeue().

- Länkad lista – enkel hantering av dynamisk storlek, O(1) för båda operationerna
#### 3.2 Tidskomplexitet för operationerna
✅ Tidskomplexitet (för en korrekt implementerad kö):

Operation	Tidskomplexitet
enqueue(x)	O(1)
dequeue()	O(1)
peek()	O(1)
isEmpty()	O(1)
(Om man använder vector utan optimering, kan dequeue() bli O(n) pga skiftning.)
#### 3.3. Anta att ADT:n Kö (Queue) implementerats genom användande av en array med kapaciteten 6 (indexeringen börjar på 0). Alla operationer som utförs på kön tar konstant tid.
Om följande operationer utförs i den ordning de är angivna:

enqueue(A), enqueue(B), enqueue(C), enqueue(D), 
dequeue(), dequeue(), dequeue(),
enqueue(E), enqueue(F), 
dequeue(), dequeue(), 
enqueue(G), enqueue(H) 


Vilket är innehållet i arrayen efter det att alla operationerna är genomförda?

📦 Start: [ _ _ _ _ _ _ ] (kapacitet 6)
Vi antar en cirkulär kö där front och rear flyttas och wrappar runt vid behov.


Steg	Operation	Front	Rear	Innehåll i array (index 0–5)
1	enqueue(A)	0	0	[A _ _ _ _ _]
2	enqueue(B)	0	1	[A B _ _ _ _]
3	enqueue(C)	0	2	[A B C _ _ _]
4	enqueue(D)	0	3	[A B C D _ _]
5	dequeue()	1	3	[A B C D _ _] (A tas bort, ignoreras)
6	dequeue()	2	3	[A B C D _ _] (B tas bort)
7	dequeue()	3	3	[A B C D _ _] (C tas bort)
8	enqueue(E)	3	4	[A B C D E _]
9	enqueue(F)	3	5	[A B C D E F]
10	dequeue()	4	5	[A B C D E F] (D tas bort)
11	dequeue()	5	5	[A B C D E F] (E tas bort)
12	enqueue(G)	5	0	[G B C D E F] (rear wrappar till 0)
13	enqueue(H)	5	1	[G H C D E F] (rear till index 1)
❗ Observera att de borttagna värdena (t.ex. A, B, C...) tekniskt finns kvar i arrayen, men anses inte längre vara en del av kön eftersom front har flyttats.
✅ Slutligt innehåll i arrayen (positioner 0–5):
plaintext
Copy
Edit
[G, H, C, D, E, F]  
Men det aktuella innehållet i kön, i rätt ordning, är:

plaintext
Copy
Edit
F, G, H
(Med front på index 5 och rear på index 1 – cirkulär hantering.)

#### 3.4. Skriv pseudokod för alla operationerna som ingår i ADT:n Queue där du ska använda ADT:n Vector som intern datastruktur. Vectorn (vars positioner börjar på 0) har följande operationer
addAt(elem, pos) - lägger till elem på positionen pos
size() - ger antalet element i listan
remove(pos) - tar bort elementet på positionen pos 
find(elem) - returnerar den position som elem finns på, men om elem inte finns returneras 



Antag att vi använder en ADT Vector med:

addAt(elem, pos)

remove(pos)

size()

find(elem)
```
Klass: Queue
plaintext
Copy
Edit
class Queue:
    vector = new Vector()

    function enqueue(elem):
        vector.addAt(elem, vector.size())   // lägg till sist

    function dequeue():
        if isEmpty():
            error("Queue is empty")
        vector.remove(0)                    // ta bort först

    function peek():
        if isEmpty():
            error("Queue is empty")
        return vector[0]

    function isEmpty():
        return vector.size() == 0
```