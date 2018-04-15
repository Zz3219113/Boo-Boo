#include<stdio.h>
#include<stdlib.h>
struct node
{
	double inx;
	double speed;
}arr[500010];
int cmp(const void *a,const void *b)
{
	return (*(struct node *)a).speed-(*(struct node *)b).speed;
}
int main()
{
	int times;
	scanf("%d",&times);
	while(times--)
	{
		int n=0;
		double x=0,w=0,r=0,sum=0;
		double right,left;
		double res=0,t=0;
		scanf("%lf %lf %lf %lf %d",&x,&w,&r,&t,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf %lf",&left,&right,&arr[i].speed);
			arr[i].inx=right-left;
			sum+=arr[i].inx;
		}
		arr[n].inx=x-sum;
		arr[n].speed=0;
		qsort(arr,n+1,sizeof(arr[0]),cmp);
		for(int i=0;i<=n;i++)
		{
			if(t*(r+arr[i].speed)<=arr[i].inx)
			{
				res+=(arr[i].inx-t*(r+arr[i].speed))/(w+arr[i].speed)+t;
				t=0;
			}
			else
			{
				res+=(double)(arr[i].inx/(r+arr[i].speed));
				t-=(double)(arr[i].inx/(r+arr[i].speed));
			}
		}
		printf("%06lf\n",res);
	}
	return 0;
}
