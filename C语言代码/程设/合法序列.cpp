#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char arr[500010];
int crr[500010];
char c;
int n,cnt;
struct node1
{
	int l,r,cnt;
}brr[500010];
int ansl,ansr,res,max;
struct node2
{
	int ads;
	char c;
}drr[500010];
int cur;
int main()
{
	while(c=getchar())
	{
		if(c=='\n')
		{
			break;
		}
		else if(c=='['||c==']'||c=='('||c==')')
		{
			arr[++n]=c;
		}
		if(c=='[')
		{
			cnt++;
		}
		crr[n]=cnt;
		brr[n].l=n;
		brr[n].cnt=0;
	}
	for(int i=1;i<=n;i++)
	{
		struct node2 sta={i,arr[i]};
		if((drr[cur].c=='(' &&sta.c ==')')||(drr[cur].c=='[' &&sta.c ==']'))
            --cur ;
        else
        {
        	cur++;
        	drr[cur]=sta;
		}
		drr[cur].ads;
		if(brr[drr[cur].ads+1].cnt<i-drr[cur].ads)
		{
			brr[drr[cur].ads+1].cnt=i-drr[cur].ads;
			brr[drr[cur].ads+1].r = i;
		}
	}
	for(int i = n ; i > 0 ; i--)
	{
        if(brr[i].cnt){
            int temp =  crr[brr[i].r] - crr[brr[i].l - 1] ;
            if(temp > res){
                res = temp;
                ansl = brr[i].l;
                ansr = brr[i].r;
            }
            else if(temp == res)
			{
                if(brr[i].r - brr[i].l > ansr - ansl)
				{
                    ansl = brr[i].l;
                    ansr = brr[i].r;
                }
            }
        }
    }
    printf("%d\n",res);
    if(res)
	{
        printf("%d %d\n",ansl-1,ansr-1);
    }
	return 0;
}
