#Programmieraufgabe 1


###1. Implementieren Sie extendedGCD
```bash
    ./gcd <numberA> <numberB>
```


###2. Wieso ist extendedGCD korrekt?

####Insbesondere: Terminiert der Algorithmus?
* Ja, wenn c == 0
* Dies geschieht in jedem Fall, da c in jeder Iteration einer kleiner werdenden Zahl zugewiesen wird
* Durch die Abrundung mit der floor() Funktion, handelt es sich außerdem immer um ganzzahlige, sodass das das Erreichen von 0 unvermeidbar ist

####Wieso berechnet er den gcd?
* Weil, Baum


###3. Schreiben Sie eine rekursive Funktion für die Fibonacci-Zahlen Fn
```bash
    ./fibonacci <maxN>
```


###4. Untersuchen Sie die Anzahl der ausgeführten Schritte und die CPU-Zeiten in 1. und 3. an ausgewählten Beispielen. Was fällt Ihnen auf?

####GCD
    a: 12   b: 3
    d: 3    u_d: 1  v_d: 0
    Done in 6μs
    Required iterations 2

    -----------------------

    a: 16   b: 12
    d: 4    u_d: 0  v_d: 0
    Done in 9μs
    Required iterations 3

    -----------------------

    a: 120000   b: 3000
    d: 3000 u_d: 1  v_d: 0
    Done in 7μs
    Required iterations 2

    -----------------------

    a: 39088168 b: 1016
    d: 8    u_d: 0  v_d: 0
    Done in 7μs
    Required iterations 9

    -----------------------

    a: 89   b: 55           (consecutive fibonacci numbers)
    d: 1    u_d: 0  v_d: 0
    Done in 6μs
    Required iterations 10

    -----------------------

    a: 9227465  b: 14930352 (consecutive fibonacci numbers)
    d: 1    u_d: 0  v_d: 0
    Done in 7μs
    Required iterations 34

####Fibonacci
    N: 3
    Done in 42μs
    Required iterations 3

    -----------------------

    N: 12
    Done in 49μs
    Required iterations 12

    -----------------------

    N: 30
    Done in 44μs
    Required iterations 30

    -----------------------

    N: 300
    Done in 97μs
    Required iterations 300

    -----------------------

    N: 3000
    Done in 971μs
    Required iterations 3000

    -----------------------

    N: 30000
    Done in 42933μs (43ms)
    Required iterations 30000

####Conclusion
Trotz erhöhter Komplexität der Eingabewerte für den extendedGCD, bleibt die Dauer der CPU Rechenzeit relativ konstant. Die Anzahl der Iterationen hängt dabei nicht von der Größe der Eingabewerte ab, sondern eher von der Größe ihres ggT.

Im Gegensatz dazu steht der Fibonacci Algorithmus, welcher bei erhöhtem Eingabewert linear sowohl die Anzahl der Iterationen als auch die CPU Zeit steigert. Ausgenommen ist davon der Schritt von 3,000 zu 30,000 Iterationen.
