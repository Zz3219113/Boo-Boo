#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,m,a[1100][2],i,j,k,temp1;
	double b[1100],sum=0,money,temp;
	while(~scanf("%d %d",&n,&m))
	{	money=n;
		sum=0;
		if(n==-1&&m==-1)
			break;
		memset(b,0,sizeof(b));
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a[i][0],&a[i][1]);
			b[i]=((double)a[i][0]/(double)a[i][1]);
		}
		for(j=0;j<i;j++)
		{
			for(k=0;k<i;k++)
			{
				if(b[k]<b[k+1])
				{
					temp=b[k];
					b[k]=b[k+1];
					b[k+1]=temp;
					temp1=a[k][1];
					a[k][1]=a[k+1][1];
					a[k+1][1]=temp1;
					temp1=a[k][0];
					a[k][0]=a[k+1][0];
					a[k+1][0]=temp1;
				}
			}
		}
		for(i=0;i<m;i++)
		{
			if(money>=a[i][1])
			{
				sum+=a[i][0];
				money-=a[i][1];
			}
			else
			{
				sum+=b[i]*money;
				break;
			}
		}
		printf("%.3lf\n",sum);	
	}
 	return 0;
}

