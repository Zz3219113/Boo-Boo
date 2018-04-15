#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
struct node
{
	long long x,step;	
};
int  flag[2000010];
int main()
{
	long long N,K;
	while(~scanf("%lld %lld",&N,&K))
	{
		memset(flag,0,sizeof(flag));
	node sta,pre,cur;
	sta.x=N;
	sta.step=0;
	queue<node>q;
	q.push(sta);
	flag[sta.x]=1;
	while(!q.empty())
	{
		pre=q.front();
		q.pop();
		if(pre.x==K)
		{
			printf("%lld\n",pre.step);
			break;
		}
		cur.x=pre.x+1;
		if(0<=cur.x&&cur.x<=1000000)
		{
			if(flag[cur.x]==0)
			{
				cur.step=pre.step+1;
				q.push(cur);
				flag[cur.x]=1;
			}
		}
		cur.x=pre.x-1;
		if(0<=cur.x&&cur.x<=1000000)
		{
			if(flag[cur.x]==0)
			{
				cur.step=pre.step+1;
				q.push(cur);
				flag[cur.x]=1;
			}
		}
		cur.x=pre.x*2;
		if(0<=cur.x&&cur.x<=1000000)
		{
			if(flag[cur.x]==0)
			{
				cur.step=pre.step+1;
				q.push(cur);
				flag[cur.x]=1;
			}
		}
	}
	}
	return 0;
}

