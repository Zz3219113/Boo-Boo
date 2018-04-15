#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
long long N,K;
double len[10000],L,R,mid;
bool fun(double a)
{
	long long count=0;
	for(long long i=0;i<N;i++)
	{
		count+=(int)(len[i]/a);
	}
	return count>=K;
}
int main()
{
	long long i;
	while(~scanf("%lld%lld",&N,&K))
	{
		memset(len,0,sizeof(len));
		R=0;L=0;
		if(N==0&&K==0)
			return 0;
		for(i=0;i<N;i++)
		{
			scanf("%lf",&len[i]);
			if(R<len[i])
				R=len[i];
		}	
		for(i=0;i<100;i++)
		{
			mid=(L+R)*0.5;
			if(fun(mid))
				L=mid;
			else
				R=mid;
		}
		printf("%.2lf\n",mid);
	}
 	return 0;
}




