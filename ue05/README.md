# Programmieraufgabe 5
    Robert Wettstädt 535161
    Sona Pecenakova 540607

### 1. Implementieren Sie HeapSort. Vergleichen Sie die Laufzeit Ihrer Implementierung, angewendet auf zufällige Listen, mit der Laufzeit der Implementierung von Quicksort aus der Lehrveranstaltung (oder Ihrer eigenen Implementierung aus Hausaufgabe 4).
```
~~~~= Arraysize 10 =~~~~

  ~~= Random Array =~~
  Heapsort     done in 4209µs   | 41 modifications
  Quicksort     done in 4618µs  | 11 modifications

  ~~= Presorted Array =~~
  Heapsort     done in 4058µs   | 43 modifications
  Quicksort     done in 717µs   | 9 modifications


~~~~= Arraysize 100 =~~~~

  ~~= Random Array =~~
  Heapsort     done in 545µs    | 727 modifications
  Quicksort     done in 303µs   | 161 modifications

  ~~= Presorted Array =~~
  Heapsort     done in 859µs    | 788 modifications
  Quicksort     done in 842µs   | 93 modifications


~~~~= Arraysize 1.000 =~~~~

  ~~= Random Array =~~
  Heapsort     done in 7574µs   | 10568 modifications
  Quicksort     done in 1950µs  | 2402 modifications

  ~~= Presorted Array =~~
  Heapsort     done in 5113µs   | 11199 modifications
  Quicksort     done in 31ms    | 820 modifications


~~~~= Arraysize 10.000 =~~~~

  ~~= Random Array =~~
  Heapsort     done in 93ms     | 139148 modifications
  Quicksort     done in 18ms    | 35383 modifications

  ~~= Presorted Array =~~
  Heapsort     done in 87ms     | 145246 modifications
  Quicksort     done in 1026ms  | 14038 modifications


~~~~= Arraysize 100.000 =~~~~

  ~~= Random Array =~~
  Heapsort     done in 873ms    | 1723694 modifications
  Quicksort     done in 256ms   | 505579 modifications

  ~~= Presorted Array =~~
  Heapsort     done in 816ms    | 1617388 modifications
  Quicksort     done in 19s     | 282408 modifications
```


### 2. Schreiben Sie ein Programm, mit dem Sie ein Textfile Huffman-codieren können. Welche Reduktion der Filegröße erreichen Sie damit? (Sie sollten Ihr Programm testen, indem Sie einen Text codieren, wieder dekodieren und überprüfen, ob Sie damit wieder den Auggangstext erhalten.)