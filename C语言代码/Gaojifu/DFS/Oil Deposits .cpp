#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int ans;
int n,m,sy,sx,sum;
char map[110][110];
void dfs(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||map[x][y]!='@')return;
	else
	{
		map[x][y]='*';
		dfs(x-1,y);
		dfs(x,y-1);
		dfs(x+1,y);
		dfs(x,y+1);
		dfs(x+1,y+1);
		dfs(x+1,y-1);
		dfs(x-1,y+1);
		dfs(x-1,y-1);
		
	}
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		if(m==0 &&n==0 )
			break;
		sum=0;
		memset(map,0,sizeof(map));
		getchar();
		for(int i=0;i<n;i++)
		{
			scanf("%s",map[i]);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(map[i][j]=='@')
				{
					sy=j;
					sx=i;
					dfs(sx,sy);
					sum++;
				}
			}
		printf("%d\n",sum);
	}
	return 0;
} 
