#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a1[4]={1,2,3,4};
	int j,i,k;
	int t=1<<4;
	for(i=0;i<t;i++)
	{
		j=i;
		k=0;
		printf("{");
		while(j)
		{
			if(j&1)
			{
				printf("%d",a1[k]);
			}
			j>>=1;
			k++;
		}
		printf("}");
	}
	return 0;
}

