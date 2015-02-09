#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct itcompany
{
	char cname[10];
	struct itcompany *link;
};
void display(struct itcompany *);
struct itcompany *search(struct itcompany *,int );
struct itcompany *insert(struct itcompany *,struct itcompany *,struct itcompany *);
struct itcompany *delete(struct itcompany *,struct itcompany *);
void main()
{
	int items,i=0,c=0,loc;
	char name[10],b[3];
	struct itcompany *head=NULL,*a=NULL,*aw=NULL;
	head=(struct itcompany *)malloc(sizeof(struct itcompany));
	a=head;
	printf("Enter no. of items in the list\t");
	scanf("%d",&items);
	for(i=0;i<items;i++)
	{
		printf("Enter the name of the itcompany\t");
		scanf("%s",name);
		strcpy(a->cname,name);
		aw=a;
		if(i!=(items-1))
		{
			a=(struct itcompany *)malloc(sizeof(struct itcompany));
			aw->link=a;
		}
		else
		aw->link=NULL;
	}
	do
	{
		printf("\nEnter 1 to insert a node at any location");
		printf("\nEnter 2 to delete a node at any location");
		printf("\nEnter 3 to display the list");
		printf("\nEnter 4 to reverse the list");
		printf("\nEnter the appropriate choice\t");
		scanf("%d",&c);
		switch(c)
		{
			case 1: {
					struct itcompany *sloc,*nloc;
					char name[10];
					int loc=0;
					nloc=(struct itcompany *)malloc(sizeof(struct itcompany));
					printf("\nEnter the data to be inserted\t");
					scanf("%s",name);
					strcpy(nloc->cname,name);
					printf("\nEnter the location at which data is to be inserted\t");
					scanf("%d",&loc);	
					sloc=search(head,loc);
					head=insert(head,sloc,nloc);
					printf("\nAfter insertion,the list is");
					display(head);
					break;
				}
			case 2: {
					struct itcompany *sloc;
					int loc=0;
					printf("\nEnter the location at which data is to be deleted\t");
					scanf("%d",&loc);	
					sloc=search(head,loc);
					head=delete(head,sloc);
					printf("\nAfter deletion,the list is");
					display(head);
					break;
				}	 
		}
		printf("\nEnter yes to continue else enter no\t");
		scanf("%s",b);

 	}while (strcmp(b,"yes")==0);
}
void display(struct itcompany *head)
{
	struct itcompany *p;
	p=head;
	while(p!=NULL)
	{
		printf("%s\n",p->cname);
		p=p->link;
	}
}
struct itcompany *search(struct itcompany *head,int loc)
{
	struct itcompany *sloc;
	int i=1;
	sloc=head;
	for(i=1;i<loc;i++)
	{
		sloc=sloc->link;
		printf("%s\n",sloc->cname);
		printf("%p\n",sloc);
	}
			printf("Element at s loc is %s\n",sloc->cname);
	return sloc;
}
struct itcompany *insert(struct itcompany *head,struct itcompany *sloc,struct itcompany *nloc)
{
	if(sloc==head)/* Insert at 1st location */
	{
		nloc->link=head;
		head=nloc;
	}
	else if(sloc==NULL) /*At the End */
	{
		if(head!=NULL)
		{
			struct itcompany *h=head;
			while(h->link!=NULL)
				h=h->link;
			h->link=nloc;
			nloc->link=NULL;		
		}else
		{
			head=nloc;
			nloc->link=NULL;
		}
	}
	else /* insert in between nodes */
	{
		nloc->link=sloc->link;
		sloc->link=nloc;
	}
	display(head);
	return head;
}
struct itcompany *delete(struct itcompany *head,struct itcompany *sloc)
{
	struct itcompany *temp;
	if(sloc==head)
	{
		head=sloc->link;
		free(sloc);
	}
	else if(sloc->link==NULL)
	{
		free(sloc);
		sloc=NULL;
	}
	else
	{
		temp=sloc->link;
		free(sloc);
		sloc=temp;
	}
}
