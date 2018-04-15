#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	short x;
	short y;
	int step;
}arr[4000010];
short flag=0;
int cont=0,start=0,endl=0;
short E[2000010][2];
int n,m;
short dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char maze[2000][2000],vis[2000][2000];
int main()
{
	scanf("%d %d",&n,&m);
	getchar();
	struct node end;
	for(int i=0;i<n;i++)//input
	{
		char c;short tem=0;
		while((c=getchar())!='\n')
		{
			if(c=='N')
			{
				arr[start].x=i;
				arr[start].y=tem;
				arr[start].step=0;
				vis[i][tem]=1;
			}
			else if(c=='C')
			{
				end.y=tem;
				end.x=i;
				end.step=0;
			}
			else if(c=='E')
			{
				E[cont][0]=i;
				E[cont][1]=tem;
				cont++;
			}
			maze[i][tem++]=c;
		}
	}
	while(start<=endl)
	{
		if(arr[start].x==end.x&&arr[start].y==end.y)//juge
		{
			printf("%d\n",arr[start].step);
			flag=1;
			break;
		}
		for(int i=0;i<4;i++)
		{
			short tx=arr[start].x+dir[i][1];
			short ty=arr[start].y+dir[i][0];
			if((tx>=0&&tx<n)&&(ty>=0&&ty<m)&&vis[tx][ty]==0)
			{
				if(maze[tx][ty]=='M')
				{
					vis[tx][ty]=1;
					continue;
				}
				else if(maze[tx][ty]=='E')
				{
					for(int i=0;i<cont;i++)
					{
						endl++;
						arr[endl].x=E[i][0];
						arr[endl].y=E[i][1];
						arr[endl].step=arr[start].step+1;
						vis[E[i][0]][E[i][1]]=1;
					}
				}
				else
				{
					endl++;
					arr[endl].x=tx;
					arr[endl].y=ty;
					arr[endl].step=arr[start].step+1;
					vis[tx][ty]=1;
				}
			}
		}
		start++;
	}
	if(flag==0)
		printf("Not Happy\n");
	return 0;
}
