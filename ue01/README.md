# htw-algorithms_and_optimizations

## maxim's branch

https://www.npmjs.com/package/big-integer

###Aufgabe 1:
  Sprache - node.js
  Aufruf -
  ```bash
  node gcd.js <numberA> <numberB>
  ```

###Aufgabe 2:
  1. Der Algorithmus terminiert.
  2. Hat einen Messbaren output.

  Der extended GCD besagt, dass anstatt immer wieder den größeren Wert d (Rest) voneinander abzuziehen eine schnellere Operation (das Teilen des größeren durch den kleineren Wert) ausgeführt wird um eben diese Schritte zu vermeiden.

  // alt und braucht mehr iterationen
  for(var i=0; i<4; i++)
    130-30
  Ergebnis -> 10

  // eine Operation
  130 - ((int) 130/4)
  Ergebnis -> 10

###Aufgabe 3:
  Sprache - node.js
  Aufruf -
  ```bash
  node fibonaci.js <numberN>
  ```

###Aufgabe 4:

####GCD
    a: 12   b: 3
    d: 3    u_d: 0  v_d: -3
    Done in 2157μs
    Required iterations 2

    -----------------------

    a: 16   b: 12
    d: 4    u_d: 0  v_d: 0
    Done in 2564μs
    Required iterations 3

    -----------------------

    a: 120000   b: 3000
    d: 3000 u_d: 1  v_d: -39
    Done in 2401μs
    Required iterations 2

    -----------------------

    a: 39088168 b: 1016
    d: 8    u_d: 0  v_d: 0
    Done in 2671μs
    Required iterations 9

    -----------------------

    a: 89   b: 55           (consecutive fibonacci numbers)
    d: 1    u_d: 0  v_d: 0
    Done in 3175μs
    Required iterations 10

    -----------------------

    a: 9227465  b: 14930352 (consecutive fibonacci numbers)
    d: 1    u_d: 0  v_d: 0
    Done in 3799μs
    Required iterations 34

####Fibonacci
    N: 3
    Done in 16030μs
    Required iterations 3

    -----------------------

    N: 12
    Done in 14741μs
    Required iterations 12

    -----------------------

    N: 30
    Done in 16549μs
    Required iterations 30

    -----------------------

    N: 300
    Done in 16558μs
    Required iterations 300

    -----------------------

    N: 3000
    Done in 27511μs
    Required iterations 3000

    -----------------------

    N: 30000
    Done in 309770μs
    Required iterations 30000

####Conclusion
Trotz erhöhter Komplexität der Eingabewerte für den extendedGCD, bleibt die Dauer der CPU Rechenzeit relativ konstant. Die Anzahl der Iterationen hängt dabei nicht von der Größe der Eingabewerte ab, sondern eher von der Größe ihres ggT.

Im Gegensatz dazu steht der Fibonacci Algorithmus, welcher bei erhöhtem Eingabewert linear sowohl die Anzahl der Iterationen als auch die CPU Zeit steigert.

Zu beachten ist auch die viel längere Rechenzeit in node.js im Vergleich zur Rechenzeit in C.
