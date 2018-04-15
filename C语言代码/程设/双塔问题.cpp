#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arr1[110],arr2[110];
int dp[110][110];
int n;
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int n,m;
	int t=1;
	while(~scanf("%d %d",&m,&n))
	{
		if(m==0&&n==0)
			break;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++)
			scanf("%d",&arr1[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr2[i]);
		
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(arr1[i]==arr2[j])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		printf("Twin Towers #%d\n",t++);
		printf("Number of Tiles : %d\n",dp[m][n]);
	}
	return 0;
}
