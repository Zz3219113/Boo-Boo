#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
char a[100010][10];
char s1[10],s2[10];
char flag;
int parent[][1]
int n,m,k;
int bsearch(char b[],left,right)
{
	int mid,ret=-1;
	while(right>=left)
	{
		mid=(lftf+right)/2;
		if(strcmp(b,a[mid])==0)
		{
			right=mid-1;
			ret=mid;
		}
		else if(strcmp(b,a[mid])==1)
			left=mid+1
		if(strcmp(b,a[mid])==-1)
			right=mid-1;
	}
	return ret;
}
int main()
{
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		}
		sort(a,a+n);
		for(int i=0;i<m;i++)
		{
			scanf("%c %s %s",&flag,s1,s2);
			loc1=bsearch(s1,0,n);
			loc2=bsearch(s2,0,n);
			if(loc1==-1||loc2==-1)
			{
				printf("No\n");
				continue;
			}
			f1=find(loc1);
			f2=find(loc2);
			if(f1)
		}
	}	
	return 0;
}
