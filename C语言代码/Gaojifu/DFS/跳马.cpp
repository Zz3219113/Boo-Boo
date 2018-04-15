#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int flag[100][100]; 
int m,n;
int dfs(int x,int y)
{	if(x<1||y<1||y>n||x>m)
		return 0;
	if(x==m&&y==n)
		return 1;
	return dfs(x+1,y+2)+dfs(x+2,y+1)+dfs(x-1,y+2)+dfs(x-2,y+1);
}
int main()
{
	scanf("%d%d",&m,&n);
	printf("%d\n",dfs(1,1));
	return 0;
}

