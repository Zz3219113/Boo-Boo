#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
int main()
{
	int n,a[200],temp,j;
	while(~scanf("%d",&n)&&n!=0)
	{
		temp=0;
		int N=n;
		memset(a,0,sizeof(a));
		if(n==1)
		{
			printf("Discarded cards:\nRemaining card: 1\n");continue;
		}
			
		if(n==2)
		{
			printf("Discarded cards: 1\nRemaining card: 2\n");continue;
		}	
		else
		{
			for(int i=1;i<=n;i++)
				a[i]=i;
			printf("Discarded cards:");
			for(int i=1;;i+=2)
			{
				if(N==3)// 
				{
					for(j=1;j<=200;j++)
					{
						if(a[j]!=0)
							break;
					}
					printf(" %d, %d\nRemaining card: %d\n",a[j],a[j+2],a[j+1]);
					break;
				}
				else
				{
					printf(" %d,",a[i]);
					a[i]=0;
					N--;
					temp++;
					a[n+temp]=a[i+1];
					a[i+1]=0;
				}
			}	
		}
	}
 	return 0;
}

