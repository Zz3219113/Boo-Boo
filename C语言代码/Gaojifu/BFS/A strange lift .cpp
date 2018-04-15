#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int visited[210];
struct node
{
	int x,step;
};
int main()
{
	int N,A,B,floor[210];
	Loop:while(~scanf("%d",&N)&&N!=0)
	{
		memset(visited,0,sizeof(visited));
		scanf("%d %d",&A,&B);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&floor[i]);
		}
		node sta,pre,cur;
		sta.x=A;
		sta.step=0;
		queue<node>q;
		q.push(sta);
		while(!q.empty())
		{
			pre=q.front();
			q.pop();
			if(pre.x==B)
			{
				printf("%d\n",pre.step);
				goto Loop;
			}
			cur.x=floor[pre.x]+pre.x;
			if(0<cur.x&&cur.x<=200&&visited[cur.x]==0)//up
			{
				cur.step=pre.step+1;
				q.push(cur);
				visited[cur.x]=1;
			}
			cur.x=pre.x-floor[pre.x];
			if(0<cur.x&&cur.x<=200&&visited[cur.x]==0)//down
			{
				cur.step=pre.step+1;
				q.push(cur);
				visited[cur.x]=1;
			}
		}
		printf("-1\n");
	}
}

