#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
#define mod 1000000007
using namespace std;
char mi[100010]; 
int main()
{
	long long t;
	while(~scanf("%lld %s",&t,mi))
	{
		long long ans=1;
		long long temp;
		int len=strlen(mi);
		for(int i=len;i>=0;i--)
		{
			for(int i=0;i<mi[i]-'0';i++)
			{
				ans*=t;
				ans %= mod;
			}
			temp=t;
			for(int j=0;j<9;j++)
			{
				t*=temp;
				t%=mod;
			}
		} 
		printf("%lld\n",ans);
	}
	return 0;
} 
