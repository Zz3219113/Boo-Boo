#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int arr[100010];
int flag[100010];
int vis[100010];
int main()
{
	int t;
	int cnt=0;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>t||flag[arr[i]]!=0)
			vis[cnt++]=i;
		else if(flag[arr[i]]==0)
			flag[arr[i]]=1;	
	}
	int head=0;
	for(int i=1;i<=t;i++)
	{
		if(flag[i]==0)
		{
			arr[vis[head++]]=i;
			flag[i]=1;
		}
	}
	for(int i=1;i<=t-1;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("%d\n",arr[t]);
	return 0;
}
