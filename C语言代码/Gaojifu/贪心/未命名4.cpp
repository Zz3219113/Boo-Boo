#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int count(int n,int m)
{	int sum;
	if(n==m)
	return 1;
	if(n>m)
	return sum=count(n-m,m)+1;
	if(m>n)
	return sum=count(m-n,n)+1;
	return sum;
}
int main()
{
	int n,a1,a2,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	scanf("%d%d",&a1,&a2);
		printf("%d\n",count(a1,a2));
	}	
 	return 0;
}

