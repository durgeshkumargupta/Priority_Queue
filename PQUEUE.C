#include<stdio.h>
#include<conio.h>
#define DMA (struct priority*)malloc(sizeof(struct priority))
struct priority *insert_data(int data,int pdata,struct priority *root);
void display(struct priority *root);
struct priority *delete_node(struct priority *root);
struct priority
{
  int data,prio;
  struct priority *next;
};
void main()
{
    int data,pdata,ch;
    struct priority *root;
    root=NULL;
    while(1)
    {
       clrscr();
       printf("Menu of priority Queue\n");
       printf("1.Insert data\n");
       printf("2.Display\n");
       printf("3.Delete node\n");
       printf("0.Exit\n");
       printf("Enter your choice=");
       scanf("%d",&ch);
       switch(ch)
       {
	 case 1:
	     printf("Enter data=");
	     scanf("%d",&data);
	     printf("Enter priority number=");
	     scanf("%d",&pdata);
	      root=insert_data(data,pdata,root);break;
	 case 2:
	      display(root);break;
	 case 3:
	      root=delete_node(root);break;
	 case 0:
	      exit(0);
	 default:
	    printf("Plz try again\n");sleep(1);
       }
    }
}
struct priority *insert_data(int data,int pdata,struct priority *root)
{
       struct priority  *temp,*prevnode,*newnode;
       newnode=DMA;
       newnode->data=data;
       newnode->prio=pdata;
       newnode->next=NULL;
       temp=root;
       if(root==NULL)
       root=newnode;
       else
       {
              if(newnode->prio<temp->prio)
   	 	{
    		    newnode->next=temp;
                    root=newnode;
                }
              else
                {
                    temp=root;
                    while(newnode->prio>temp->prio && temp!=NULL)
                      {
                           prevnode=temp;
                           temp=temp->next;
                       }
                     if(newnode->prio>temp->prio)
                        prevnode->next=newnode;
                     else
                       {
                            newnode->next=temp;
                            prevnode->next=newnode;
                       }
                }
          }   
return root;
}
void display(struct priority *root)
{
     struct priority *temp;
     if(root==NULL)
       printf("Priority queue is empty");
     else
     {
       temp=root;
	while(temp)
	{
	  printf("%d->%d  ",temp->data,temp->prio);
	  temp=temp->next;
	}
     }
     sleep(2);

}
struct priority *delete_node(struct priority *root)
{
    int d,p,c=0;
    struct priority *temp,*prevnode;
    printf("Enter position=");
    scanf("%d",&p);
    temp=root;
    if(root==NULL)
    printf("List empty");
    else if(p==1)
    {     root=temp->next;
	  temp->next=NULL;

    }
    else
    {
       while(temp)
	{
	 c++;
	if(c==p)
	{
	  d=temp->data;
	   prevnode->next=temp->next;
	   temp->next=NULL;
	   free(temp);
	}
	prevnode=temp;
	temp=temp->next;
    }
    }
    printf("Dequeue data=%d",d);
    sleep(2);
    return root;
}
