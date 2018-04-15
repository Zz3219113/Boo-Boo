#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
void swap(int *p1,int *p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int main()
{
	int num1,num2;
	int *p1,*p2;
	printf("please input your numble!\n");
	scanf("%d%d",&num1,&num2);
	p1=&num1;
	p2=&num2;
	if(num1<num2)
	{
		swap(&num1,&num2);	//swap(p1,p2);	
	}
	printf("the max is %d,the min is %d",num1,num2);
 	return 0;
}

