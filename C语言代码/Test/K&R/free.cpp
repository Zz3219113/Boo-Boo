#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
using namespace std;
int main()
{
	int *p1,*p2;
	p1=(int *)malloc(10*sizeof(int));
	p2=p1;
	free(p2);
 	return 0;
}

