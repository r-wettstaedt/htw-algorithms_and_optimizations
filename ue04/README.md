#Programmieraufgabe 4
    Robert Wettstädt 535161
    Sona Pecenakova 540607


###1. Implementieren Sie die Sortieralgorithmen
	Code: sort.c
	
####Aufruf:
```bash
./sort
```

####Test:
```
~~~~= Arraysize 10 =~~~~

  ~~= Random Array =~~
[ 830 15 659 543 314 275 968 326 112 327 ]

Insertionsort
[ 15 112 275 314 326 327 543 659 830 968 ]
Mergesort
[ 15 112 275 314 326 327 543 659 830 968 ]
Quicksort
[ 15 112 275 314 326 327 543 659 830 968 ]

  ~~= Presorted Array =~~
Insertionsort
[ 15 112 275 314 326 327 543 659 830 968 ]
Mergesort
[ 15 112 275 314 326 327 543 659 830 968 ]
Quicksort
[ 15 112 275 314 326 327 543 659 830 968 ]
```



###2. Messen Sie die (über mehrere Läufe gemittelten) Laufzeiten dieser Algorithmen für zufällig erzeugte Listen ganzer Zahlen verschiedener Längen.

####Laufzeiten für einen Lauf
```
~~~~= Arraysize 10 =~~~~

  ~~= Random Array =~~
Insertion done in 0.000001 seconds and 33 comparisons
Mergesort done in 0.000002 seconds and 24 comparisons
Quicksort done in 0.000001 seconds and 9 comparisons

  ~~= Presorted Array =~~
Insertion done in 0.000001 seconds and 10 comparisons
Mergesort done in 0.000002 seconds and 19 comparisons
Quicksort done in 0.000001 seconds and 9 comparisons


~~~~= Arraysize 100 =~~~~

  ~~= Random Array =~~
Insertion done in 0.000008 seconds and 2190 comparisons
Mergesort done in 0.000018 seconds and 551 comparisons
Quicksort done in 0.000007 seconds and 152 comparisons

  ~~= Presorted Array =~~
Insertion done in 0.000001 seconds and 100 comparisons
Mergesort done in 0.000021 seconds and 360 comparisons
Quicksort done in 0.000018 seconds and 94 comparisons


~~~~= Arraysize 1000 =~~~~

  ~~= Random Array =~~
Insertion done in 0.000776 seconds and 256688 comparisons
Mergesort done in 0.000228 seconds and 8697 comparisons
Quicksort done in 0.000107 seconds and 2372 comparisons

  ~~= Presorted Array =~~
Insertion done in 0.000007 seconds and 1000 comparisons
Mergesort done in 0.000181 seconds and 5242 comparisons
Quicksort done in 0.000836 seconds and 816 comparisons


~~~~= Arraysize 10000 =~~~~

  ~~= Random Array =~~
Insertion done in 0.076856 seconds and 24912857 comparisons
Mergesort done in 0.002808 seconds and 120423 comparisons
Quicksort done in 0.001068 seconds and 35556 comparisons

  ~~= Presorted Array =~~
Insertion done in 0.000045 seconds and 10000 comparisons
Mergesort done in 0.001916 seconds and 73379 comparisons
Quicksort done in 0.034230 seconds and 14021 comparisons


~~~~= Arraysize 100000 =~~~~

  ~~= Random Array =~~
Insertion done in 7.746232 seconds and 2506041110 comparisons
Mergesort done in 0.029859 seconds and 1536078 comparisons
Quicksort done in 0.012542 seconds and 506314 comparisons

  ~~= Presorted Array =~~
Insertion done in 0.000461 seconds and 100000 comparisons
Mergesort done in 0.022008 seconds and 915899 comparisons
Quicksort done in 0.705005 seconds and 282178 comparisons
```

####Über 5 Laüfe gemittelte Laufzeiten:
```
Average run time on random arrays:
Insertion: 7.555748 seconds
Mergesort: 0.031240 seconds
Quicksort: 0.012234 seconds

Average run time on presorted arrays:
Insertion: 0.000456 seconds
Mergesort: 0.024142 seconds
Quicksort: 0.743308 seconds
```

###3. Vergleichen Sie die Laufzeiten mit den theoretisch ermittelten mittleren Anzahlen von Vergleichen, die in den Algorithmen vorgenommen werden.
```
Average comparisons on random arrays:
Insertion: 2530972413 comparisons
Mergesort: 1665706 comparisons
Quicksort: 544744 comparisons

Average comparisons on presorted arrays:
Insertion: 111110 comparisons
Mergesort: 991530 comparisons
Quicksort: 297219 comparisons
```

- Man sieht, dass die durchschnittliche Laufzeiten in machen Fällen mit der Anzahl der durchschnittlichen Vergleichen zusammenhägen
- Z.B dauert der Insertion-Sort auf random array am längsten und hat auch die größeste Anzahl an Vergleichen
- Anderseits, sieht man bei dem Merge-Sort keine Beziehung zwischen den Daten

###4. Was geschieht, wenn man die Algorithmen auf die sortierte Liste 0, 1, 2, ... n – 1 anwendet?
- Man kann von den gemittelten Laufzeiten sehen, dass z.B. Insertionsort, der relativ langsam auf den Random Arrays ist, sehr schnell die sortierten Listen durchlaufen kann.
- Im Gegenfall, ist Quicksort sehr schnell auf random arrays aber langsamer auf sortierten arrays

###5. Stellen Sie Ihre Ergebnisse in einem Diagramm dar (x-Achse Eingabegröße n, y-Achse Laufzeiten bzw. Anzahlen der Vergleiche).