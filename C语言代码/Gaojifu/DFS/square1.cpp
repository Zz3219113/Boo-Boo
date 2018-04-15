#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
bool used[21];
int stick[21];
int t,goal;
bool cmp(int a,int b)
{
	return a>b;
}
bool dfs(int count,int pos,int res)
{
	if(count==3)//3��ƴ�þ��ܱ�֤��ƴ��
		return true;
	for(int i=pos;i<t;i++)//DFS���ѭ��
	{
		if(used[i])
			continue;
		used[i] = true;
		if(stick[i]==res)
		{
			if(dfs(count+1,0,goal))//DFS����еĵݹ�
				return true;
		}
		else if(stick[i]<res)
		{
			if(dfs(count,i+1,res-stick[i]))//DFS����еĵݹ�
				return true;
		}
		else
		{
			return dfs(count,pos+1,len);
		}
		used[i] = false;
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		cin>>t;
		int sum=0;
		for(int i=0;i<t;i++)
		{
			cin>>stick[i];
			sum+=stick[i];
		}
		if(sum%4)
		{
			printf("no\n");
			continue;
		}
		goal = sum/4;
		memset(used,false,sizeof(used));
		sort(stick,stick+t,cmp);
		if(dfs(0,0,goal))//��ʼ̬
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
