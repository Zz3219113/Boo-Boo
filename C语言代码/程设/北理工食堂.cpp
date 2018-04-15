#include<stdio.h>
#include<stdlib.h>
int arr[100010];
int brr[100010];
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&arr[i],&brr[i]);
	qsort(arr,n,sizeof(arr[0]),cmp);
	qsort(brr,n,sizeof(brr[0]),cmp);
	long long ans=0;
	for(i=0,j=n-1;i<j;i++,j--)
		ans+=arr[j]-arr[i]+brr[j]-brr[i];
	printf("%lld\n",ans);
	return 0;
}

