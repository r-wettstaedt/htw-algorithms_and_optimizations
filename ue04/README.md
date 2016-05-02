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
Insertion done in 0.000003 seconds
Mergesort done in 0.000002 seconds
Quicksort done in 0.000002 seconds

  ~~= Presorted Array =~~
Insertion done in 0.000000 seconds
Mergesort done in 0.000001 seconds
Quicksort done in 0.000001 seconds


~~~~= Arraysize 100 =~~~~

  ~~= Random Array =~~
Insertion done in 0.000011 seconds
Mergesort done in 0.000048 seconds
Quicksort done in 0.000010 seconds

  ~~= Presorted Array =~~
Insertion done in 0.000001 seconds
Mergesort done in 0.000021 seconds
Quicksort done in 0.000016 seconds


~~~~= Arraysize 1000 =~~~~

  ~~= Random Array =~~
Insertion done in 0.000849 seconds
Mergesort done in 0.000249 seconds
Quicksort done in 0.000123 seconds

  ~~= Presorted Array =~~
Insertion done in 0.000006 seconds
Mergesort done in 0.000194 seconds
Quicksort done in 0.000891 seconds


~~~~= Arraysize 10000 =~~~~

  ~~= Random Array =~~
Insertion done in 0.072222 seconds
Mergesort done in 0.002420 seconds
Quicksort done in 0.001004 seconds

  ~~= Presorted Array =~~
Insertion done in 0.000041 seconds
Mergesort done in 0.001907 seconds
Quicksort done in 0.034848 seconds


~~~~= Arraysize 100000 =~~~~

  ~~= Random Array =~~
Insertion done in 7.497361 seconds
Mergesort done in 0.029497 seconds
Quicksort done in 0.010858 seconds

  ~~= Presorted Array =~~
Insertion done in 0.000441 seconds
Mergesort done in 0.020837 seconds
Quicksort done in 0.704434 seconds
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

###4. Was geschieht, wenn man die Algorithmen auf die sortierte Liste 0, 1, 2, ... n – 1 anwendet?
- Man kann von den gemittelten Laufzeiten sehen, dass z.B. Insertionsort, der relativ langsam auf den Random Arrays ist, sehr schnell die sortierten Listen durchlaufen kann.
- Im Gegenfall, ist Quicksort sehr schnell auf random arrays aber langsamer auf sortierten arrays

###5. Stellen Sie Ihre Ergebnisse in einem Diagramm dar (x-Achse Eingabegröße n, y-Achse Laufzeiten bzw. Anzahlen der Vergleiche).