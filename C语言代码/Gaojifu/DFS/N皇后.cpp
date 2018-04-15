#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
int ans;
int map[10][10];
using namespace std;
int N,row;
bool check(int row,int col)
{
	for(int i=0;i<row;i++)       //Í¬ÐÐ 
	{
		if(map[i][col])
			return false;
		for(int j=0;j<N;j++)          //Ð±Ïò 
			if(map[i][j])
			{
				if(fabs(i-row)==fabs(col-j))
					return 0;
				else
					break;
			}
	}
	return true;
}
int dfs(int row)
{
	if(row>=N)
		ans++;
	for(int col=0;col<N;col++)
	{
		if(check(row,col))
		{
			map[row][col]=1;
			dfs(row+1);
			map[row][col]=0;
		}
		
	}
}
int main()
{
	while(~scanf("%d",&N),N)
	{
		memset(map,0,sizeof(map));
		ans=0;
		dfs(0);
		printf("%d\n",ans);
	
	}	
	return 0;
}

