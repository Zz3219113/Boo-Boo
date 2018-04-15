#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int cont1=1,cont2=0,cont3=0,flag1=0,flag2=0,flag3=0,cont4=0,cont5=0,cont6=0;
	char c,b;
	while(c=getchar())
	{
	Juge:if(c!='#'&&c!='@'&&c!='('&&c!=')'&&c!=34&&c!='\''&&c!='\n'&&c!=';')
			continue;	
		else if(c=='#')//
		{
			if(cont4%2||cont5%2)
			{
				printf("Unterminated string in line %d.\n",cont3);
				cont4=0,cont5=0;
			}
			if(flag1==1)
				printf("Unterminated block comment at end of program.\n");
			b=getchar();
			printf("Program %d contains %d logical lines and %d physical lines.\n",cont1,cont2,cont3);
			if(b=='#')	
				return 0;
			else
			{
				cont1++,cont2=0,cont3=0,cont4=0,cont5=0,cont6=0;
				flag1=0,flag2=0,flag3=0;
				c=b;
				if(b!='\n')
					goto Juge;
			}
		}
		else if(c=='@')//
		{
			if(flag1==0&&(cont5%2==0)&&(cont4%2==0))
			{
				flag2=1;
				c=getchar();
				goto Juge;
			}
		}
		else if(c=='(')
		{
			if(flag1==0)
			{
				b=getchar();
				if(b=='('&&flag2==0)
					flag1=1;
				else
				{
					c=b;
					goto Juge;
				}
			}
			
		}
		else if(c==')')
		{
			b=getchar();
			if(b==')')
				flag1=0;
			else
			{
				c=b;
				goto Juge;
			}	
		}
		else if(c=='\'')//'
		{
			if(flag1==0&&(cont5%2==0)&&flag2==0)
				cont4++;
		}
		else if(c==34)//"
		{
			if(flag1==0&&(cont4%2==0)&&flag2==0)
				cont5++;
		}
		else if(c=='\n')
		{
			cont3++;
			if(cont4%2||cont5%2)
				printf("Unterminated string in line %d.\n",cont3);	
			cont4=0,cont5=0;	
			flag2=0;
		}
		else if(c==';')
		{
			if(flag1==0&&flag2==0&&(cont4%2==0)&&(cont5%2==0))
				cont2++;
		}
	}
	return 0;
}
