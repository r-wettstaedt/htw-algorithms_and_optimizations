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
                    printf("%c",x[i]);
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

                for(i=1;i<=m;i++)
                                c[i][0]=0;
                for(j=1;j<=n;j++)
                                c[0][j]=0;

                //l = links, o = oben, p = linksoben
                for(i=1;i<=m;i++)
                	for(j=1;j<=n;j++){
                		if(x[i]==y[j]){
                             c[i][j]=c[i-1][j-1]+1;
                             b[i][j]='p';
                        }
                        else if(c[i-1][j]>=c[i][j-1]) {
            				c[i][j]=c[i-1][j];
                            b[i][j]='o';
                    	}
                        else{
                        	c[i][j]=c[i][j-1];
                            b[i][j]='l';
                        }
                }
}

int main()
{
                printf("Erste Sequenz: ");
                scanf("%s",x);
                printf("Zweite Sequenz:");
                scanf("%s",y);
                printf("\nThe Longest Common Subsequence is ");
                lcs();
                print(m,n);
                printf("\n");
        		return 0;
}
