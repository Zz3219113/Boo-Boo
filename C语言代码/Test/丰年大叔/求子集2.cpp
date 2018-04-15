#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,i,t,temp,flag=0;
	scanf("%d",&n);
	t=1<<(n+1);
	for(i=0;i<t;i++)
	{	int count=0;
		temp=i;
		printf("{");
		while(temp)
		{
			if(temp%2==1)
			{
				if(flag==0)
				{
					printf("%d",count);
					flag=1;
				}
				else 
					printf(" %d",count);
			}
			count++;
			temp=temp/2;
		}
		printf("}");
		printf("\n");
		flag=0;
	}
	return 0;
}

