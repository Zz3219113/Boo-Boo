#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
long long N,M,mid;
int money[100010];
bool fun(int a)
{
	long long sum=0,count=1;
	for(long long i=0;i<N;i++)
	{
		if((sum+money[i])<=a)
		{
			sum+=money[i];
		}
		else
		{
			sum=money[i];
			count++;
		}
	}	
	return count<=M;		
}
int main()
{
	long long i,L=0,R=0,result;
	scanf("%lld %lld",&N,&M);
	for(i=0;i<N;i++)
	{
		scanf("%lld",&money[i]);
		R+=money[i];
		if(L<money[i])
			L=money[i];
	}
	while(L<=R)
	{	
		mid=(L+R)/2;
		if(fun(mid))
		{
			R=mid;
		} 
		else
			L=mid+1;
	}
	printf("%lld\n",result);
 	return 0;
}

