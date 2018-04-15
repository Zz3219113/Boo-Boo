#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
#define Max 0x3f3f3f3f
using namespace std;
char arr[30];
int a[30];
int len;
int dfs(int num,int turn,int cnt)
{
	if(num==0)    
	{
		if(turn==1)
		{
			for(int i=0;i<=1;i++)//第一个翻面 
			{
				a[i]=!a[i];
			}
			dfs(num+1,1,cnt+1); 
		}
		else					//第一个不翻面
		{
				return dfs(num+1,turn,cnt);
		}
	}
	else          
	{
		if(num==len)
		{
			if(a[num-1]==0)
				return cnt;
			else
				return Max;
		}
		else
		{
			if(a[num-1]==1)
			{
				a[num+1]=!a[num+1];
				a[num]=!a[num];
				a[num-1]=!a[num];
				return dfs(num+1,turn,cnt+1);
			}
			else
				return dfs(num+1,turn,cnt);
		}
	}
}
int main()
{
	while(~scanf("%s",arr))
	{
		len=strlen(arr);
		for(int i=0;i<len;i++)
		{
			a[i]=arr[i]-'0';
		}
		int ans1=dfs(0,1,0);
		for(int i=0;i<len;i++)
		{
			a[i]=arr[i]-'0';
		}
		int ans2=dfs(0,0,0);
		int flag=min(ans1,ans2);
		if(flag==Max)
			printf("i can't do it!\n");
		else
			printf("%d\n",flag);
		memset(a,0,sizeof(a));
		memset(arr,0,sizeof(arr));
	}
	return 0;
}
