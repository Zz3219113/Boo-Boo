#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char arr[100010];
char b[2],c[2];
int main()
{
	int n;
	b[0]='w';
	b[1]='b';
	c[0]='b';
	c[1]='w';
	while(~scanf("%d",&n))
	{
		getchar();
		int cont1=0,cont2=0,res1=0,res2;
		for(int i=0;i<n;i++)
		{
			scanf("%c",&arr[i]);
		}
		for(int i=0;i<n;i+=2)//wb
		{
			if(arr[i]!=b[(i/2)%2])
			{
				if((i/2)%2==0)
					cont1++;
				else
					cont2++;
			}
			if(arr[i+1]!=b[(i/2)%2])
			{
				if((i/2)%2==0)
					cont1++;
				else
					cont2++;
			}		
		}
		if(cont1>cont2)
			res1=cont1;
		else
		{
			res1=cont2;
		}
		cont1=0;
		cont2=0;
		for(int i=0;i<n;i+=2)//wb
		{
			if(arr[i]!=c[(i/2)%2])
			{
				if((i/2)%2==0)
					cont1++;
				else
					cont2++;
			}
			if(arr[i+1]!=c[(i/2)%2])
			{
				if((i/2)%2==0)
					cont1++;
				else
					cont2++;
			}
		}
		if(cont1>cont2)
			res2=cont1;
		else
			res2=cont2;
		if(res1>res2)
			printf("%d\n",res2);
		else
			printf("%d\n",res1);
	}
}
