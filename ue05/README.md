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
[ 621 675 54 936 121 868 352 362 133 468 ]
Heapsort  done in 0.000002 seconds and 68 comparisons
[ 54 121 133 352 362 468 621 675 868 936 ]
Insertion done in 0.000001 seconds and 34 comparisons
Mergesort done in 0.000002 seconds and 24 comparisons
Quicksort done in 0.000001 seconds and 11 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000002 seconds and 68 comparisons
[ 54 121 133 352 362 468 621 675 868 936 ]
Insertion done in 0.000002 seconds and 10 comparisons
Mergesort done in 0.000002 seconds and 19 comparisons
Quicksort done in 0.000000 seconds and 9 comparisons


~~~~= Arraysize 100 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.000014 seconds and 1260 comparisons
Insertion done in 0.000013 seconds and 2375 comparisons
Mergesort done in 0.000029 seconds and 545 comparisons
Quicksort done in 0.000010 seconds and 156 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000011 seconds and 1260 comparisons
Insertion done in 0.000002 seconds and 100 comparisons
Mergesort done in 0.000015 seconds and 356 comparisons
Quicksort done in 0.000013 seconds and 95 comparisons


~~~~= Arraysize 1000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.000171 seconds and 19120 comparisons
Insertion done in 0.000793 seconds and 257296 comparisons
Mergesort done in 0.000232 seconds and 8713 comparisons
Quicksort done in 0.000105 seconds and 2508 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000174 seconds and 19120 comparisons
Insertion done in 0.000007 seconds and 1000 comparisons
Mergesort done in 0.000190 seconds and 5252 comparisons
Quicksort done in 0.000871 seconds and 836 comparisons


~~~~= Arraysize 10000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.002173 seconds and 258084 comparisons
Insertion done in 0.081847 seconds and 24905013 comparisons
Mergesort done in 0.002489 seconds and 120501 comparisons
Quicksort done in 0.000989 seconds and 35914 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.002039 seconds and 258084 comparisons
Insertion done in 0.000067 seconds and 10000 comparisons
Mergesort done in 0.001856 seconds and 73151 comparisons
Quicksort done in 0.036401 seconds and 14020 comparisons


~~~~= Arraysize 100000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.029935 seconds and 3247772 comparisons
Insertion done in 7.831078 seconds and 2509690044 comparisons
Mergesort done in 0.028535 seconds and 1536058 comparisons
Quicksort done in 0.011608 seconds and 510230 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.027648 seconds and 3247772 comparisons
Insertion done in 0.000528 seconds and 100000 comparisons
Mergesort done in 0.022998 seconds and 908286 comparisons
Quicksort done in 0.749236 seconds and 282331 comparisons
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


### 2. Schreiben Sie ein Programm, mit dem Sie ein Textfile Huffman-codieren können. Welche Reduktion der Filegröße erreichen Sie damit? (Sie sollten Ihr Programm testen, indem Sie einen Text codieren, wieder dekodieren und überprüfen, ob Sie damit wieder den Auggangstext erhalten.)