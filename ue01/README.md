# Algorithms & Optimization UE01

### 1. Implementieren Sie extendedGCD
    
    ./extendedGCD <number A> <number B>
    

### 2. Wieso ist extendedGCD korrekt?

#### Terminiert der Algorithmus?
    Ja, wenn r = 0, r wird kleiner also wird es 0 erreichen
    
### 3. Schreiben Sie eine rekursive Funktion für die Fibonacci-Zahlen Fn
    ./fibonacci <number N>
    
### 4. Untersuchen Sie die Anzahl der ausgeführten Schritte und die CPU-Zeiten in 1. und 3. an ausgewählten Beispielen. Was fällt Ihnen auf?

####  fibonacci
    n = 3     time: 0.000034 seconds
    n = 10    time: 0.000045 seconds
    n = 15    time: 0.000064 seconds
    n = 25    time: 0.001473 seconds
    n = 40    time: 1.316626 seconds
    n = 50    time: 167.200933 seconds
    
#### extendedGCD

   ./extendedGCD 10 15
    iterations: 3
    time: 0.000043 seconds
    
    --------------------
  
    ./extendedGCD 13442 923810
    iterations: 15
    time: 0.000043 seconds
    
    --------------------
    
    ./extendedGCD 89 55 (consecutive fibonacci numbers)
    iterations: 9
    time: 0.000043 seconds
    
    ---------------------
    
    ./extendedGCD 9227465 14930352 (consecutive fibonacci numbers)
    iterations: 35
    time: 0.000043 seconds
    
#### Conclusion
    Die Komplexität von dem rekursiven Fibonacci-Algorithmus ist exponentiell (O(2N/2)), d.h. mir der Eingabewert steigert auch die CPU-Zeit und die Anzahl von Iterationen (Anzahl von Iterationen = n)
    Bei dem extendedGCD algorithmus bleibt die Zeit konstant und die Anzahl von der Iterationen ändert sich.
