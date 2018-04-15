#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
#define Max 0x3f3f3f3f
using namespace std;
int map[1010][1010];
int dis[1010];
int flag[1010],shop[1010];
int n,m,s,sta;
void Dis()
{
	int i,j;
	dis[0]=0; 
	for(int x=0;x<sta;x++)
	{
		map[0][shop[x]]=0;
	}
	for(i=0;i<=n;i++)
	{
		int temp=Max;
		int k;
		for(j=0;j<=n;j++)
		{
			if(flag[j]==0&&temp>dis[j])
			{
				temp=dis[j];
				k=j;
			}
		}
		flag[k]=1;
		for(j=0;j<=n;j++)
		{
			if(flag[j]==0)
			dis[j]=min(dis[j],dis[k]+map[k][j]);
		}
	}
}
int main()
{
	int x,y,temp;
	while(~scanf("%d%d%d",&n,&m,&s))
	{
		memset(flag,0,sizeof(flag));
		memset(map,Max,sizeof(map));
		memset(dis,Max,sizeof(dis));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&temp);
			if(map[x][y]>temp)
				map[x][y]=temp;
		}
		scanf("%d",&sta);
		for(int i=0;i<sta;i++)
			scanf("%d",&shop[i]);
		Dis();
		if(dis[s]==Max)
			printf("-1\n");
		else
			printf("%d\n",dis[s]);
	}
	return 0;
}

