#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int main()
{
    int i,A,B;
    int a[10]={1,2,3,1,2,1,1,6,1,1};
    
    A=a[5];
    B=0;
    for(i=0; i<10; i++)
        if(B=0)
        {
            A = a[i];
            B =1;
        }else if( A==a[i])
            B++;
        else if(A!=a[i])
            B--;
    printf("%d", A);
    getchar();
    return 0;
}
