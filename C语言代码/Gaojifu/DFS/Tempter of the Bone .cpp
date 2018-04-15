#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int flag1,ex,ey,sy,sx;
int N,M,T;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int flag[10][10];
char maze[10][10];
int abs(int p)
{
	return p>=0?p:-p;
}
void dfs(int x,int y,int step)
{
	int xx,yy,i;
	if(flag1==1)
		return ;
	if(x==ex&&y==ey&&step==T)
	{
		flag1=1;
		return;
	}
	int mindis=abs(x-ex)+abs(y-ey);
	if(mindis>T-step||(mindis+T-step )%2!=0)
		return;
	for(i=0;i<4;i++)
	{
		 xx=x+dir[i][0];
		 yy=y+dir[i][1];
		if(xx>=0&&yy>=0&&xx<N&&yy<M&&flag[xx][yy]==0&&maze[xx][yy]!='X')
		{  
			flag[xx][yy]=1;
			dfs(xx,yy,step+1);
			flag[xx][yy]=0;
		}
	}
}
int main()
{
	while(~scanf("%d%d%d",&N,&M,&T))
	{	memset(flag,0,sizeof(flag));
		
		int cnt=0;
		if(N==0&&M==0&&T==0)
			break;
		for(int i=0;i<N;i++)
		{
			scanf("%s",maze[i]);
			for(int j=0;j<M;j++)
			{
				if(maze[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				if(maze[i][j]=='D')
				{
					ex=i;
					ey=j;
				}
				if(maze[i][j]=='X')
					cnt++; 
			}
		}
		if(M*N-cnt-1<T)
		{
			printf("No\n");
			continue;
		}
		flag1=0;
		flag[sx][sy]=1;
		dfs(sx,sy,0);
		if(flag1==1)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
