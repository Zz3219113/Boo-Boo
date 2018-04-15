#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>	
int main()
{
	int n,i,j,m,stick[5005],temp,max;
	
	while(~scanf("%d",&m))
	{  	int count=1;
		memset(stick,0,sizeof(stick));
		for(i=0;i<m;i++)
		{
			scanf("%d",&stick[i]);
		}		
		count=m;
		for(j=1;j<m;j++)
		{
			for(i=0;i<=j-1;i++)
			{
				if(stick[i]>=stick[j])
				{	
					count--;
					stick[i]=stick[j];
					stick[j]=0;
					break;				
				}			
			}
		}
		printf("%d\n",count);	
	}
	return 0;
}

