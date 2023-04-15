#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
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
        cout<<"\nOptions\tChoices";
        cout<<"\nInsert\tI/i";
        cout<<"\nDelete\tD/d";
        cout<<"\nExit\tX/x";
        do{
            ch=getchar();
        }while(strchr("IiDdXx",ch)==NULL);

        switch(ch)
        {
            case 'I':
            case 'i':
                   cout<<"\nEnter Element\t";
                   cin>>ele;
                   Insert(ele);
                   cout<<"\n**Queue**\n";
                   Display();
                break;

            case 'D':
            case 'd':
                  if(rear==NULL)
                       cout<<"\nQueue is Empty";
                  else
                  {
                    ele=Delete();
                    cout<<"\nDeleted element is"<<ele;
                    if(rear==NULL)
                        cout<<"Queue has becomes empty";
                    else
                    {
                        cout<<"\n***Queue**";
                        Display();
                    }
                  }
        }
    }while((ch!='X')&&(ch!='x'));
}

void Insert(int ele)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=ele;
    if(rear==NULL)
          front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    rear->next=front;
}

int Delete()
{
    struct node *temp;
    int ele;
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
    return ele;
}

void Display()
{
    struct node *temp;
    temp=front;
    cout<<"Front->";
    do{
        cout<<temp->info<<"->";
        temp=temp->next;
    }while(temp!=front);
    cout<<"Rear";
}