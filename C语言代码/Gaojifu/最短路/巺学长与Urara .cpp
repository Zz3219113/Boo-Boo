#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
#define Max 0x3f3f3f3f
using namespace std;
int map[510][510];
int flag[210];
int dis[510];
int m,n;
void Dis(int x,int n)
{
	memset(dis,Max,sizeof(dis));
	memset(flag,0,sizeof(flag));
	dis[x]=0;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		int temp=Max;
		for(j=0;j<n;j++)
		{
			if(flag[j]==0)
			{
				if(temp>dis[j])
				{
					temp=dis[j];
					k=j;
				}
			}
			
		}
		flag[k]=1;
			for(j=0;j<n;j++)
			{
				if(flag[j]==0)
				{
					if(dis[j]>dis[k]+map[k][j])
						dis[j]=dis[k]+map[k][j];
				}
			}
	}
	return dis[f];
}
int main()
{
	while(~scanf("%d%d%d%d%d",&n,&m,&s1,&s2,&f))
	{
		
		memset(map,Max,sizeof(map));
		
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&temp);
			if(map[x][y]>temp)
				map[x][y]=map[y][x]=tmep;
		}
		int ans1=Dis(s1,n);
		if(ans1==Max)
			printf("-1",ans1);
		else
			printf("%d",ans1);
		int ans2=Dis(s2,n);
		if(ans2==Max)
			printf(" -1\n");
		else
			printf(" %d\n",ans2);
		
	}
	return ;
}
