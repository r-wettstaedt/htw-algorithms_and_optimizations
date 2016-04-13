# htw-algorithms_and_optimizations

## ollie's branch

## Aufgabe 1:
### 1.Implementieren Sie extendedGCD

```bash
node gcd.js <numberA> <numberB>
```

## Aufgabe 2:
### 2.Wieso ist extendedGCD korrekt?

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


## Aufgabe 3:
### 3.Schreiben Sie eine rekursive Funktion für die Fibonacci - Zahlen Fn.

```bash
node fibonacci.js <number>
```


## Aufgabe 4:
### 4.Untersuchen Sie die Anzahl der ausgeführten Schritte und die CPU Zeiten in 1. und 3. an ausgewählten Beispielen. Was fällt Ihnen auf?

#### GCD

    a:12 b:3
    d:3 ud:0 vd:-3
    required iterations: 2
    time: 14845μs

    -----------------------

    a:16 b:12
    d:4 ud:0 vd:0
    required iterations: 3
    time: 14504μs

    -----------------------

    a:120000 b:3000
    d:3000 ud:0 vd:-39
    required iterations: 9
    time: 14991μs

    -----------------------

    a:39088168 b:1016
    d:8 ud:0 vd:0
    required iterations: 9
    time: 14410μs

    -----------------------

    a:89 b:55
    d:1 ud:0 vd:0
    required iterations: 10
    time: 15399μs

    -----------------------

    a:9227465 b:14930352
    d:1 ud:0 vd:0
    required iterations: 34
    time: 14440μs


#### Fibonacci
    N: 3
    Done in 326μs
    Required iterations 3

    -----------------------

    N: 12
    Done in 367μs
    Required iterations 12

    -----------------------

    N: 30
    Done in 27321μs
    Required iterations 30

    -----------------------

    N: 300
    Done in not measurable, because of "no bigInt"
    Required iterations -

    -----------------------

    N: 3000
    Done in not measurable, because of "no bigInt"
    Required iterations -

    -----------------------

    N: 30000
    Done in not measurable, because of "no bigInt"
    Required iterations -


####Conclusion
Trotz erhöhter Komplexität der Eingabewerte für den extendedGCD, bleibt die Dauer der CPU Rechenzeit relativ konstant. Die Anzahl der Iterationen hängt dabei nicht von der Größe der Eingabewerte ab, sondern eher von der Größe ihres ggT.

Im Gegensatz dazu steht der Fibonacci Algorithmus, welcher bei erhöhtem Eingabewert linear sowohl die Anzahl der Iterationen als auch die CPU Zeit steigert.

Zu beachten ist auch die viel längere Rechenzeit in node.js im Vergleich zur Rechenzeit in C.
