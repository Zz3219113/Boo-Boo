#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b=0,c,n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c);
			if(b==0)
			{
				a=c;
				b=1;
			}
			else if(a==c)
			{
				b++;
			}
			else if(a!=c)
			{
				b--;
			}
		}
		printf("%d\n",a);
	}
	return 0;
}
