#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
using namespace std;
int main()
{
	int n,m,k,juge,max,min;
	int a[10010];
	while(~scanf("%d %d %d",&n,&k,&m)!=EOF&&n!=0&&m!=0&&k!=0)
	{
		int N=n,flag=0,count=0,a1=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			a[i]++;
		a[m]=0;
		N--;
		for(int i=2;i<=N;i++)
		{
	 		a1=(a1+k)%i;
		}
		juge=(a1+m)%n;
		printf("%d\n",juge+1);
	} 
 	return 0;
}

