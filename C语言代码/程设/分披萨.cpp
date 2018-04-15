#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
double PI=acos(-1.0);
double res[10001];
int Y,F;
int fun(double a)
{
	int count=0;
	for(int i=0;i<Y;i++)
	{
		count+=(int)(res[i]/a);
	}
	if(count>=F)
	return 1;
	else
	return 0;
}
int main()
{
	int t,ri;	
	double	L,R,mid,sum,max;
	while(~scanf("%d%d",&Y,&F))
	{
		memset(res,0,sizeof(res));
		F+=1;
		for(int i=0;i<Y;i++)
		{
			scanf("%d",&ri);
			res[i]=PI*ri*ri;
			sum+=res[i];
		}
		max=sum/F;
		L=0.0;
		R=max;
		while((R-L)>1e-6)
		{
			mid=(R+L)/2;
			if(fun(mid))
				L=mid;
			else
				R=mid;
		}
		printf("%.4lf\n",mid); 
	}
 	return 0;
}
