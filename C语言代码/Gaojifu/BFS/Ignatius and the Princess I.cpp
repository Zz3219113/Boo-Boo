#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int flag[105][105];
int time;
int way[105][105]; 
char maze[105][105];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node
{
	int x,y,time;                                                                                        
	bool operator < (const node &a) const {  
        return time>a.time;//最小值优先  
    } 
};
void print(int x,int y)
{

    int nx,ny;
    if(!way[x][y])
        return;
    nx=x-dir[way[x][y]-1][0];
    ny=y-dir[way[x][y]-1][1];
    print(nx,ny);
    printf("%ds:(%d,%d)->(%d,%d)\n",time++,nx,ny,x,y);
    if(maze[x][y]>='1'&&maze[x][y]<='9')
    {
    	int cnt=maze[x][y]-'0';
		while(cnt--)
    {
        printf("%ds:FIGHT AT (%d,%d)\n",time++,x,y);
    }
	}
    
}
int main()
{
	int n,m,ty,tx;
	priority_queue<node>q;
	node sta,pre,cur;
	Loop:while(~scanf("%d %d",&n,&m))
	{
		memset(maze,0,sizeof(maze));
		memset(way,0,sizeof(way));
		memset(flag,0,sizeof(flag));
		getchar();
		for(int i=0;i<n;i++)
			gets(maze[i]);
		sta.x=0;sta.y=0;sta.time=0;
		q.push(sta);
		flag[0][0]=1;
		while(!q.empty())
		{	
			pre=q.top();
			q.pop();
			if(pre.y==m-1&&pre.x==n-1)
			{	time=1;
				printf("It takes %d seconds to reach the target position, let me show you the way.\n",pre.time);
				time=1;
				print(n-1,m-1);
				printf("FINISH\n");
				goto Loop;
			}
			for(int i=0;i<4;i++)
			{
				cur.x=pre.x+dir[i][0];
				cur.y=pre.y+dir[i][1];
				if(cur.x>=0&&cur.x<n&&cur.y>=0&&cur.y<m&&maze[cur.x][cur.y]!='X'&&flag[cur.x][cur.y]==0)
				{
					if(maze[cur.x][cur.y]>'0'&&maze[cur.x][cur.y]<='9')
					{
						cur.time=pre.time+maze[cur.x][cur.y]-'0'+1;
						way[cur.x][cur.y]=i+1;
						q.push(cur);
						flag[cur.x][cur.y]=1;
					}
					else
					{
						cur.time=pre.time+1;
						way[cur.x][cur.y]=i+1;
						q.push(cur);
						flag[cur.x][cur.y]=1;
					}
				}
			}
		}
		printf("God please help our poor hero.\n");
	}
	return 0;
}

