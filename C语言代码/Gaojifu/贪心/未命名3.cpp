#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{	int count[405],end,start,n,i,j,t,temp;
	scanf("%d",&t);
	while(t--)
	{	memset(count,0,sizeof(count));
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&start,&end);
			if(start>end)
			{
				temp=end;
				end=start;
				start=temp;
			}
			if(start%2==0)
			{
				count[start-1]+=10;
			}
			if(end%2==1)
			{ 
			count[end+1]+=10; 
			} 
			for(j=start;j<=end;j++)
			{
			count[j]+=10;
			}	
		}
		int	max=0;
			for(j=0;j<400;j++)
			{
				if(max<count[j])
					max=count[j];
			}
		printf("%d\n",max);
	}
 	return 0;
}

