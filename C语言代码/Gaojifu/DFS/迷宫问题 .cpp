#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int flag[6][6];
int way[6][6];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node
{
	int x,y,step;
};
void print(int x,int y)
{
	int nx,ny;
	if(!way[x][y])
		return;
	nx=x-dir[way[x][y]-1][0];
	ny=y-dir[way[x][y]-1][1];
	print(nx,ny);
	printf("(%d,%d)\n",nx,ny);
}
int main()
{
	int maze[6][6];
	int tx,ty;
	memset(way,0,sizeof(way));
	memset(flag,0,sizeof(flag));
	memset(maze,0,sizeof(maze));
	node sta,pre,cur;
	queue<node>q;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&maze[i][j]);
	sta.x=0,sta.y=0,sta.step=0;
	q.push(sta);
	flag[0][0]=1;
	while(!q.empty())
	{
		pre=q.front();
		q.pop();
		if(pre.x==4&&pre.y==4)
		{
			print(4,4);
			printf("(4,4)\n");
			break;
		}
		for(int i=0;i<4;i++)
		{
			tx=pre.x+dir[i][0];
			ty=pre.y+dir[i][1];
			if(tx>=0&&tx<=4&&ty>=0&&ty<=4&&flag[tx][ty]==0&&maze[tx][ty]==0)
			{
				cur.x=tx;
				cur.y=ty;
				cur.step=pre.step+1;
				way[tx][ty]=i+1;
				q.push(cur);
				flag[tx][ty]=1;
			}
		}
	}
	
	return 0;
} 

