# Programmieraufgabe 5
    Robert Wettstädt 535161
    Sona Pecenakova 540607

### 1. Implementieren Sie HeapSort. Vergleichen Sie die Laufzeit Ihrer Implementierung, angewendet auf zufällige Listen, mit der Laufzeit der Implementierung von Quicksort aus der Lehrveranstaltung (oder Ihrer eigenen Implementierung aus Hausaufgabe 4).
	Code: sort.c
	
####Aufruf:
```bash
./sort
```

####Test:
```
~~~~= Arraysize 10 =~~~~

 ~~= Random Array =~~
[ 884 622 182 270 256 22 248 382 558 26 ]

Heapsort:
[ 22 26 182 248 256 270 382 558 622 884 ]

  ~~= Presorted Array =~~
Heapsort:
[ 22 26 182 248 256 270 382 558 622 884 ]
```

####Laufzeiten für einen Lauf
```
~~~~= Arraysize 10 =~~~~

  ~~= Random Array =~~
[ 480 249 507 957 740 63 777 360 149 758 ]
Heapsort  done in 0.000002 seconds and 22 comparisons
[ 63 149 249 360 480 507 740 758 777 957 ]
Insertion done in 0.000001 seconds and 32 comparisons
Mergesort done in 0.000002 seconds and 24 comparisons
Quicksort done in 0.000000 seconds and 10 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000002 seconds and 22 comparisons
[ 63 149 249 360 480 507 740 758 777 957 ]
Insertion done in 0.000001 seconds and 10 comparisons
Mergesort done in 0.000001 seconds and 19 comparisons
Quicksort done in 0.000001 seconds and 9 comparisons


~~~~= Arraysize 100 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.000013 seconds and 653 comparisons
Insertion done in 0.000011 seconds and 2665 comparisons
Mergesort done in 0.000028 seconds and 534 comparisons
Quicksort done in 0.000010 seconds and 171 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000014 seconds and 653 comparisons
Insertion done in 0.000001 seconds and 100 comparisons
Mergesort done in 0.000021 seconds and 358 comparisons
Quicksort done in 0.000017 seconds and 96 comparisons


~~~~= Arraysize 1000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.000189 seconds and 11656 comparisons
Insertion done in 0.000883 seconds and 242864 comparisons
Mergesort done in 0.000249 seconds and 8689 comparisons
Quicksort done in 0.000130 seconds and 2466 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000169 seconds and 11656 comparisons
Insertion done in 0.000008 seconds and 1000 comparisons
Mergesort done in 0.000217 seconds and 5262 comparisons
Quicksort done in 0.000879 seconds and 811 comparisons


~~~~= Arraysize 10000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.002117 seconds and 165995 comparisons
Insertion done in 0.074943 seconds and 25016453 comparisons
Mergesort done in 0.002421 seconds and 120471 comparisons
Quicksort done in 0.001025 seconds and 35946 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.001978 seconds and 165995 comparisons
Insertion done in 0.000043 seconds and 10000 comparisons
Mergesort done in 0.001891 seconds and 73493 comparisons
Quicksort done in 0.033785 seconds and 14066 comparisons


~~~~= Arraysize 100000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.025421 seconds and 2159924 comparisons
Insertion done in 7.811294 seconds and 2501311994 comparisons
Mergesort done in 0.028097 seconds and 1536161 comparisons
Quicksort done in 0.012201 seconds and 510384 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.028437 seconds and 2159924 comparisons
Insertion done in 0.000440 seconds and 100000 comparisons
Mergesort done in 0.022067 seconds and 915912 comparisons
Quicksort done in 0.719735 seconds and 282381 comparisons
```


####Über 5 Laüfe gemittelte Laufzeiten und Vergleichen:
```
Average run times on random arrays:
Heapsort:  0.030832 seconds
Insertion: 8.057698 seconds
Mergesort: 0.031792 seconds
Quicksort: 0.012531 seconds

Average run times on presorted arrays:
Heapsort:  0.028961 seconds
Insertion: 0.000542 seconds
Mergesort: 0.024025 seconds
Quicksort: 0.760987 seconds

Average comparisons on random arrays:
Heapsort:  3526136 comparisons
Insertion: 2525274195 comparisons
Mergesort: 1665797 comparisons
Quicksort: 546114 comparisons

Average comparisons on presorted arrays:
Heapsort:  3526136 comparisons
Insertion: 111110 comparisons
Mergesort: 991275 comparisons
Quicksort: 297300 comparisons
```

- Man sieht, dass die Laufzeit von dem Heapsort vergleichbar mit den Laufzeiten von Mergesort Algorithmus sind, sowohl auf Random Arrays als auch auf presortierten Arrays
- Die Anzahl von durchgeführten Vergleichen ist allerdings viel höher als bei MergeSort. Das heißt, der Algorithmus kann mehrere Vergleichen durchführen in vergleichbaren Zeit
- Die Anzahl von Vergleichen bleibt dabei gleich wenn es auf random arrays angewendet wird als die auf sortierten Arrays
 

### 2. Schreiben Sie ein Programm, mit dem Sie ein Textfile Huffman-codieren können. Welche Reduktion der Filegröße erreichen Sie damit? (Sie sollten Ihr Programm testen, indem Sie einen Text codieren, wieder dekodieren und überprüfen, ob Sie damit wieder den Auggangstext erhalten.)