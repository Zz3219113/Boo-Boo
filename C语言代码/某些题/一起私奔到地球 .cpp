#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int sum=0;
int arr[1010];
int main()
{
	int t;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		qsort(arr,n,sizeof(arr[0]),cmp);
		for(int i=n-1;i>2;i-=2)
			if(arr[0]+2*arr[1]+arr[i]>2*arr[0]+arr[i-1]+arr[i])
                sum+=2*arr[0]+arr[i-1]+arr[i];
            else sum+=arr[0]+2*arr[1]+arr[i];
            if(i==2) 
				sum+=arr[0]+arr[1]+arr[2];
            else if(i==1) 
				sum+=arr[1];
            else sum+=arr[0];
        printf("%d\n",sum);
    }
}
