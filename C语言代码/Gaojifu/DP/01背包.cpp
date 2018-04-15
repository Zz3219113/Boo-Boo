#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
struct node{
	int weight,value;
}arr[1001];
int dp[1001];
int main()
{
	int t,cnt,v;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&cnt,&v);
		for(int i=1;i<=cnt;i++)
			scanf("%d",&arr[i].value);
		for(int i=1;i<=cnt;i++)
			scanf("%d",&arr[i].weight);
		for (int i =1; i <=cnt; i++)
			for (int j = v; j >= arr[i].weight; j--)
				dp[j] = max(dp[j], dp[j - arr[i].weight] + arr[i].value);
		printf("%lld\n",dp[v]);
	}
	return 0;
}
