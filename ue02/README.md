#Programmieraufgabe 2


###1. Programmieren Sie rekursiv mit den Parametern Punkt A, Punkt B, Winkel alpha, Höhe h ein Fraktal.
![Fractal](http://i.imgur.com/wjSo8wr.png)
```bash
    ./fractal [A] [B] [alpha] [h]
```

---

![FractalSVG1](http://rawgit.com/r-wettstaedt/htw-algorithms_and_optimizations/feature/dev-robert/ue02/fractal1.svg)
```bash
    ./fractal 0 256 45 128
```

---

![FractalSVG2](http://rawgit.com/r-wettstaedt/htw-algorithms_and_optimizations/feature/dev-robert/ue02/fractal2.svg)
```bash
    ./fractal 0 256 90 90
```

---

![FractalSVG3](http://rawgit.com/r-wettstaedt/htw-algorithms_and_optimizations/feature/dev-robert/ue02/fractal3.svg)
```bash
    ./fractal 0 256 100 128
```



###2. Programmieren Sie die Ackermann-Funktion a: NxN → N. Berechnen Sie a für einige kleine (!) Werte m und n. Was fällt Ihnen auf?
```bash
    ./ackermann [m] [n]
```

https://en.wikipedia.org/wiki/Ackermann_function#Table_of_values

    Big Integer     | Done in 12μs
    A(0, 0) = 1
    Native Integer  | Done in 0μs
    A(0, 0) = 1

    -----------------------

    Big Integer     | Done in 21μs
    A(0, 1) = 2
    Native Integer  | Done in 0μs
    A(0, 1) = 2

    -----------------------

    Big Integer     | Done in 13μs
    A(0, 2) = 3
    Native Integer  | Done in 1μs
    A(0, 2) = 3

    -----------------------

    Big Integer     | Done in 13μs
    A(0, 3) = 4
    Native Integer  | Done in 0μs
    A(0, 3) = 4

    -----------------------

    Big Integer     | Done in 6μs
    A(0, 4) = 5
    Native Integer  | Done in 0μs
    A(0, 4) = 5

    -----------------------

    Big Integer     | Done in 9μs
    A(1, 0) = 2
    Native Integer  | Done in 0μs
    A(1, 0) = 2

    -----------------------

    Big Integer     | Done in 22μs
    A(1, 1) = 3
    Native Integer  | Done in 1μs
    A(1, 1) = 3

    -----------------------

    Big Integer     | Done in 22μs
    A(1, 2) = 4
    Native Integer  | Done in 0μs
    A(1, 2) = 4

    -----------------------

    Big Integer     | Done in 20μs
    A(1, 3) = 5
    Native Integer  | Done in 0μs
    A(1, 3) = 5

    -----------------------

    Big Integer     | Done in 14μs
    A(1, 4) = 6
    Native Integer  | Done in 1μs
    A(1, 4) = 6

    -----------------------

    Big Integer     | Done in 11μs
    A(2, 0) = 3
    Native Integer  | Done in 1μs
    A(2, 0) = 3

    -----------------------

    Big Integer     | Done in 14μs
    A(2, 1) = 5
    Native Integer  | Done in 0μs
    A(2, 1) = 5

    -----------------------

    Big Integer     | Done in 14μs
    A(2, 2) = 7
    Native Integer  | Done in 1μs
    A(2, 2) = 7

    -----------------------

    Big Integer     | Done in 19μs
    A(2, 3) = 9
    Native Integer  | Done in 1μs
    A(2, 3) = 9

    -----------------------

    Big Integer     | Done in 21μs
    A(2, 4) = 11
    Native Integer  | Done in 1μs
    A(2, 4) = 11

    -----------------------

    Big Integer     | Done in 24μs
    A(3, 0) = 5
    Native Integer  | Done in 1μs
    A(3, 0) = 5

    -----------------------

    Big Integer     | Done in 26μs
    A(3, 1) = 13
    Native Integer  | Done in 1μs
    A(3, 1) = 13

    -----------------------

    Big Integer     | Done in 92μs
    A(3, 2) = 29
    Native Integer  | Done in 3μs
    A(3, 2) = 29

    -----------------------

    Big Integer     | Done in 386μs
    A(3, 3) = 61
    Native Integer  | Done in 13μs
    A(3, 3) = 61

    -----------------------

    Big Integer     | Done in 2044μs
    A(3, 4) = 125
    Native Integer  | Done in 85μs
    A(3, 4) = 125

    -----------------------

    Big Integer     | Done in 25μs
    A(4, 0) = 13
    Native Integer  | Done in 1μs
    A(4, 0) = 13

    -----------------------

    Big Integer     | n.A.
    A(4, 1) = n.A.
    Native Integer  | n.A.
    A(4, 1) = n.A.

###3. Zeigen Sie durch mathematische Induktion, dass sich für die Lösung der Rekursionsgleichung der Wert T(n) = n lg n ergibt, wenn eine Potenz von 2 ist. (Dabei ist lg der Logarithmus zur Basis 2.)
T(2^k) = 2^t * k