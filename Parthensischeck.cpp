#include<stdio.h>
#include<iostream>
void Push(char[],char);
char Pop(char[]);
int top=-1;
using namespace std;
int main()
{
    char expr[40],st[20],ele;
    int i;
    cout<<"Enter expression\n";
    i=0;
    while((expr[i++]=getchar())!='\n');
    expr[--i]='\0';
    for(i=0;expr[i]!='\0';i++)
    {      
        if(expr[i]=='(')
        {
            Push(st,expr[i]);
        }
        else
        {
            if(expr[i]==')')
            {
                if(top==-1)
                {
                    cout<<"\n ( required";
                }
                else
                {
                    ele=Pop(st);
                }
            }
        }
    }
    if(top!=-1)
    {
        while(top>-1)
        {
            ele=Pop(st);
              cout<<") required";
        }
    }
}

void Push(char st[20],char ele)
{
    top++;
    st[top]=ele;
}
char Pop(char st[20])
{
    char ele;
    ele=st[top];
    top--;
    return ele;
}