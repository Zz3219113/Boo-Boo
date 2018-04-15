#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#define LEN sizeof(struuct movie)
using namespace std;
struct movie
{
	char name[20];
	float rete;
	struct movie *next;
};
int main()
{
	struct movie *head=NULL;
	struct movie *prev,*current;
	char input[40];
	printf("Enter the first movie\n");
	while(gets(input)!=NULL&&input[0]!='0')
	{
		current=(struct movie *)malloc(sizeof(struct movie));
		if(head==NULL)
			head=current;
		else
			prev->next=current;
		current->next=NULL;
		strcpy(current->name,input);
		printf("Enter the rate<0-10>\n");
		scanf("%d",&current->rete);
		while(getchar()!='\n');
			continue;
		puts("Enter the next movie\n");
		prev=current;
	}
	if(head==NULL)
	{
		printf("No data entered\n");	
	} 
	else
	{
		printf("Here is a movie list\n");
	}
	current=head;
	while(current !=NULL);
	{
		printf("Movie: %s Rating: %d\n",current->name,current->rete);
		current=current->next;
	}
	current=head;
	while(current!=NULL)
	{
		free(current);
		current=current->next;
	}
	printf("Bye!\n");
 	return 0;
}

