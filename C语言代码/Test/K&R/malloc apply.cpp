#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
using namespace std;
int main()
{
	int count,*array;
	if((array=(int *)malloc(10*sizeof(int)))==NULL)
	{
		printf("不能分配内存。\n");
		exit(1); 
	}
	for(count=0;count<10;count++)
		array[count]=count;
	for(count=0;count<10;count++)
		printf("%-2d",array[count]);
 	return 0;
}

