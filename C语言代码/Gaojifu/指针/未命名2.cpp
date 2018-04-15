#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int t;
	char letter[100010];
	long long sum,n,count[130],len;
	scanf("%d",&t);
	while(t--)
	{	
		memset(letter,0,sizeof(letter));
		memset(count,0,sizeof(count));
		scanf("%s%lld",letter,&n);
		len=strlen(letter);
		int L=0,R=0,sum=0;
		for(R=0;R<len;R++)
		{
			count[letter[R]]++;
			while(L<R&&count[letter[R]]>n)
			{
				count[letter[L]]--;
				L++;
			}
			sum+=(R-L+1);
		}
		printf("%lld\n",sum);
	}
	return 0;
}

