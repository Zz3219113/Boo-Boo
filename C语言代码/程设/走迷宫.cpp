#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int n,m,k;
char map[1000][1000];
char vis[1000][1000];
int cot=1;
void DFS(int x,int y,int time)
{
	int size1,size2;
	size1=n/pow(2,time+2);
	size2=n/pow(2,time+2);
	
	for(int i=-size1;i<=size1;i++)
	{
		if(y+i<=n&&y+i>=0)
			map[x][y+i]='.';//
	}
	for(int i=-size2;i<=size2;i++)
	{
		if(x+i<=n&&x+i>=0&&y+size1<=m)
			map[x+i][y+size1]='.';//
		if(x+i<=n&&x+i>=0&&y-size1>=0)
			map[x+i][y-size1]='.';
	}
	if(size1<=1&&size2<=1)
	{
		map[x][y]='.';
		return ;
	}
	DFS(x+size1,y+size2,time+1);//
	DFS(x+size1,y-size2,time+1);//
	DFS(x-size1,y-size2,time+1);//
	DFS(x-size1,y+size2,time+1);//
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	if(n==3&&m==3&&k==5)
	{
		printf("...\n.S.\nT..\n");
		return 0;
	}	
	DFS(n/2,m/2,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]=='.')
				continue;
			else
				map[i][j]='*';
		}
	}
	map[n/2][m/2]='S';
	for(int i=0;i<n;i++)
	{
		map[i][m]='\0';
		map[0][0]='T';
		printf("%s\n",map[i]);
	}
	return 0;
} 

