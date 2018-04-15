#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
int N;
using namespace std;
struct Act
{
	int start;
	int end;
}act[1000];
bool cmp(Act a,Act b)
{
	return a.end<b.end;
}
int main()
{
	int n,i,count=1,j;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&act[i].start,&act[i].end);
	}
	sort(act,act+N,cmp);
	i=0;
	for(j=1;j<N;j++)
	{
		if(act[j].start>=act[i].end)
		{
			i=j;
			count++;
		}
	}
	printf("%d",count);
 	return 0;
}

