#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int *)a>*(int *)b?1:-1;
}
int main()
{
	int a[5]={2,1,4,3,5},i,j,k,temp;
	for(i=1;i<5;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0&&temp<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	printf("%d %d %d %d %d",a[0],a[1],a[2],a[3],a[4]);
 	return 0;
}
 
