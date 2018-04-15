#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
char arr[100010];
int main()
{
	long long n,m;
	scanf("%lld %lld",&n,&m);
	scanf("%s",arr);
	for(int i=0;i<n;i++)
	{
		if(m==0)
			arr[i]=arr[i];
		int a,z;
		a=arr[i]-'a';
		z='z'-arr[i];
		if(a>=z)
		{
			if(m>a)
			{
				arr[i]='a';
				m-=a;
			}
			else
			{
				arr[i]='a'+a-m;
				m=0;
			}
		}
		else
		{
			if(m>z)
			{
				arr[i]='z';
				m-=z;
			}
			else
			{
				arr[i]='z'-(z-m);
				m=0;
			}
		}
	}
	if(m>0)
		printf("-1\n");
	else
	printf("%s\n",arr);
	return 0;
}
