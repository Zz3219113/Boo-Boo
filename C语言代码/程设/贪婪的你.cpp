#include<stdio.h>
#include<stdlib.h>
struct node
{
	int grade;
	int dl;
}arr[10001];
long long sum;
int max,ads,temp;
int cmp(const void *a,const void *b)
{
	struct node *c=(struct node *)a;
	struct node *d=(struct node *)b;
	if(c->dl==d->dl)
		return c->grade-d->grade;
	else
		return d->dl-c->dl;
}
int main()
{
	int n,t;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i].grade);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i].dl);
		if(arr[i].dl>ads)
			ads=arr[i].dl;
	}
	qsort(arr,n,sizeof(arr[0]),cmp);
	/*for(int i=0;i<n;i++)
	{
		printf("%d %d \n",arr[i].dl,arr[i].grade);
	}*/
	int j;
	for(int i=ads;i>=1;i--)
	{
		max=0;
		for(int j=0;arr[j].dl>=i;j++)
		if(max<arr[j].grade)
		{
			max=arr[j].grade;
			temp=j;
		}
		sum+=max;
		arr[temp].grade=0;
	}
	printf("%lld\n",sum);
	return 0;
}
