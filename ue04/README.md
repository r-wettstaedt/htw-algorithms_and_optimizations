#Programmieraufgabe 4
    Robert Wettstädt 535161
    Sona Pecenakova 540607


###1. Implementieren Sie die Sortieralgorithmen
```bash
./sort
```

###2. Messen Sie die (über mehrere Läufe gemittelten) Laufzeiten dieser Algorithmen für zufällig erzeugte Listen ganzer Zahlen verschiedener Längen.
```
~~~~= Arraysize 10 =~~~~

  ~~= Random Array =~~
  Insertionsort done in 1844µs  | 33 modifications
  Mergesort     done in 4639µs  | 24 modifications
  Quicksort     done in 4557µs  | 9 modifications

  ~~= Presorted Array =~~
  Insertionsort done in 464µs   | 10 modifications
  Mergesort     done in 547µs   | 19 modifications
  Quicksort     done in 522µs   | 9 modifications


~~~~= Arraysize 100 =~~~~

  ~~= Random Array =~~
  Insertionsort done in 251µs   | 2190 modifications
  Mergesort     done in 370µs   | 551 modifications
  Quicksort     done in 140µs   | 152 modifications

  ~~= Presorted Array =~~
  Insertionsort done in 15µs    | 100 modifications
  Mergesort     done in 368µs   | 360 modifications
  Quicksort     done in 377µs   | 94 modifications


~~~~= Arraysize 1.000 =~~~~

  ~~= Random Array =~~
  Insertionsort done in 25ms    | 256688 modifications
  Mergesort     done in 3895µs  | 8697 modifications
  Quicksort     done in 1421µs  | 2372 modifications

  ~~= Presorted Array =~~
  Insertionsort done in 134µ    | 1000 modifications
  Mergesort     done in 4182µs  | 5242 modifications
  Quicksort     done in 25ms    | 816 modifications


~~~~= Arraysize 10.000 =~~~~

  ~~= Random Array =~~
  Insertionsort done in 2408ms  | 24912857 modifications
  Mergesort     done in 66ms    | 120423 modifications
  Quicksort     done in 21ms    | 35556 modifications

  ~~= Presorted Array =~~
  Insertionsort done in 1200µs  | 10000 modifications
  Mergesort     done in 68ms    | 73379 modifications
  Quicksort     done in 956m    | 14021 modifications


~~~~= Arraysize 100.000 =~~~~

  ~~= Random Array =~~
  Insertionsort done in 227s    | 2506041110 modifications
  Mergesort     done in 597ms   | 1536078 modifications
  Quicksort     done in 259ms   | 506314 modifications

  ~~= Presorted Array =~~
  Insertionsort done in 11ms    | 100000 modifications
  Mergesort     done in 554ms   | 915899 modifications
  Quicksort     done in 19s     | 282178 modifications
```

###3. Vergleichen Sie die Laufzeiten mit den theoretisch ermittelten mittleren Anzahlen von Vergleichen, die in den Algorithmen vorgenommen werden.
```
Average modifications on random arrays:
Insertion: 2530972413 modifications
Mergesort: 1665706 modifications
Quicksort: 544744 modifications

Average modifications on presorted arrays:
Insertion: 111110 modifications
Mergesort: 991530 modifications
Quicksort: 297219 modifications
```

- Man sieht, dass die durchschnittliche Laufzeiten in machen Fällen mit der Anzahl der durchschnittlichen Vergleichen zusammenhägen
- Z.B dauert der Insertion-Sort auf random array am längsten und hat auch die größeste Anzahl an Vergleichen
- Anderseits, sieht man bei dem Merge-Sort keine Beziehung zwischen den Daten

###4. Was geschieht, wenn man die Algorithmen auf die sortierte Liste 0, 1, 2, ... n – 1 anwendet?
- Man kann von den gemittelten Laufzeiten sehen, dass z.B. Insertionsort, der relativ langsam auf den Random Arrays ist, sehr schnell die sortierten Listen durchlaufen kann.
- Im Gegenfall, ist Quicksort sehr schnell auf random arrays aber langsamer auf sortierten arrays

###5. Stellen Sie Ihre Ergebnisse in einem Diagramm dar (x-Achse Eingabegröße n, y-Achse Laufzeiten bzw. Anzahlen der Vergleiche).
![Random Array computing times](http://rawgit.com/r-wettstaedt/htw-algorithms_and_optimizations/feature/dev-robert/ue04/01.png)

---

![Presorted Array computing times](http://rawgit.com/r-wettstaedt/htw-algorithms_and_optimizations/feature/dev-robert/ue04/02.png)

---

![Random Array modifications](http://rawgit.com/r-wettstaedt/htw-algorithms_and_optimizations/feature/dev-robert/ue04/03.png)

---

![Presorted Array modifications](http://rawgit.com/r-wettstaedt/htw-algorithms_and_optimizations/feature/dev-robert/ue04/04.png)
