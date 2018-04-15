#include<stdio.h>
#include<stdlib.h>
int main()
{
	int res=0,a[8],a1,a2;
	a[0]=8;
	for(int i=0;i<7;i++)
	{
		scanf("%d %d",&a1,&a2);
		a[i+1]=a1+a2;
		if(a[i+1]>a[0])
		{
			res=i+1;
			a[0]=a[i+1];
		}
	}
	printf("%d\n",res);
	return 0;
}
