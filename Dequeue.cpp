#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
void Insert(int);
int Delete();
void Display();
struct node *front,*rear;
int main()
{
    int ele;
    char ch;
    front=rear=NULL;
    do{
        cout<<"\n\tOptions\t\tChoices\t\n";
        cout<<"\n\tInsert\t\tI/i\n";
        cout<<"\n\tDelete\t\tD/d\n";
        cout<<"\n\tExit\t\tX/x\n";
        cout<<"\nEnter your choice\n";
        do{
            ch=getchar();
        }while(strchr("IiDdXx",ch)==NULL);
        switch(ch)
        {
            case 'I':
            case 'i':
                  cout<<"\nEnter Element:\t";
                  cin>>ele;
                  Insert(ele);
                  cout<<"\n***Queue***\n";
                  Display();
                  break;

            case 'D':
            case 'd':
                  if(front==NULL)
                       cout<<"\nQueue is Empty\n";
                  else
                  {
                    ele=Delete();
                    cout<<"\nDeleted Element is:\t"<<ele;
                    if(front==NULL)
                        cout<<"\nQueue has becomes empty\n";
                    else 
                    {
                        cout<<"\n***Queue***\n";
                        Display();
                    }
                  }
        }
    }while(ch!='X'&&ch!='x');
}

void Insert(int ele)
{
    struct node *newnode;
    char fr;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=ele;
    newnode->next=NULL;
    if(rear==NULL)
        front=rear=newnode;
    else 
    {
        cout<<"\nselect (F/f)/select(R/r)\n";
        do{
            fr=getchar();
        }while(strchr("FfRr",fr)==NULL);
        switch(fr)
        {
            case 'F':
            case 'f':
                   newnode->next=front;
                   front=newnode;
                   break;
                   
            case 'R':
            case 'r':
                  rear->next=newnode;
                  rear=newnode;
        }
    }
}

int Delete()
{
    int ele;
    struct node *temp1,*temp2;
    char fr;
    if(front==rear)
    {
        temp2=front;
        ele=front->info;
        front=rear=NULL;
    }
    else
    {
        cout<<"\nSelect(F/f)front/Select(R/r):\t";
        do{
            fr=getchar();
        }while(strchr("FfRr",fr)==NULL);
        switch(fr)
        {
            case 'F':
            case 'f':
                  ele=front->info;
                  temp2=front;
                  front=front->next;
                  break;

            case 'R':
            case 'r':
                ele=rear->info;
                temp1=front;
                while(temp1->next!=rear)
                   temp1=temp1->next;
                   temp2=rear;
                   temp1->next=NULL;
                   rear=temp1;
        }
    }
    free(temp2);
    return ele;
}

void Display()
{
    struct node *temp;
    cout<<"\nFront->";
    for(temp=front;temp!=NULL;temp=temp->next)
        cout<<temp->info<<"->";
    cout<<"Rear";
}
