#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	char a[100000];
	long long i,count,length,t;
	scanf("%lld",&t);
	while(t--)
	{	count=0;
		memset(a,0,sizeof(a));
		scanf("%s",a);
		length=strlen(a);
		for(i=0;i<length;i++)
		{
			if(a[i]<='9'&&a[i]>='0')
				count++;
		}
		printf("%lld\n",count);			
	}
	return 0;
}

