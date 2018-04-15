#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 12 
#define N 110
#define Max 0x3f3f3f3f
int m,n;
int matrix[M][N];
int arr[110];
int dp[110];
int turn(int x)
{
	if(x==0)
		return m;
	else if(x==m+1)
		return 1;
	else
		return x;
}
long long Min(long long x,long long y)
{
	return x>y?y:x;
}
int main()
{
	while (scanf("%d %d",&m,&n)!= EOF) 	
	{ 			
		long long ads=0,staads[11]={0};
		for (int i = 1; i <=m; i++) 
			for (int j = 1; j <=n; j++) 
			{ 				
				scanf("%lld", &matrix[i][j]);  	
			}
		memset(dp,Max,sizeof(dp));
		for(int i=n;i<=1;i--)
		{
			for(int i=1;i<=m;i++)
			{
				dp[j][i]=Min(dp[][]+,dp[][]);
			}
		}
		printf("%lld\n",);
	}
	
	return 0;
}
