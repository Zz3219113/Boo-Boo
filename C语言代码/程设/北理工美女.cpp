#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int x;
	int y;
	int val;
}arr[15];
int max(int x,int y)
{
	return x>y?x:y;
}
int dp[1005][1005];
int n,X,Y;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d",&n,&X,&Y);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].val);
		}
		for(int i=0;i<=X;i++)
		{
			for(int j=0;j<=Y;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(i>=arr[k].x && j>=arr[k].y)
                		dp[i][j]=max(dp[i][j] ,max(dp[i-arr[k].x][j]+dp[arr[k].x][j-arr[k].y] , dp[i-arr[k].x][arr[k].y]+dp[i][j-arr[k].y] )+arr[k].val );
            		if(i>=arr[k].y && j>=arr[k].x)
                		dp[i][j]=max( dp[i][j] ,max( dp[arr[k].y][j-arr[k].x]+dp[i-arr[k].y][j] , dp[i-arr[k].y][arr[k].x]+dp[i][j-arr[k].x] )+arr[k].val );
				}
			}
		}
		printf("%d\n",dp[X][Y]);
	}
	return 0;
}
