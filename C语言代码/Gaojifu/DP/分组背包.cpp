#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int dp[150],arr[150][150];
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		if(n==0&&m==0) 
			break;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&arr[i][j]);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)     //n组物品 
			for(int j=m;j>=1;j--) // 01背包问题 
				for(int k=1;k<=m;k++) //遍历物品 
					if(j-k>=0)
					dp[j]=max(dp[j],dp[j-k]+arr[i][k]);
		printf("%d\n",dp[m]);
		
	}
	return 0;
}
