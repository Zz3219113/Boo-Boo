#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define allocsize 10000
using namespace std;
static char allocbuf[allocsize];
static char *allocp=allocbuf;
char *alloc(int n)
{
	if(allocbuf+allocsize-allocp>=n)
	{
		allocp+=n;
		return allocp-n;
	}
	else
		return 0;	
}
void afree(char *p)
{
	if(p>=allocbuf&&p<allocbuf+allocsize)
		allocp=p;
}
