#include<stdio.h>
#include<math.h>
char arr[210];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int m=0,max1=0,max2=0;
		scanf("%s",arr);
		for(int i=0;arr[i]!='\0';i++)
		{
			if(arr[i]=='+')
				m++;
			else
				m--;
			if(m>0&&m>max1)
				max1=m;
			if(m<0&&-m>max2)
				max2=-m;
		}
		printf("%d\n",abs(max1+max2));
	}
	return 0;
}
