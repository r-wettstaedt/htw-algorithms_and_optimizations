# Programmieraufgabe 6
    Robert Wettstädt 535161
    Sona Pecenakova 540607

### 1. Wieso kann eine natürliche Zahl n nicht pseudoprim bezüglich einer Zahl a sein, wenn ggT(a, n) ≠ 1 gilt?

### 2. Finden Sie natürliche Zahlen n und 1 < a < n-1, für die a^(n-1) ≡ 1 mod n gilt, wobei n aber keine Primzahl ist.
```
n:15, a:4
4^(15 - 1) mod 15 = 1
1 mod 15 = 1
```

### 3. Implementieren Sie den Algorithmus von Rabin und Miller; einen Pseudocode dazu finden Sie in moodle. Testen Sie Ihre Implementierung, indem Sie diese mit der java-BigInteger-Methode isProbablePrime vergleichen. Wie viele Primzahlen < 1.000.000 findet Ihr Programm? Mit welchem Parameter k?
```bash
./main
```
```bash
All 1.000.000 tests passed
Number of primes found: 78.496
k: 64
```

### 4. Finden Sie eine 32-bit-Zahl, die bei einem (k = 1) Durchlauf des MillerRabin-Testes nicht als zusammengesetzt erkannt wird, obwohl sie das aber ist. Wie viele Zahlen müssen dabei getestet werden?

### 5. Finden Sie mit Ihrer Implementierung des Rabin-Miller-Algorithmus eine Zufalls(pseudo)primzahl mit 512 bit. Wie viele Zahlen müssen dabei getestet werden?