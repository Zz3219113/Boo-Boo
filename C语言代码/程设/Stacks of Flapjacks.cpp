#include<stdio.h>
#include<string.h>
#define Max 0x3f3f3f3f
int arr1[100],arr2[100];
void flip(int x,int y,int arr[])
{
	for(int i=x,j=y;i<=j;i++,j--)
	{
		int temp;
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}
int main()
{
	int n=0;
	memset(arr1,Max,sizeof(arr1));
	memset(arr2,Max,sizeof(arr2));
	while(scanf("%d",&arr1[++n])!=EOF)
	{
		int pos1,pos2;
		arr2[n]=arr1[n];
		while(getchar()!='\n')
		{
			scanf("%d",&arr1[++n]);
			arr2[n]=arr1[n];
		}
		printf("%d",arr1[1]);
		for(int i=2;i<=n;i++)
			printf(" %d",arr1[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(arr2[i]<arr2[j])
				{
					int temp;
					temp=arr2[i];
					arr2[i]=arr2[j];
					arr2[j]=temp;
				}
			}
		for(pos2=n;pos2>=1;pos2--)
		{
			
			for(pos1=1;pos1<=n;pos1++)
			{
				if(arr1[pos1]==arr2[pos2])
					break;
			}
			if(pos1!=pos2)
			{
				if(pos1!=1)
				{
					printf("%d %d ",n+1-pos1,n+1-pos2);
					flip(1,pos1,arr1);
					flip(1,pos2,arr1);
					
				}
				else if(pos1==1)
				{
					printf("%d ",n+1-pos2);
					flip(1,pos2,arr1);
				}
			}
			if(pos1==pos2)
				continue;
		}
		printf("0\n");
		memset(arr1,Max,sizeof(arr1));
		memset(arr2,Max,sizeof(arr2));
		n=0;
	}
	return 0;
}
