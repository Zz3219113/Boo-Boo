#include<stdio.h>
#include<string.h>
#include<math.h>
unsigned long long n,left,right,mid,num;
int getpow(long long ans,int t)//最大的尾数 
{
	int tmp=0;
	while(ans)
	{
		ans/=t;
		tmp++;
	}
	return tmp;
}
long long que(int q,int k)
{
	long long temp=1,sum=0;
	for(int i=0;i<k;i++)
	{
		sum+=temp;
		temp*=q;
	}
	return sum;
}
int main()
{
	Loop:while(~scanf("%lld",&n))
	{
		int sta=getpow(n,2);
		for(int i=sta;i>=2;i--)
		{
			left=2,right=n;
			while(left<=right)
			{
				mid=(left+right)/2;//二分找解
				//printf("%lld %lld %lld\n",left,mid,right);
				num=que(mid,i);
				if(n==num)
				{
					printf("%lld\n",mid);
					goto Loop;
				}
				else if(n>num)
				{
					left=mid+1;
				}
				else
				{
					right=mid-1;
				}
			}
		}
		printf("%lld\n",n-1);
	}
}
