//impletion of stack using linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
struct node
{
    int info;
  struct node* next;
};

struct node* Push(struct node*,int);
struct node* Pop(struct node*);
void Display(struct node*);
using namespace std;
int main()
{
    struct node* top=NULL;
    int ele;
    char ch;
    do{
        cout<<"\nOptions\n";
        cout<<"\nPush\n";
        cout<<"\nPop\n";
        cout<<"\nExit\n";
        cout<<"Enter your choice\n";
        do{
            ch=getchar();
        }while(strchr("PpOoXx",ch)==NULL);

        switch(ch)
        {
            case 'P':
            case 'p':
                     cout<<"Enter element to push\n";
                     cin>>ele;
                     top=Push(top,ele);
                     cout<<"\n**STACK**";
                     Display(top);
                     break;

            case 'O':
            case 'o':
                    if(top==NULL){
                        cout<<"\nStack is empty";
                    }
                    else{
                        top=Pop(top);
                        if(top==NULL)
                        {
                            cout<<"\nStack becomes empty";
                        }
                        else
                        {
                            cout<<"\n**STACK**";
                            Display(top);
                        }
                    }
        }
    }while(ch!='X'&&ch!='x');
}
struct node* Push(struct node* top,int ele)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=ele;
    newnode->next=top;
    top=newnode;
    return top;
}

struct node* Pop(struct node* top)
{
    struct node* t;
    int ele;
    t=top;
    ele=top->info;
    cout<<"\nPopped element is"<<ele;
    top=top->next;
    free(t);
    return top;
}

void Display(struct node* top)
{
    cout<<"\nSTACK";
    for(;top!=NULL;top=top->next)
    {
        cout<<top->info<<"->";
    }
}