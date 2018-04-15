#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;	
}
int dp[2002][2002];
int main()
{
	int n,i,j,a[2002];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=n;i>0;i--)
		for(j=i;j<=n;j++)
			dp[i][j]=max(dp[i+1][j]+a[i]*(n+i-j),dp[i][j-1]+a[j]*(n+i-j));
	printf("%d\n",dp[1][n]);
}

