#include <iostream>
#include <string.h>
using namespace std;
int top;
void Push(int[],int);
int Pop(int[]);
void Display(int[]);
int main()
{
    int st[10],ele;
    char ch;
    
    top=-1;

    do{
        cout<<"\n**Options choice**\n";
        cout<<"Push P/p\n";
        cout<<"Pop O/o\n";
        cout<<"Display D/d\n";
        cout<<"Exit X/x";
        
        cout<<"\n\nEnter your choice\t\n";
        
        do{
            ch=getchar();
        }while(strchr("PpOoXxDd",ch)==NULL);

        switch(ch)
        {
            case 'P':
            case 'p':
                    if(top<9)
                    {
                        cout<<"\nEnter Element in stack\n";
                        cin>>ele;
                        Push(st,ele);
                        cout<<"####STACK####\n";
                        Display(st);
                    }
                    else{
                        cout<<"\nStack is Full\n";
                    }
                     break;
           

            case 'O':
            case 'o':
                   if(top==-1)
                   {
                    cout<<"\nStack is Empty\n";
                   }
                   else
                   {
                    ele=Pop(st);
                    {
                        cout<<"\nPop element is:\t"<<ele;
                    }
                    if(top==-1)
                    {
                       cout<<"\nstack becomes empty\n";
                    }
                    else{
                         cout<<"\n####STACK####";
                        Display(st);
                    }
                      break;
                   }
           

            case 'D':
            case 'd':
                   if(top==-1)
                   {
                    cout<<"\nStack is Empty\n";
                   }
                   else
                   {
                        cout<<"####STACK####";
                        Display(st);
                    }
                   break;
        }
    }while(ch!='X'&&ch!='x');
}

void Push(int st[10],int ele)
{
    top++;
    st[top]=ele;
}
int Pop(int st[10])
{
    int temp=st[top];
    top--;
    return temp;
}
void Display(int st[10])
{
    int i;
    cout<<"\nTop->";
    for(i=top;i>-1;i--)
    {
        cout<<"|"<<st[i]<<"|"<<"->";
    }
     cout<<"\n";
}

