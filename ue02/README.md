#Programmieraufgabe 2


###1. Programmieren Sie rekursiv mit den Parametern Punkt A, Punkt B, Winkel alpha, Höhe h folgendes Fraktal.
```bash
    ./fractal <A> <B> <alpha> <h>
```


###2. Programmieren Sie die Ackermann-Funktion a: NxN → N
```bash
    ./ackermann <A> <B>
```

###3. Zeigen Sie durch mathematische Induktion, dass sich für die Lösung der Rekursionsgleichung der Wert T(n) = n lg n ergibt, wenn eine Potenz von 2 ist. (Dabei ist lg der Logarithmus zur Basis 2.)
	
	T(n)= {2 				 falls n=2
		= {2T(n/2)+n         falls n= 2^k,mit k>1

	zu zeigen:
	T(n)= n lg⁡(n)

	T(n)≤ c n lg⁡(n)		      	c>0
	T(2)= 2 ≤c 2 lg(2)     		c≥1
	T(4)= 2T(2)+4=8 ≤c 4 lg(4)	c≥1
	

	T(n)= 2T(n/2)+ n ≤ 2c(n/2) lg⁡(n/2) + n
					= c n lg⁡(n/2)+n
					= c n lg⁡n-c n lg⁡2+n
					= c n lg⁡n-c n+n
					≤ c n lg⁡n
