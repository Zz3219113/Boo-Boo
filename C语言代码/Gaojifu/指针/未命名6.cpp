#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,i,j,k,sum=0,a2[130];
	char a1[100005];
	scanf("%d",&n);
	scanf("%s",a1);
	for(i=0;i<n;i++)
	{
		a2[a1[i]]=1;
	}
	for(i='A',j='a';i<='Z',j<='z';j++,i++)
	{
			sum+=a2[i]+a2[j];
	}
	memset(a2,0,sizeof(a2));
	int min=100005,L=0,R=0,len=0;
	a2[a1[0]]=1;
	while(1)
	{
		while(len<sum)
		{
			R++;
			if(R>=n)
				break;
			if(a2[a1[R]]==0)									
				len++;
			a2[a1[R]]++;					
	  	}
	  	while(1)
	  	{
	  		if(a2[a1[L]]>1)
			{
				a2[a1[L]]--;
	  			L++;	
	  		}	
	  		if(a2[a1[L]]==1)
	  			break;
	  	}
	  	if(R-L<min)
	  		min=R-L;
	  	if(R>=n)
	  		break;
		else if(R!=n)
		{
			a2[a1[L]]--;
			L++;
			len--;
		} 
	}
	printf("%d",min);
	return 0;
}

