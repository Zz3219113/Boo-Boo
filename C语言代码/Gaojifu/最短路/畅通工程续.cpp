#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
#define Max 0x3f3f3f3f
using namespace std;
int map[210][210];
int flag[210];
int dis[210];
int n,m;
void Dis(int x,int n)
{
	int i,j;
	memset(dis,Max,sizeof(dis));
	dis[x]=0;
	for(i=0;i<n;i++)
	{
		int tem=Max;
		int k;
		for(j=0;j<n;j++)
		{
			
			if(flag[j]==0&&dis[j]<tem)
			{
				tem=dis[j];
				k=j;
			}
		}
		flag[k]=1;
		for(j=0;j<n;j++)
		{
			if(flag[j]==0)
			dis[j]=min(dis[j],dis[k]+map[k][j]);
		}
	}
}
int main()
{
	int a,c,b,x,y;
	while(~scanf("%d %d",&n,&m))
	{
		memset(flag,0,sizeof(flag));
		memset(map,Max,sizeof(map));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(map[a][b]>c)
				map[a][b]=map[b][a]=c;
		}
		scanf("%d%d",&x,&y);
		Dis(x,n);
		if(dis[y]==Max)
			printf("-1\n");
		else
			printf("%d\n",dis[y]);
	}
	return 0;
}
