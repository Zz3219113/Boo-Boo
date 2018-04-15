#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a,b,ads;
}arr[1000010];
int brr[1000010];
int cmp(const void *a,const void *b)
{
	struct node *c=(struct node*)a;
	struct node *d=(struct node*)b;
	return d->a-c->a;
}
int cmp1(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int n,res=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i].a);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i].b);
	for(int i=0;i<n;i++)
		arr[i].ads=i+1;
	qsort(arr,n,sizeof(arr[0]),cmp);
	if(n%2==0)
	{
		brr[++res]=arr[0].ads;
		for(int i=1;i<n-1;i+=2)
		{
			if(arr[i].b>arr[i+1].b)
				brr[++res]=arr[i].ads;
			else
				brr[++res]=arr[i+1].ads;
		}
		brr[++res]=arr[n-1].ads;
	}
	else
	{
		brr[++res]=arr[0].ads;
		for(int i=1;i<n-1;i+=2)
		{
			if(arr[i].b>arr[i+1].b)
				brr[++res]=arr[i].ads;
			else
				brr[++res]=arr[i+1].ads;
		}
	}
	printf("%d\n",res);
	qsort(brr+1,res,sizeof(int),cmp1);
	for(int i=1;i<=res;i++)
	{
		if(i==1)
			printf("%d",brr[i]);
		else
			printf(" %d",brr[i]);
	}
	printf("\n");
	return 0;
}
