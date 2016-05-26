# Programmieraufgabe 5
    Robert Wettstädt 535161
    Sona Pecenakova 540607

### 1. Implementieren Sie HeapSort. Vergleichen Sie die Laufzeit Ihrer Implementierung, angewendet auf zufällige Listen, mit der Laufzeit der Implementierung von Quicksort aus der Lehrveranstaltung (oder Ihrer eigenen Implementierung aus Hausaufgabe 4).
	Code: sort.c
	Methode: *hSort
	
####Aufruf:
```bash
./sort
```

####Test:
```
~~~~= Arraysize 10 =~~~~

  ~~= Random Array =~~
[ 342 832 899 523 633 558 574 637 80 693 ]

Heapsort:
[ 80 342 523 558 574 633 637 693 832 899 ]

  ~~= Presorted Array =~~
Heapsort:
[ 80 342 523 558 574 633 637 693 832 899 ]
```

####Laufzeiten für einen Lauf
```
~~~~= Arraysize 10 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.000001 seconds and 22 comparisons
Insertion done in 0.000001 seconds and 32 comparisons
Mergesort done in 0.000003 seconds and 23 comparisons
Quicksort done in 0.000001 seconds and 8 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000000 seconds and 22 comparisons
Insertion done in 0.000000 seconds and 10 comparisons
Mergesort done in 0.000001 seconds and 19 comparisons
Quicksort done in 0.000000 seconds and 9 comparisons


~~~~= Arraysize 100 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.000012 seconds and 675 comparisons
Insertion done in 0.000011 seconds and 2787 comparisons
Mergesort done in 0.000023 seconds and 539 comparisons
Quicksort done in 0.000008 seconds and 175 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000012 seconds and 675 comparisons
Insertion done in 0.000001 seconds and 100 comparisons
Mergesort done in 0.000019 seconds and 359 comparisons
Quicksort done in 0.000013 seconds and 94 comparisons


~~~~= Arraysize 1000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.000193 seconds and 11711 comparisons
Insertion done in 0.000746 seconds and 249360 comparisons
Mergesort done in 0.000219 seconds and 8673 comparisons
Quicksort done in 0.000108 seconds and 2479 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000171 seconds and 11711 comparisons
Insertion done in 0.000008 seconds and 1000 comparisons
Mergesort done in 0.000182 seconds and 5216 comparisons
Quicksort done in 0.000831 seconds and 803 comparisons


~~~~= Arraysize 10000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.002251 seconds and 166410 comparisons
Insertion done in 0.077187 seconds and 25054832 comparisons
Mergesort done in 0.002386 seconds and 120436 comparisons
Quicksort done in 0.001045 seconds and 35728 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.002145 seconds and 166410 comparisons
Insertion done in 0.000043 seconds and 10000 comparisons
Mergesort done in 0.001873 seconds and 73102 comparisons
Quicksort done in 0.033853 seconds and 13983 comparisons


~~~~= Arraysize 100000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.027329 seconds and 2160845 comparisons
Insertion done in 7.761559 seconds and 2499838618 comparisons
Mergesort done in 0.026674 seconds and 1535870 comparisons
Quicksort done in 0.011484 seconds and 505711 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.027130 seconds and 2160845 comparisons
Insertion done in 0.000446 seconds and 100000 comparisons
Mergesort done in 0.021126 seconds and 916684 comparisons
Quicksort done in 0.705482 seconds and 282310 comparisons
```


####Über 5 Laüfe gemittelte Laufzeiten und Vergleichen:
```
Average run times on random arrays:
Heapsort:  0.030341 seconds
Insertion: 7.783212 seconds
Mergesort: 0.030228 seconds
Quicksort: 0.012891 seconds

Average run times on presorted arrays:
Heapsort:  0.030404 seconds
Insertion: 0.000517 seconds
Mergesort: 0.023682 seconds
Quicksort: 0.745334 seconds

Average comparisons on random arrays:
Heapsort:  2338866 comparisons
Insertion: 2526114463 comparisons
Mergesort: 1665865 comparisons
Quicksort: 544976 comparisons

Average comparisons on presorted arrays:
Heapsort:  2338866 comparisons
Insertion: 111110 comparisons
Mergesort: 992813 comparisons
Quicksort: 297290 comparisons
```

- Man sieht, dass die Laufzeit von dem Heapsort vergleichbar mit den Laufzeiten von Mergesort Algorithmus sind, sowohl auf Random Arrays als auch auf presortierten Arrays
- Die Anzahl von durchgeführten Vergleichen ist allerdings höher als bei MergeSort. Das heißt, der Algorithmus kann mehrere Vergleichen durchführen in vergleichbaren Zeit
- Quicksort ist besser als Heapsort bei random Arrays, dabei aber wesentlich schlechter bei sortierten Arrays
- Bei Heapsort bleibt die Anzahl von Vergleichen gleich und die Zeit aehnlich bei den random und sortierten Arrays 

### 2. Schreiben Sie ein Programm, mit dem Sie ein Textfile Huffman-codieren können. Welche Reduktion der Filegröße erreichen Sie damit? (Sie sollten Ihr Programm testen, indem Sie einen Text codieren, wieder dekodieren und überprüfen, ob Sie damit wieder den Auggangstext erhalten.)