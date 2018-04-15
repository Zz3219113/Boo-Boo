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
int flag[1010];
int dis[1010];
int n,m;
void Dis()
{
	int tem=Max,i,j;
	dis[1]=0;
	for(i=1;i<=n;i++)
	{	
		int k;
		for(j=1;j<=n;j++)
		{
			if(flag[j]==0&&tem>dis[j])
			{
				tem=dis[j];
				k=j;
			}
		}
		flag[k]=1;
		for(j=1;j<=n;j++)
			if(flag[j]==0&&dis[k]+map[k][j]<dis[j])
				dis[j]=dis[k]+map[k][j];
	}
}
int main()
{
	int x,y,temp;
	while(~scanf("%d%d",&n,&m))
	{
		memset(flag,0,sizeof(flag));
		memset(dis,Max,sizeof(dis));
		memset(map,Max,sizeof(map));
		if(n==0&&m==0)
			break;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&temp);
			if(map[x][y]>temp)
				map[y][x]=map[x][y]=temp;
		}
		Dis();
		printf("%d\n",dis[n]);
	}
	return 0;
}
