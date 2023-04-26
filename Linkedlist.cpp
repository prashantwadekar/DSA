#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct node{
    int info;
    struct node *next;
};
struct node *Create(struct node*);
struct node *Insert(struct node*,int,int);
struct node *Delete(struct node*,int);
void Display(struct node*);
int main()
{
    struct node *lst=NULL;
    int ele,pos;
    char ch;
    do{
        cout<<"\n\tOptions\t\tChoice\n";
        cout<<"\n\tCreate\t\tC/c\n";
        cout<<"\n\tInsert\t\tI/i\n";
        cout<<"\n\tDelete\t\tD/d\n";
        cout<<"\n\tExit\t\tX/x\n";
        cout<<"\nEnter Your Choice:\t";
        do{
            ch=getchar();
        }while(strchr("CcIiDdXx",ch)==NULL);

        switch(ch)
        {
            case 'C':
            case 'c':
                    lst=Create(lst);
                    cout<<"\n**LIST**\n";
                    Display(lst);
                    break;

            case 'I':
            case 'i':
                   cout<<"\nEnter Information:\t";
                   cin>>ele;
                   cout<<"\nEnter Postion:\t";
                   cin>>pos;
                   lst=Insert(lst,ele,pos);
                   cout<<"\n***LIST***";
                   Display(lst);
                   break;

            case 'D':
            case 'd':
                   if(lst==NULL)
                          cout<<"\nList is Empty\n";
                    else
                    {
                        cout<<"\nEnter Information to Delete:\t";
                        cin>>ele;
                        lst=Delete(lst,ele);
                        if(lst==NULL)
                              cout<<"\nList has become empty\n";
                        else
                        {
                            cout<<"\n**LIST**";
                            Display(lst);
                        }
                    }
        }
    }while(ch!='X'&&ch!='x');
}

struct node *Create(struct node *lst)
{
    int ele;
    struct node *newnode,*last;
    cout<<"\nEnter Information:\t";
    cin>>ele;
    while(ele!=0)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->info=ele;
        newnode->next=NULL;
        if(lst==NULL)
          lst=newnode;
        else
           last->next=newnode;
        last=newnode;
        cout<<"\nEnter Infromation:\t";
        cin>>ele;
    }
    return lst;
}

struct node *Insert(struct node *lst,int ele,int pos)
{
    struct node *newnode,*temp;
    int p;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=ele;
    newnode->next=NULL;
    if(pos==1){
        newnode->next=lst;
        lst=newnode;
    }
    else
    {
        p=2;
        temp=lst;
        while((p!=pos)&&(temp->next!=NULL))
        {
            p++;
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return lst;
}

struct node *Delete(struct node *lst,int ele)
{
    struct node *temp,*prev;
    prev=NULL;
    temp=lst;
    while((temp->info!=ele)&&(temp!=NULL))
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
    {
        lst=lst->next;
    }
    else
    {
        if(temp==NULL)
              cout<<"\nInformation is not present\n";
        else
               prev->next=temp->next;
    }
    free(temp);
    return lst;
}

void Display(struct node *lst)
{
    struct node *temp;
    cout<<"\nLIST->\n";
    for(temp=lst;temp!=NULL;temp=temp->next)
          cout<<temp->info<<"->";
    cout<<"|";
}