#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
using namespace std;
int f[100100];
int main()
{
	int n,k,m;
	while(scanf("%d%d%d",&n,&k,&m)!=EOF,n||m||k)
	{
		f[1]=0;
		for(int i=2;i<n;i++)
		{
			f[i]=(f[i-1]+k)%i;
		}
		f[n]=(f[n-1]+m)%n;
		printf("%d\n",f[n]+1);
	}
}
