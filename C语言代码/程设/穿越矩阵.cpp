#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 0x3f3f3f3f
long long min(long long x,long long y)
{
	return x>y?x:y;
}
int arr[12];
long long map[12][110];
int ads[110][110];
long long dp[110][110];
int main()
{
	int n,m;
	Loop:while(~scanf("%d %d",&m,&n))
	{
		int t=0,tar=1<<30,min,temp=1<<30;
		memset(ads,0,sizeof(ads));
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				scanf("%lld",&map[i][j]);
		if(m==1)
		{
			long long end=0;
			for(int i=1;i<=n;i++)
			{
				end+=map[1][i];
				if(i==1)
					printf("1");
				else
					printf(" 1");
			}
			printf("\n");
			printf("%lld\n",end);
			goto Loop;
		}
		int x;
		for(int i=n-1;i>=1;i--)
		{
			for(int j=1;j<=m;j++)
			{
				int a1,a2,a3;
				a1=j-1>0?j-1:m;
				a2=j;
				a3=j+1>m?1:j+1;
				x=a1;
				int min=map[a1][i+1];
				if(min>map[a2][i+1])
				{
					min=map[a2][i+1];
					x=a2;
				}
				else if(min==map[a2][i+1])
				{
					if(a2<=x)
					{
						x=a2;
					}
				}
				if(min>map[a3][i+1])
				{
					min=map[a3][i+1];
					x=a3;
				}
				else if(min==map[a3][i+1])
				{
					if(a3<=x)
					{
						x=a3;
					}
				}
				map[j][i]+=map[x][i+1];
				ads[j][i]=x;
			}
		}
		/*for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				printf("%d ",map[i][j]);*/
		x=1;
		min=map[1][1];
		for(int i=2;i<=m;i++)
		{
			if(min>map[i][1])
			{
				min=map[i][1];
				x=i;
			}
		}
		t=x;
		for(int i=1;i<=n;i++)
		{
			if(i==1)
				printf("%d",x);
			
			else
			{
				printf(" %d",ads[x][i-1]);
				x=ads[x][i-1];
			}
		}
		printf("\n");
		printf("%lld\n",map[t][1]);
	}
	return 0;
}
