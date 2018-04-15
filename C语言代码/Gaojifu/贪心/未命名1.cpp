#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,temp,i,j;
	int a[15]={0},count[15]={0};
	scanf("%d",&n);	
	getchar();
	for(i=0;i<n;i++)
	{	a[i]=getchar();
		switch(a[i])
		{
			case 50:count[2]++;break;
			case 51:count[3]++;break;
			case 52:{count[2]+=2;count[3]++;};break;
			case 53:count[5]++;break;
			case 54:{count[3]++;count[5]++;};break;
			case 55:count[7]++;break;
			case 56:{count[2]+=3;count[7]++;}break;
			case 57:{count[3]+=2;count[2]++;count[7]++;}break;	
		}	
	}
	for(i=7;i>1;i--)
	{	
		if(count[i]!=0)
		{
			for(j=0;j<count[i];j++)
			{
				printf("%d",i);
			}
		}
	}
	printf("\n");
	return 0;
}

