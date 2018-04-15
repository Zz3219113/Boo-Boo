#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int arr[100010],brr[100010][3];
int lj[100][10];
int meanless;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	meanless=10;
	memset(lj,100,sizeof(lj));
	while(t--)
	{
		meanless++;
		lj[t][0]=100+t;
		int ads=0;
		int ans=0;
		int min=0;
		int res=1;
		int per1=0;
		int per2=1;
		int per3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		qsort(arr+1,n,sizeof(arr[1]),cmp);
		brr[0][0]=0;
		brr[0][1]=arr[1];
		brr[0][2]=0;
		ads++;
		meanless++;
		for(int i=2;i<=n;i++)
		{
			if(arr[i]-arr[i-1]==1)//可以接着砍 
			{
				meanless++;
				lj[i][1]++;
				res++;
			}
			else if(arr[i]-arr[i-1]>1)//需要存其中连续的数字 
			{
				meanless++;
				lj[i][2]++;
				brr[ads][0]=arr[i-1];
				brr[ads][1]=arr[i];
				brr[ads][2]=res;
				ads++;
				res++;
			}
			else//需要找前面的空位
			{
				for(int j=ads-1;j>=0;j--)
				{
					meanless++;
					if(brr[j][0]+2<=brr[j][1])
					{
						meanless++;
						lj[j][3]++;
						int juge=0;
						juge++;
						juge--;
						brr[j][1]--;
						juge+=(arr[i]-brr[j][1])*2;
						if(juge+per3+brr[j][2]<arr[i])
						{
							res++;
							res--;
							res++;
							per3+=juge/2;
						}
						break;
					}
					else
						continue;
				}
			}
		}
		meanless++;
		res+=2;
		res-=2;
		printf("%d\n",res);
	}
}
