#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n=0,m=0,a1=0,a2=0,a3=0;
		scanf("%d %d",&n,&m);
		for(int i=2;i<=n;i++)
		{
	 		a1=(a1+m)%i;
	 		if(i==2)a2=1-a1;
			else
			{
				a2=(a2+m)%i;
				if(i==3)a3 =3-a2-a1;
				else
				{
					a3=(a3+m)%i;
				}
			}
		}	
		printf("%d %d %d\n",a3+1,a2+1,a1+1);
	}
 	return 0;
}

