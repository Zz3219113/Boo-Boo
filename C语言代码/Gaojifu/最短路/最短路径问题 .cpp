#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
#define Max 0x3f3f3f3f
using namespace std;
int dis[1010];
int cost[1010][1010];
int map[1010][1010];
int ans[1010];
int flag[1010];
int st,en,n,m;
void Dis()
{
	int i,j,temp,k;
	dis[st]=0;
	ans[st]=0;
	for(i=1;i<n;i++)
	{
		temp=Max;
		for(j=1;j<=n;j++)
		{
			if(flag[j]==0&&temp>dis[j])
			{
				temp=dis[j];
				k=j;
			}	
		}
		flag[k]=1;
		for(j=1;j<=n;j++)
		{
			if(flag[j]==0)
			{
				if(map[k][j]+dis[k]<dis[j])
				{
					dis[j]=dis[k]+map[k][j];
					ans[j]=ans[k]+cost[k][j];
				}
				else if(map[k][j]+dis[k]==dis[j])
				{
					if(ans[j]>ans[k]+cost[k][j])
						ans[j]=ans[k]+cost[k][j];
				}
			}
			
		}
	}
}
int main()
{
	int x,y,mon,temp;
	while(~scanf("%d%d",&n,&m))
	{
		if(m==0&&n==0)
			break;
		memset(ans,Max,sizeof(ans));
		memset(flag,0,sizeof(flag));
		memset(dis,Max,sizeof(dis));
		memset(map,Max,sizeof(map));
		memset(cost,Max,sizeof(cost));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&x,&y,&temp,&mon);
			if(map[x][y]>temp)
			{
				map[y][x]=map[x][y]=temp;
				cost[x][y]=cost[y][x]=mon;
			}
			else if(map[x][y]==temp)
			{
				if(cost[x][y]>mon)
				cost[x][y]=cost[y][x]=mon;
			}
		}
		scanf("%d%d",&st,&en);
		Dis();
		printf("%d %d\n",dis[en],ans[en]);
	}
	return 0;
}
