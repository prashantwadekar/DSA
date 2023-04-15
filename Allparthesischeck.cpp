#include<iostream>
#include<stdio.h>
using namespace std;
int top=-1;
void Push(char[],char);
char Pop(char[]);
int main()
{
    char expr[40],st[20],ele;
    int i;
    cout<<"Enter Expression:\n";
    i=0;
    while((expr[i++]=getchar())!='\n');
    expr[--i]='\0';
    for(i=0;expr[i]!='\0';i++)
    {
        if(expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            Push(st,expr[i]);
        }
        else
        {
         if(expr[i]==')'||expr[i]==']'||expr[i]=='}')
         {
            if(top>-1)
            {
                ele=Pop(st);
            
            switch (ele)
            {
            case '(':
                    if(expr[i]==']'||expr[i]=='}')
                    {
                        cout<<") required";
                    }
                break;


            case '[':
                  if(expr[i]=='}'||expr[i]==')')
                  {
                    cout<<"] required";
                  }
                break;
                

            case '{':
                 if(expr[i]==')'||expr[i]==']')
                 {
                    cout<<"} required";
                 }
                break;
            
            }
         }
         else
         {
            switch (expr[i])
            {
            case ')':
                        cout<<"( required";
                    break;

            case ']':
                    cout<<"[ required";
                break;

            case '}':
                    cout<<"{ required";
                 break;
            }
         }
        }
    }
    }
while(top>-1)
{
    ele=Pop(st);
    switch(ele)
    {
        case '(':
            cout<<") required";
            break;

        case '[':
            cout<<"] required";
            break;

        case '{':
            cout<<"} required";
            break;

    }
}
}


void Push(char st[20],char ele)
{
    st[++top]=ele;
}
char Pop(char st[20])
{
    char e;
    e=st[top--];
    return e;
}