#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	long long time,a[100],n,i;
	while(~scanf("%lld",&n))
	{
		time=0;
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		if(n>1)
		{
			time=a[0]*8+5;
			for(i=1;i<n;i++)
			{
			if(a[i]>a[i-1])
				time+=(a[i]-a[i-1])*8;
			else
				time+=(a[i-1]-a[i])*3;
			}
			time+=(n-1)*5;
		}
		if(n==1)
			time=a[0]*8+5;
		printf("%lld\n",time);
	}
 	return 0;
}

