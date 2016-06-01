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
Quicksort done in 0.000001 seconds and 8 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000000 seconds and 22 comparisons
Quicksort done in 0.000000 seconds and 9 comparisons


~~~~= Arraysize 100 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.000012 seconds and 675 comparisons
Quicksort done in 0.000008 seconds and 175 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000012 seconds and 675 comparisons
Quicksort done in 0.000013 seconds and 94 comparisons


~~~~= Arraysize 1000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.000193 seconds and 11711 comparisons
Quicksort done in 0.000108 seconds and 2479 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.000171 seconds and 11711 comparisons
Quicksort done in 0.000831 seconds and 803 comparisons


~~~~= Arraysize 10000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.002251 seconds and 166410 comparisons
Quicksort done in 0.001045 seconds and 35728 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.002145 seconds and 166410 comparisons
Quicksort done in 0.033853 seconds and 13983 comparisons


~~~~= Arraysize 100000 =~~~~

  ~~= Random Array =~~
Heapsort  done in 0.027329 seconds and 2160845 comparisons
Quicksort done in 0.011484 seconds and 505711 comparisons

  ~~= Presorted Array =~~
Heapsort  done in 0.027130 seconds and 2160845 comparisons
Quicksort done in 0.705482 seconds and 282310 comparisons
```


####Über 5 Laüfe gemittelte Laufzeiten und Vergleichen:
```
Average run times on random arrays:
Heapsort:  0.030341 seconds
Quicksort: 0.012891 seconds

Average run times on presorted arrays:
Heapsort:  0.030404 seconds
Quicksort: 0.745334 seconds

Average comparisons on random arrays:
Heapsort:  2338866 comparisons
Quicksort: 544976 comparisons

Average comparisons on presorted arrays:
Heapsort:  2338866 comparisons
Quicksort: 297290 comparisons
```

- Quicksort ist besser als Heapsort bei random Arrays, dabei aber wesentlich schlechter bei sortierten Arrays
- Bei Heapsort bleibt die Anzahl von Vergleichen gleich und die Zeit aehnlich bei den random und sortierten Arrays 

### 2. Schreiben Sie ein Programm, mit dem Sie ein Textfile Huffman-codieren können. Welche Reduktion der Filegröße erreichen Sie damit? (Sie sollten Ihr Programm testen, indem Sie einen Text codieren, wieder dekodieren und überprüfen, ob Sie damit wieder den Auggangstext erhalten.)

    Code: huffman.c

####Reduktion von Filegröße
```
Original bits = 664
Compressed bits = 349
Saved 52.56% of memory

Original size = 83 bytes
Compressed size = 44 bytes

```
####Test
Original File: text.txt
```
this is an exercise for the course algorithms that we are taking in our university
```

CodeTable:
```
u: 00000
c: 00001
h: 0001
r: 0010
s: 0011
e: 010
 : 011
n: 1000
b: 100100
x: 100101000
z: 100101001
j: 100101010
q: 1001010110
k: 1001010111
v: 1001011
p: 100110
y: 100111
i: 1010
o: 1011
a: 1100
l: 11010
d: 11011
g: 111000
f: 111001
w: 111010
m: 111011
t: 1111
```

CompressedFile: compressedFile.txt
```
0000000: 11110001 10100011 01110100 01101111 00100001 10101001  ..to!.
0000006: 01000010 00100000 11010001 10100111 11001101 10010011  B ....
000000c: 11110001 01001100 00110110 00000010 00110100 11110011  .L6.4.
0000012: 01011100 01011001 01010111 10001111 01100110 11111100  \YW.f.
0000018: 01110011 11011111 01001001 11100001 00100111 11111001  s.I.'.
000001e: 00101011 11010100 01110000 11101010 00011101 10000000  +.p...
0000024: 10011000 00100010 10100101 10100010 00111010 11111001  ."..:.
000002a: 11110110 11111000                                      ..
```

DecompressedFile: decompressedFile.txt
```
this is an exercise for the course algorithms that we are taking in our universityd g
```

- Die Größe der Textdatei ist mit dem Huffman Coding ziemlich stark reduziert, mehr als 50%
- Die Dekompression funktioniert allerdings noch nicht perfekt, z.B. bei den letzten Bits wird der Originaltext nocht um ein paar Buchstaben erweitert
- Die Codetable wird anhand von den im Wikipedia gefundenen english letter frequencies bestimmt


