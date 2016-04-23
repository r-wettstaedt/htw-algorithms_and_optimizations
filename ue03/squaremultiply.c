#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <math.h>


int convertTo2(int n)
{
	
	int rem, i=1, binary=0;
   
    while (n!=0)
    {
        rem = n%2;
        n /= 2;
        binary += rem * i;
        i *= 10;
    }
    return binary;
		
		
}

int squareAndMultiply(int number, int exp)
{
	int binexp = convertTo2(exp);
	
	//convert binary exponent to array
	int length = log10(binexp) + 1;
    int i;
    int *expArray = calloc(length, sizeof(int));
    for ( i = 0; i < length; ++i, binexp /= 10 )
    {
        expArray[i] = binexp % 10;
        //printf("%d", expArray[i]);
    }
    
    //printf("\n");
    
    //square and multiply
    //run the array of binary exponent from the back
    
    int result = number;
    for(i = length - 2; i >= 0; i--){
    	if(expArray[i] == 0){
    		result *= result;
    	}
    	else if(expArray[i] == 1){
    		result *= result;
    		result += result;
    	}
    }
    
    return result;
    
	
}

int main(int argc, char *argv[])
{
        
    int n = atoi(argv[1]);
    int e = atoi(argv[2]);
  
	printf("%d^%d = %d\n", n, e, squareAndMultiply(n, e));
	//printf("Decimal %d to binary is = %d\n", n, convertTo2(e));
    return 0;
}