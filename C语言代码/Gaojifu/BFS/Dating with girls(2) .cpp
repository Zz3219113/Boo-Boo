#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int flag[110][110][11];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
struct node
{
	int x,y,step;
};
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	Loop:while(t--)
	{
	int r,c,k,ex,ey;
	node sta,pre,cur;
	queue<node>q;
	char maze[100][100];
	memset(flag,0,sizeof(flag));
	scanf("%d%d%d",&r,&c,&k);        //in
	getchar();
	for(int i=0;i<r;i++)
	{
		gets(maze[i]);
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(maze[i][j]=='Y')
			{
				sta.x=j;
				sta.y=i;
				sta.step=0;
				q.push(sta);
				flag[j][i][0]=1;
			}
			if(maze[i][j]=='G')
			{
				ex=j;
				ey=i;
			}
		}
	}
	while(!q.empty())
	{
		pre=q.front();
		q.pop();
		if(pre.x==ex&&pre.y==ey)
		{
			printf("%d\n",pre.step);
			goto Loop;
		}
			for(int i=0;i<4;i++)
			{
				int tx=pre.x+dir[i][0];
				int ty=pre.y+dir[i][1];
				if(tx<c&&tx>=0&&ty<r&&ty>=0&&(maze[ty][tx]!='#'||(pre.step+1)%k==0)&&flag[ty][tx][(pre.step+1)%k]==0)
				{
					cur.x=tx;
					cur.y=ty;
					cur.step=pre.step+1;
					q.push(cur);
					flag[ty][tx][(pre.step+1)%k]=1;
				}
			}
	}
	printf("Please give me another chance!\n");
	}
	return 0;
}

