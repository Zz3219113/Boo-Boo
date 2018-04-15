#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
#define Max 0x3f3f3f3f
using namespace std;
struct node{
	long long weight,value;
}arr[501];
long long dp[10010];
int main()
{
	int t,a1,a2,v,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,Max,sizeof(dp));
		scanf("%d %d",&a1,&a2);
		v=a2-a1;
		scanf("%d",&n);
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&arr[i].value,&arr[i].weight);
		}
 		for(int i=1;i<=n;i++)
		{
			int j;
			for(j=arr[i].weight;j<=v;j++)
			{
				if(dp[j]>dp[j-arr[i].weight]+arr[i].value)
					dp[j]=dp[j-arr[i].weight]+arr[i].value;
			}
		}
		if(dp[v]>=50000000000)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[v]);
	}
	return 0;
}
