#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int n,m,maxren,times,ex;
int dp[150],rennai[150],arr[150],cost[150];
void zopack(int value,int weight)//零一背包 
{
	for(int i=ex;i>=value;i--)
	{
		dp[i]=max(dp[i],dp[i-value]+weight);
	}
}
void cpack(int value,int weight)//完全背包 
{
	for(int i=weight;i<=ex;i++)
	{
		dp[i]=max(dp[i],dp[i-value]+weight);
	}
}
int main()
{
	while(~scanf("%d %d %d %d",&ex,&maxren,&n,&times))
	{
		for(int i=1;i<=n;i++)
			scanf("%d %d",&arr[i],&cost[i]);
		for(int i=1;i<=n;i++)
		{
			if(arr[i]*times>=ex)
				cpack(arr[i],cost[i]);
			else
			{
				int k=1;
				while(k<times)//二进制优化 
				{
					zopack(k*arr[i],k*cost[i]);
					times-=k;
					k*=2;
				}
				zopack(arr[i],cost[i]);
			}
		}
		printf("%d\n",dp[ex]);
	}
	return 0;
} 
