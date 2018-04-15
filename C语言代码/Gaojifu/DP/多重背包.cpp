#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int a[102],c[102],dp[100005],n,m;
void zopack(int value,int weight)//零一背包 
{
	for(int i=m;i>=value;i--)
		dp[i]=max(dp[i],dp[i-value]+weight);
}
void cpack(int value,int weight)//完全背包 
{
	for(int i=weight;i<=m;i++)
		dp[i]=max(dp[i],dp[i-value]+weight);
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(dp,0,sizeof(dp));
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[j]);
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]*a[i]>=m)
				cpack(a[i],a[i]);
			else
			{
				int k=1;
				while(k<c[i])//二进制优化 
				{
					zopack(k*a[i],k*a[i]);
					c[i]-=k;
					k*=2;
				}
				zopack(c[i]*a[i],a[i]*c[i]);
			}
		}
		int count=0;
		for(int i=1;i<=m;i++)
		{
			if(dp[i]==i)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
