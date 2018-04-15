#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{	int n,i,j,x,y,count=0;
	char a1[2005],a2[2005];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c",&a1[i]);
		getchar();
	}
	for(i=n-1;i>=0;i--)
	{
		a2[i]=a1[n-i-1];
	}
	i=0;j=0;
	while(1)
	{	
		if(a1[i]>a2[j])
		{
			printf("%c",a2[j]);
			count++;
			j++;
		}	
		else if(a1[i]<a2[j])
		{
			printf("%c",a1[i]);
			count++;
			i++;
		}
		else
		{	x=i;
			y=j;
			while(1)
			{	x++;
				y++;
				if(a1[x]>a2[y])
				{	
					printf("%c",a2[j]);
					count++;
					j++;
					break;
				}
				if(a1[x]<a2[y])
				{
					printf("%c",a1[i]);
					count++;
					i++;
					break;
				}
			}
		}
		if(count/80==1)
		{
			printf("\n");
			count=0;
		}
		if(i+j==n)
		break;	
	}
	return 0;
}

