#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
long long N,born[100010],cow,mid;
int cmp(const void *a,const void *b)
{
	return (*(long long *)a-*(long long*)b)>0?1:-1;
}
bool fun(int a)
{
	long long i,count,end=0;
	count=end+1;
	for(i=1;i<cow;i++)
	{
		while(count<N&&born[count]-born[end]<a)
			count++;
		if(count>=N)
			return false;
		end=count;
	}
	return true;
} 
int main()
{
	long long i,L,R;
	scanf("%lld %lld",&N,&cow);
	for(i=0;i<N;i++)
	{
		scanf("%lld",&born[i]);
	}
	qsort(born,N,sizeof(born[0]),cmp);
	L=0;R=1000000000;
	for(i=0;i<100;i++)
	{
		mid=(L+R)/2;
		if(fun(mid))
			L=mid;
		else
			R=mid;
	}
	printf("%lld\n",mid);
 	return 0;
}

