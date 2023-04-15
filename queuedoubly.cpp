#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
void Insert(int);
int Delete();
void Display();

struct node *front ,*rear;

int main()
{
    int ele;
    char ch;
    front=rear=NULL;
    do{
        cout<<"\n\tOptions\t\tChoices\t";
        cout<<"\n\tInsert\t\tI/i";
        cout<<"\n\tDelete\t\tD/d";
        cout<<"\n\tExit\t\tX/x";
        cout<<"\nEnter Your Choice:\t";
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
                    cout<<"\n***Queue***\t";
                    Display();
                break;

            case 'D':
            case 'd':
                    if(rear==NULL) 
                         cout<<"\nQueue is Empty";
                    else
                    {
                        ele=Delete();
                        cout<<"\nDeleted Element is :\t"<<ele;
                        if(rear==NULL)
                              cout<<"\nQueue has becomes empty";
                        else
                        {
                            cout<<"\n***Queue***";
                            Display();
                        }
                    }
        }
    }while((ch!='X')&&(ch!='x'));
}

void Insert(int ele)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
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
    int ele;
    struct node *temp;
    temp=front;
    ele=front->info;
    if(front==rear)
         front=rear=NULL;
    else{
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
    cout<<"\nFront->";
    do{
        cout<<temp->info<<"->";
        temp=temp->next;
    }while(temp!=front);
    cout<<"Rear";
}