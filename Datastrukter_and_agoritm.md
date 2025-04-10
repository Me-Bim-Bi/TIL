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
1. Vilken tidskomplexitet har linjärsökning i värsta/sämsta fallet? 
- I bästa fall hittar man elementet direkt (första platsen) → O(1)
- I genomsnitt måste man gå igenom hälften av elementen → O(n)
- I värsta fallet finns inte elementet i listan, eller ligger sist → O(n)

2. Vilken tidskomplexitet har binärsökning i värsta/sämsta fallet?
- Bästa fall: Elementet finns mitt i → O(1)
- Värsta fall: Elementet finns inte eller är i ytterkant → O(log n)

3. Vilket krav ställs på den sekvens av element som binärsökningen ska genomföras på? Sorterad

4. Kan linjärsökning vara snabbare än binärsökning? Motivera ditt svar? Ja.Om det element som söks är placerat först.

5. Anta en sorterad array med 350 element (indexerad fr.o.m 0) och att det element som söks finns
i den tredje fjärdedelen av arrayen. Vilka index motsvarande startindex, slutindex samt mittindex
kommer binärsökning att generera för den delsekvens som motsvarar den aktuella fjärdedelen? 
- Step 1: 0

6. Om tidskomplexiteten för en algoritm är T(n) kvadratisk, dvs cn2
, och det vid exekvering med
1000 element tog 2 mikrosekunder. Vilket är då värdet på ’c’?
7. Anta att det tar 3 ms att exekvera linjärsökning i värsta fallet i en array innehållande 3000
element.
a. Hur lång tid förväntas det då ta om antalet ökas till 12000?
i. ca 4 ms
ii. ca 6 ms
iii. ca 12 ms
b. Om det vid en annan exekvering tog 9 ms, hur många element innehöll i så fall arrayen?
8. Anta att det tar 3 ms att exekvera binärsökning för värsta fallet i en array innehållande 3000
element.
a. Om det vid en annan exekvering tog 9 ms, hur många element innehöll i så fall arrayen?
b. För vilket antal element, dvs värde på n, kommer det att ta 1 ms?
9. Uttryck n3
/5+21n2
-14n+3 i Θ-notation
10. Är 2 n+1 = O(2n )? Är 2 2n = O(2 n )?
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
13. Vilken tidskomplexitet har Selectionsort i värsta fallet?
14. Visa hur innehållet i arrayen nedan sorteras med insertionsort resp selectionsort
a)
b)
15. Anta funktionen f(n) =7n3 – 5n2 + 20n. Nedan följer några påståenden avseende hur funktionen
växer beroende på n.
a. f(n) = O(n4
)
b. f(n) = O(n2
)
c. f(n) = Ω(n2
)
d. f(n) = Ω(n)
e. f(n) = Θ(n3
)
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
Stabil? Inplace?: 
d-heap: mer än 2 barn på trädet. dn+1 dn+2 => barn. (4-1)/d => räkna föräldra