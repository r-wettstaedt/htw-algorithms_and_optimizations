# Programmieraufgabe 7
    Robert Wettstädt 535161
    Sona Pecenakova 540607

### 1. Führen Sie eine Breitensuche BFS mit Startknoten s im unten abgebildeten Graphen durch. Notieren Sie den Verlauf der Zustände der Warteschlange Q.
```
Q = {s}

1. u = s(0)		Q = {a(1), d(1)}
2. u = a(1)		Q = {d(1), b(2), e(2)}
3. u = d(1)		Q = {b(2), e(2), f(2)}
4. u = b(2)		Q = {e(2), f(2), c(3), g(3)}
5. u = e(2)		Q = {f(2), c(3), g(3)}
6. u = f(2)		Q = {c(3), g(3), h(3)}
7. u = c(3)		Q = {g(3), h(3), i(4)}
8. u = g(3)		Q = {h(3), i(4)}
9. u = h(3)		Q = {i(4)}
10. u = i(4)	Q = {}
```


### 2. Lesen Sie den Beweis für die Korrektheit von BFS auf den Seiten 11 und 12 durch. Wieso gilt 3. auf Seite 30? Wo wird dies im Beweis verwendet?

### 3. Führen Sie eine Tiefensuche DFS mit Startknoten s im unten abgebildeten Graphen durch. Notieren Sie für jeden Knoten u das Zeitintervall (d[u], f[u]) und für jede Kante, ob sie eine Tree-, Back-, Forward- oder Cross-Kante ist. Starten Sie mit dem Knoten s und gehen Sie die Adjazenzlisten lexikographisch durch.