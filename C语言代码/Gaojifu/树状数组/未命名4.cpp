#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100010;
int c[MAXN];
struct Node
{
    int S,E;
    int index;
}node[MAXN];


int n;
int cnt[MAXN];
bool cmp(Node a,Node b)
{
    if(a.E==b.E)return a.S<b.S;
    return a.E>b.E;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int val)
{
    while(i<=n)
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&node[i].S,&node[i].E);
            node[i].index=i;
        }
        sort(node+1,node+n+1,cmp);
        memset(c,0,sizeof(c));
        memset(cnt,0,sizeof(cnt));
        cnt[node[1].index]=0;
        add(node[1].S+1,1);
        for(int i=2;i<=n;i++)
        {
            if(node[i].E==node[i-1].E&&node[i].S==node[i-1].S)
               cnt[node[i].index]=cnt[node[i-1].index];
            else
                cnt[node[i].index]=sum(node[i].S+1);
            add(node[i].S+1,1);
        }
        printf("%d",cnt[1]);
        for(int i=2;i<=n;i++)
          printf(" %d",cnt[i]);
        printf("\n");
    }
    return 0;
}
