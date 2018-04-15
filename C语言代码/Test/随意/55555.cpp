#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	long long n,m,sum=0,t1,t2,i,j,t,k,p;
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		scanf("%lld %lld",&n,&m);
		t2=n/5;
		t1=m/5;
		sum+=t1*t2*5;
		if(m>n)
		{
			p=m;m=n;n=p;
		}
		t2=n/5;t1=m/5;
	    sum=t1*t2*5;
		for(j=1;j<=m;j++)
		{
			if(j<=t1*5)
			for(k=t2*5+1;k<=n;k++)
			{
			 	if((j+k)%5==0) sum++;
			}
			else
			for(k=1;k<=n;k++)
			{
				if((j+k)%5==0) sum++;
			}
		}

		printf("%lld\n",sum);
	}
 	return 0;
}

