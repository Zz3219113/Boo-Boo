#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
char arr[110];
int map[50][50];
int flag[50][50];
struct node{
	int x,y;
};
int main()
{
	Loop:while(~scanf("%s",arr))
	{
		node pre,cur;
		queue<node>q;
		int len=strlen(arr);
		if(arr[0]=='0')
		{
			for(int i=0;i<26;i++)
			{
				if(map[0][i]==1)
				{
					node sta;
					sta.x=0;
					sta.y=i;
					q.push(sta);
				}
			}
			while(!q.empty())
			{
				pre=q.front();
				q.pop();
				if(pre.y==1&&map[pre.x][pre.y]==1)
				{
					printf("yes\n");
					memset(arr,0,sizeof(arr));
					memset(map,0,sizeof(map));
					memset(flag,0,sizeof(flag));
					goto Loop;
				}
				for(int i=0;i<26;i++)
				{
					if(map[pre.y][i]==1)
					{
						if(flag[pre.y][i]==0)
						{
							cur.x=pre.y;
							cur.y=i;
							q.push(cur);
							flag[pre.y][i]=1;
						}
					}
				}
			}
			printf("no\n");
			memset(arr,0,sizeof(arr));
			memset(map,0,sizeof(map));
			memset(flag,0,sizeof(flag));
			goto Loop;
		}
		int a=arr[0]-'a';
		int b=arr[len-1]-'a';
		map[a][b]=1;
	}
	return 0;
}
