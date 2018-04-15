#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
long long powermod(int x,int y,int mod)
{
	x=x%mod;
	if(y==0)
		return 1;
	if(y==1)
		return x%mod;
	long long  res=1;
	res=powermod(x,y/2,mod);
	res=res*res%mod;
	if(y%2)
		res=res*x%mod;
	return res;
} 
int main()
{
	long long t,x;
	while(~scanf("%lld",&t))
	{
		scanf("%lld",&x);
		printf("%lld\n",powermod(t,x,1e9+7));
	}
	return 0;
}
