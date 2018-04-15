#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
using namespace std;
int main()
{
	int t;
	long long a,b;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int s=0;
		scanf("%lld %lld",&a,&b);
		while(a>b)
		{
			a=a-(a%(a/2+1));
			s++;
		}
		printf("Case %d: %d\n",i,s);
	} 
 	return 0;
}

