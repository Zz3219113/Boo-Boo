#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
struct node{  
    int x,y,step;  
    bool operator < (const node &a) const {  
        return step>a.step;//最小值优先  
    }  
}; 
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int flag[210][210];
int main()
{
	int n,m,tx,ty,ex,ey;
	priority_queue<node>q;
	char maze[210][210];
	node sta,pre,cur;
	Loop:while(~scanf("%d%d",&n,&m))
	{
		getchar();
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;i++)
			gets(maze[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]=='r')
				{
					sta.x=j;
					sta.y=i;
					sta.step=0;
					q.push(sta);
					flag[i][j]=1;
				}
				if(maze[i][j]=='a')
				{
					ex=j;
					ey=i;
				}
			}
		while(!q.empty())
		{
			pre=q.top();
			q.pop();
			if(pre.x==ex&&pre.y==ey)
			{
				printf("%d\n",pre.step);
				goto Loop;
			}
			for(int i=0;i<4;i++)
			{
				tx=pre.x+dir[i][0];
				ty=pre.y+dir[i][1];
				if(tx>=0&&tx<m&&ty>=0&&ty<n&&flag[ty][tx]==0&&maze[ty][tx]!=-1)
				{
					if(maze[ty][tx]=='x')
					{
						cur.x=tx;
						cur.y=ty;
						cur.step=pre.step+2;
						q.push(cur);
						flag[ty][tx]=1;
					}
					else
					{
						cur.x=tx;
						cur.y=ty;
						cur.step=pre.step+1;
						q.push(cur);
						flag[ty][tx]=1;
					}
				}
			}
		}
		printf("Poor ANGEL has to stay in the prison all his life.\n");
	}
	return 0;
}

