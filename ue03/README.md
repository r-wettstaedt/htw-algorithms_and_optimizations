#Programmieraufgabe 3
	Robert Wettstädt 535161
    Sona Pecenakova 540607



###1. Implementieren Sie einen Algorithmus, der die n-te Potenz a^n einer natürlichen Zahl a in O (log n) Schritten berechnet.
```bash
    ./squaremultiplybig <a> <n>
```


###2. Modifizieren Sie Ihr Programm aus 1. derart, dass die modulare Potenz a^n mod m berechnet wird.
```bash
    ./modularexp <a> <n> <m>
```

###3. Testen Sie Ihre Programme und messen Sie dabei die Laufzeit
#### Simple multiplication
		2^5 = 32
		Time: 0.000062 seconds
			
		2^19 = 524288
		Time: 0.000070 seconds
					
		2^123 = 1.0633823966279326983230456482242756608 × 10^37
		Time: 0.000069 seconds
			
		2^123456 = 9.1021647594683810219535933654934251479534157863 × 10^199
		Time: 0.339742 seconds
			
		2^1234567
		Time: 33.373205 seconds

#### Square-and-Multiply
		2^5 = 32
		Time: 0.000085 seconds
			
		2^19 = 524288
		Time: 0.000097 seconds
					
		2^123 = 1.0633823966279326983230456482242756608 × 10^37
		Time: 0.000101 seconds
			
		2^123456 = 9.1021647594683810219535933654934251479534157863 × 10^199
		Time: 0.000755 seconds
			
		2^123456789
		Time: 2.126740 seconds
			
		2^1234567890
		Time: 26.736135 seconds
			
#### Modular exponentiation
		2^5 mod 13 = 6
		Time: 0.000072 seconds
			
		2^19 mod 24 = 8
		Time: 0.000074 seconds 
			
		2^123 mod 35 = 8
		Time: 0.000074 seconds
			
		2^123456789 mod 123 = 20
		Time: 0.000091 seconds 
			
		2^123456789012 mod 123456 = 55552
		Time: 0.000099 seconds
	
- Man kann merken, dass der "Simple Multiplication" Algorithmus, der die Zahl einfach n-mal multipliziert schneller ist, bei kleineren Zahlen. Aber je hoeher die Zahlen sind, wird es wesentlich langsamer als der Square-and-Multiply Algorithmus.
- Modular exponentiation ist viel schneller als Square-and-Multiply, dadurch dass alle Werte waehrend der Berechnung bei modulo reduziert werden.

###4. Wie lange dauert die Berechnung von an mod m in 2., wenn a, n und m 1000-bit- Zahlen sind?
			