#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int flag[101][101];
struct node
{
	int n,m,s,step;
};
int main()
{
	int n,m,s,tm,tn,ts;
	Loop:while(~scanf("%d %d %d",&s,&n,&m))
	{
		getchar();
		memset(flag,0,sizeof(flag));
		if(n==0&&m==0&&s==0)
			break;
		if(s%2)
		{
			printf("NO\n");
			continue;
		}
		node sta,cur,pre;
		if(m>n)
		{
			int t;
			t=n;
			n=m;
			m=t;
		}
		sta.n=0;
		sta.m=0;
		sta.s=s;
		sta.step=0;
		queue<node>q;
		q.push(sta);
		while(!q.empty())
		{
			pre=q.front();
			q.pop();
			if(pre.n == pre.s && pre.s == s/2)
			{
				printf("%d\n",pre.step);
				goto Loop; 
			}
			if(pre.s+pre.m>m)     //s->m;
			{
				tn=pre.n;                             
				tm=m;
				ts=pre.s+pre.m-m;
			}
			else
			{
				tn=pre.n;
				tm=pre.s+pre.m;
				ts=0;
			}
			if(flag[tn][tm]==0)
			{
				cur.n=tn;
				cur.m=tm;
				cur.s=ts;
				cur.step=pre.step+1;
				q.push(cur);
				flag[tn][tm]=1;
			}
			if(pre.s+pre.n>n)     //s->n;
			{	
				tn=n;                             
				tm=pre.m;
				ts=pre.s+pre.n-n;
			}
			else
			{
				tn=pre.s+pre.n;
				tm=pre.m;
				ts=0;
			}
			if(flag[tn][tm]==0)
			{
				cur.n=tn;
				cur.m=tm;
				cur.s=ts;
				cur.step=pre.step+1;
				q.push(cur);
				flag[tn][tm]=1;
			}
			if(pre.s+pre.n>s)     //n->s;
			{	
				tn=pre.s+pre.n-s;                             
				tm=pre.m;
				ts=s;
			}
			else
			{
				tn=0;
				tm=pre.m;
				ts=pre.s+pre.n;
			}
			if(flag[tn][tm]==0)
			{
				cur.n=tn;
				cur.m=tm;
				cur.s=ts;
				cur.step=pre.step+1;
				q.push(cur);
				flag[tn][tm]=1;
			}
			if(pre.m+pre.n>m)     //n->m;
			{	
				tn=pre.m+pre.n-m;                             
				tm=m;
				ts=pre.s;
			}
			else
			{
				tn=0;
				tm=pre.m+pre.n;
				ts=pre.s;
			}
			if(flag[tn][tm]==0)
			{
				cur.n=tn;
				cur.m=tm;
				cur.s=ts;
				cur.step=pre.step+1;
				q.push(cur);
				flag[tn][tm]=1;
			}
			if(pre.m+pre.n>n)     //m->n;
			{	
				tn=n;                             
				tm=pre.m+pre.n-n;
				ts=pre.s;
			}
			else
			{
				tn=pre.n+pre.m;
				tm=0;
				ts=pre.s;
			}
			if(flag[tn][tm]==0)
			{
				cur.n=tn;
				cur.m=tm;
				cur.s=ts;
				cur.step=pre.step+1;
				q.push(cur);
				flag[tn][tm]=1;
			}
			if(pre.m+pre.s>s)     //m->s;
			{	
				tn=pre.n;                             
				tm=pre.m+pre.s-s;
				ts=s;
			}
			else
			{
				tn=pre.n;
				tm=0;
				ts=pre.s+pre.m;
			}
			if(flag[tn][tm]==0)
			{
				cur.n=tn;
				cur.m=tm;
				cur.s=ts;
				cur.step=pre.step+1;
				q.push(cur);
				flag[tn][tm]=1;
			}
		}
		printf("NO\n");
	}
	return 0;
}
