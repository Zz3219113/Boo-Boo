#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int flag[21][21];
char map[21][21];
int W,H,ans;
int sx,sy;
void dfs(int x,int y)
{
	flag[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(tx>=0&&ty>=0&&tx<H&&ty<W&&flag[tx][ty]==0&&map[tx][ty]!='#')
		{
			ans++;
			dfs(tx,ty);
		}
	}
}
int main()
{
	while(~scanf("%d %d",&W,&H)&&W!=0||H!=0)
	{
		memset(flag,0,sizeof(flag));
		ans=1;
		getchar();
		for(int i=0;i<H;i++)
		{
			gets(map[i]);
			for(int j=0;j<W;j++)
				if(map[i][j]=='@')
				{
					sx=i;
					sy=j;
				}
		}
		dfs(sx,sy);
		printf("%d\n",ans);
	}
	
}
