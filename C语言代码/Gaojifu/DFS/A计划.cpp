#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,T,bala;
char maze[2][20][20];
int flag[2][20][20];
struct node{
	int x,y,z,step;
};
int  bfs()
{
	node sta,pre,cur;
	queue<node>q;
	sta.x=0;sta.y=0;sta.step=0;
	flag[0][0][0]=1;
	q.push(sta);
	while(!q.empty())
	{
		pre=q.front();
		q.pop();
		if(maze[pre.z][pre.y][pre.x]=='P')
		{
			return pre.step;
			break;
		}
		for(int i=0;i<4;i++)
		{
			int tx=pre.x+dir[i][1];
			int ty=pre.y+dir[i][0];
			cur.x=tx;
			cur.y=ty;
			cur.z=pre.z;
			if(maze[pre.z][ty][tx]=='#')
			{
				cur.z^=1;
			}
			if(tx>=0&&ty>=0&&tx<n&&ty<m&&flag[pre.z][ty][tx]==0&&maze[pre.z][ty][tx]!='*')
			{
				cur.step=pre.step+1;
				flag[cur.z][ty][tx]=1;
				q.push(cur);
			}
		}
	}
	return 0x3f3f3f3f;
	
}
int main()
{
	int t;
	scanf("%d",&t);
	char lj[20];
	while(t--)
	{	
		memset(maze,0,sizeof(maze));
		memset(flag,0,sizeof(flag));
		scanf("%d %d %d",&m,&n,&T);
		for(int j=0;j<2;j++) 
		for(int i=0;i<m;i++)
		{
			scanf("%s",maze[j][i]);
		}
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(maze[0][i][j]==maze[1][i][j]&&maze[0][i][j]=='#'||maze[0][i][j]=='#'&&maze[1][i][j]=='*'||maze[1][i][j]=='#'&&maze[0][i][j]=='*')
				{
					maze[0][i][j]='*';
					maze[1][i][j]='*';
				}
		int time=bfs();
		if(time>T)
		printf("NO\n");
		else
		printf("YES\n");
		
	}
	return 0;
}

