#include<stdio.h>
int main()
{
	int n,i,j,k,a1[100],temp,flag,t;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		a1[i]=i;
	}
	t=1<<(n+1);
	for(i=0;i<t;i++)
	{	
		temp=i;
		k=0;
		printf("{");
		while(temp)
		{
			if(temp&1)
			{	if(flag==0)
				{
					printf("%d",a1[k]);
					flag=1;
				}
				else if(flag==1)
					printf(" %d",a1[k]);
			}
			temp>>=1;
			k++;
		}
		printf("}");
		printf("\n");
		flag=0;
	}
	return 0;
}

