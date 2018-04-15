#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[1000],b[1000],c[1000];
	int i=0,j=0,k=0;
	while(i<1000&&j<1000)
	{
		if(a[i]<b[j])
			c[k++]=a[i++];
		else
			c[k++]=b[j++]; 
	}	
 	return 0;
}

