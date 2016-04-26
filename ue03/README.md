#Programmieraufgabe 3


###1. Implementieren Sie einen Algorithmus, der die n-te Potenz a^n einer natürlichen Zahl a in O (log n) Schritten berechnet.
```bash
    ./squaremultiplybig <a> <n>
```


###2. Modifizieren Sie Ihr Programm aus 1. derart, dass die modulare Potenz a^n mod m berechnet wird.
```bash
    ./modularexp <a> <n> <m>
```

###3. Testen Sie Ihre Programme und messen Sie dabei die Laufzeit
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
	
- Modular exponentiation ist viel schneller als Square-and-Multiply, dadurch dass alle Werte waehrend der Berechnung bei modulo reduziert werden.

###4. Wie lange dauert die Berechnung von an mod m in 2., wenn a, n und m 1000-bit- Zahlen sind?
			