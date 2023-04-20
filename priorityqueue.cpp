#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
struct node{
    int info,priority;
    struct node *next;
};
void Insert(int,int);
int Delete();
void Display();
struct node *front,*rear;
int main()
{
    int ele,prio;
    char ch;
    front=rear=NULL;
    do{
        cout<<"\n\tOptions\tChoice\n";
        cout<<"\n\tInsert\tI/i\n";
        cout<<"\n\tDelete\tD/d\n";
        cout<<"\n\tExist\tX/x\n";
        cout<<"\nEnter your choice:\t";
        do{
            ch=getchar();
        }while(strchr("IiDdXx",ch)==NULL);

        switch(ch)
        {
            case 'I':
            case 'i':
                   cout<<"\nEnter Element:\t";
                   cin>>ele;
                   cout<<"\nEnter Priority:\t";
                   cin>>prio;
                   Insert(ele,prio);
                   cout<<"\n***Queue***\n";
                   Display();
                break;

            case 'D':
            case 'd':
                 if(rear==NULL)
                     cout<<"\nQueue is Empty\n";
                else 
                {
                    ele=Delete();
                    cout<<"\nDeleted Element is :\t"<<ele;
                    if(rear==NULL)
                        cout<<"\nQueue becomes Empty";
                    else
                    {
                        cout<<"\n***Queue**\n";
                        Display();
                    }
                }
        }
    }while(ch!='X'&&ch!='x');
}

//code for insert element in queue

void Insert(int ele,int prio)
{
    struct node *newnode,*prev,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=ele;
    newnode->priority=prio;

    newnode->next=NULL;
    if(rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        prev=NULL;
        temp=front;
        while(temp!=NULL && newnode->priority<=temp->priority)
        {
            prev=temp;
            temp=temp->next;
        }
        if(prev==NULL)
        {
            newnode->next=front;
            front=newnode;
        }
        else
        {
            newnode->next=temp;
            prev->next=newnode;
            if(temp==NULL)
            {
                rear=newnode;
            }
        }
    }
}

//delete function
int Delete()
{
    int ele;
    struct node *temp;
    temp=front;
    ele=front->info;
    if(front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->next;
        rear->next=front;
    }
    free(temp);
    return(ele);
}

//display function

void Display()
{
    struct node *temp;
    cout<<"\nFront->";
    for(temp=front;temp!=NULL;temp=temp->next)
         cout<<temp->info<<"|"<<temp->priority<<"->";
    cout<<"Rear";
}
