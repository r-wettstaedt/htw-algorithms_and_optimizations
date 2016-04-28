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
  Insertionsort done in 1844µs
  Mergesort     done in 4639µs
  Quicksort     done in 4557µs

  ~~= Presorted Array =~~
  Insertionsort done in 464µs
  Mergesort     done in 547µs
  Quicksort     done in 522µs


~~~~= Arraysize 100 =~~~~

  ~~= Random Array =~~
  Insertionsort done in 251µs
  Mergesort     done in 370µs
  Quicksort     done in 140µs

  ~~= Presorted Array =~~
  Insertionsort done in 15µs
  Mergesort     done in 368µs
  Quicksort     done in 377µs


~~~~= Arraysize 1.000 =~~~~

  ~~= Random Array =~~
  Insertionsort done in 25ms
  Mergesort     done in 3895µs
  Quicksort     done in 1421µs

  ~~= Presorted Array =~~
  Insertionsort done in 134µs
  Mergesort     done in 4182µs
  Quicksort     done in 25ms


~~~~= Arraysize 10.000 =~~~~

  ~~= Random Array =~~
  Insertionsort done in 2408ms
  Mergesort     done in 66ms
  Quicksort     done in 21ms

  ~~= Presorted Array =~~
  Insertionsort done in 1200µs
  Mergesort     done in 68ms
  Quicksort     done in 956ms


~~~~= Arraysize 100.000 =~~~~

  ~~= Random Array =~~
  Insertionsort done in 227s
  Mergesort     done in 597ms
  Quicksort     done in 259ms

  ~~= Presorted Array =~~
  Insertionsort done in 11ms
  Mergesort     done in 554ms
  Quicksort     done in 19s
```
###3. Vergleichen Sie die Laufzeiten mit den theoretisch ermittelten mittleren Anzahlen von Vergleichen, die in den Algorithmen vorgenommen werden.
###4. Was geschieht, wenn man die Algorithmen auf die sortierte Liste 0, 1, 2, ... n – 1 anwendet?
###5. Stellen Sie Ihre Ergebnisse in einem Diagramm dar (x-Achse Eingabegröße n, y-Achse Laufzeiten bzw. Anzahlen der Vergleiche).