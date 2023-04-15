#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void Insert(int[],int);
int Xdelete(int[]);
void Display(int []);
int front ,rear;
int main()
{
    int q[10],ele;
    char ch;
    front=rear=-1;
    do{
        cout<<"\n\t Options\tChoice";
        cout<<"\n \t Insert\t\t I/i";
        cout<<"\n\t Delete\t\t D/d";
        cout<<"\n\t Exit\t\t X/x";
        cout<<"\nEnter Your Choice:\t";
        do{
            ch=getchar();
        }while(strchr("IiDdXx",ch)==NULL);

        switch(ch)
        {
            case 'I':
            case 'i':
                    if(rear<9)
                    {
                        cout<<"Enter Element:\n";
                        cin>>ele;
                        Insert(q,ele);
                        cout<<"**Queue**";
                        Display(q);
                    }
                    else{
                        cout<<"\nQueue is Full";
                    }
                break;

            case 'D':
            case 'd':
                 if(front==-1)
                 {
                    cout<<"\nQueue is Empty";
                 }
                 else
                 {
                    ele=Xdelete(q);
                    cout<<"\nDeleted Element is:"<<ele;
                    if(front==-1)
                    {
                        cout<<"\nQueue has becomes empty";
                    }
                    else
                    {
                        cout<<"\n**Queue**";
                        Display(q);
                    }
                 }
        }
    }
    while((ch!='X')&&(ch!='x'));
}

void Insert(int q[10],int ele)
{
    rear++;
    q[rear]=ele;
    if(front==-1)
        front=rear;
}
int Xdelete(int q[10])
{
    int ele,i;
    ele=q[front];
    i=front;
    while(i<rear)
    {
        q[i]=q[i+1];
        i++;
    }
    rear--;
    if(rear==-1)
         front=-1;
    
    return ele;
}
void Display(int q[10])
{
    int i;
    cout<<"\nFront->";
    for(i=front;i<=rear;i++)
    {
        cout<<q[i]<<"->";
    }
    cout<<"Rear";
}