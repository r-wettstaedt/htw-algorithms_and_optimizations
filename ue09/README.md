# Programmieraufgabe 9
    Robert Wettstädt 535161
    Sona Pecenakova 540607

### Implementieren Sie LCS-Length und Print-LCS. Wenden Sie Ihre Methode auf das Beispiel von Seite 8 an. Welches asymptotische Laufzeitverhalten hat Print-LCS?

Beispiel:
```
    ./lcs
    ACGCTAC             
    CTGACA

    The Longest Common Subsequence is CGCA
    Print method took 0.000012 seconds to execute 

```



Implementation:
```c
#include<stdio.h>
#include<string.h>

int i,j,m,n,c[20][20];
char x[20],y[20],b[20][20];

void print(int i,int j)
{
if(i==0 || j==0)
return;
if(b[i][j]=='p'){
print(i-1,j-1);
printf("%c",x[i-1]);
}
else if(b[i][j]=='o')
print(i-1,j);
else
print(i,j-1);
}

void lcs()
{
m=strlen(x);
n=strlen(y);

for(i=0;i<=m;i++){
c[i][0]=0;
}
for(i=0;i<=n;i++){
c[0][i]=0;
}

//p links oben, o oben, l links
for(i=1;i<=m;i++)
for(j=1;j<=n;j++){
if(x[i-1]==y[j-1]){
c[i][j]=c[i-1][j-1]+1;
b[i][j]='p';
} else if(c[i-1][j]>=c[i][j-1]){
c[i][j]=c[i-1][j];
b[i][j]='o';
} else {
c[i][j]=c[i][j-1];
b[i][j]='l';
}
}
}

int main()
{
scanf("%s",x);
scanf("%s",y);
printf("\nThe Longest Common Subsequence is ");
lcs();
print(m,n);
printf("\n");
return 0;
}

```

Wir haben uns bei der Implementation an das Beispiel von http://www.thecrazyprogrammer.com/2015/05/c-program-for-longest-common-subsequence-problem.html orientiert
