#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int cnt;
char map[15][15];
int flag[15][15];
struct node{
	int x, y;
};
int x,y;
char c;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool check(int x,int y)
{
	if(x<0||x>8||y<0||y>8)
		return true;
	return false;
}
int bfs1(int x,int y)
{
	memset(flag,0,sizeof(flag));
	node sta,pre,cur;
	queue<node>q;
	sta.x=x;sta.y=y;
	q.push(sta);
	flag[x][y]=1;
	while(!q.empty())
	{
		pre=q.front();
		q.pop();
		if(map[pre.x][pre.y]=='.')
		{
			return 0;
		}
		for(int i=0;i<4;i++)
		{
			int ty=pre.y+dir[i][0];
			int tx=pre.x+dir[i][1];
			if(!check(tx,ty)&&(map[tx][ty]=='.'||map[tx][ty]==map[x][y]&&map[x][y]!=0&&map[tx][ty]!=c)&&flag[tx][ty]==0)
			{
				cur.x=tx;
				cur.y=ty;
				q.push(cur);
				flag[tx][ty]=1;
			}
		}
	}
	if(cnt==0)
	{
		printf("K.O.\n");
		cnt=1;	
		   return 0;
	}
		
}
int bfs2(int x,int y)
{
	memset(flag,0,sizeof(flag));
	node sta,pre,cur;
	sta.x=x;sta.y=y;
	queue<node>q;
	q.push(sta);
	flag[x][y]=1;
	while(!q.empty())
	{
		pre=q.front();
		q.pop();
		if(map[pre.x][pre.y]=='.')
		{
			if(cnt==0)
			{
				printf("Safe\n");
				cnt=1;
			}
			return 0;
		}
		for(int i=0;i<4;i++)
		{
			int ty=pre.y+dir[i][0];
			int tx=pre.x+dir[i][1];
			if(!check(tx,ty)&&(map[tx][ty]=='.'||map[tx][ty]==c)&&flag[tx][ty]==0)
			{
				cur.x=tx;
				cur.y=ty;
				q.push(cur);
				flag[tx][ty]=1;
			}
		}
	}
	if(cnt==0)
	{
	printf("Suicide\n");
	cnt=1;
	}
	return 0;	
}
int go(int x,int y)
{
	int xx,yy;
	for(int i=0;i<4;i++)
	{
		xx=x+dir[i][1];
		yy=y+dir[i][0];
		if(check(xx,yy))
			continue;
		if(map[xx][yy]!=c)
			bfs1(xx,yy);	
	}
	bfs2(x,y);
	return 0;
}
int main()
{
	cnt=0;
	memset(map,0,sizeof(map));
	for(int i=0;i<9;i++)
	{	
		scanf("%s",map[i]);
	}
	scanf("%d %d %c",&x,&y,&c);
	map[x][y]=c;
	go(x,y);
	return 0;
}
