#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
void Push(char[],char);
char Pop(char[]);
int top=-1;
int main()
{
    char expr[40],Postfix[40],st[20],ele;
    int i,j;
    cout<<"\n Enter Expression\n";
    i=0;
    while((expr[i++]=getchar())!='\n');
    expr[--i]='\0';
    for(i=0,j=0;expr[i]!='\0';i++)
    {
        if((expr[i]=='+')||(expr[i]=='-')||(expr[i]=='*')||(expr[i]=='/'))
        {
            if(top==-1)
            {
                Push(st,expr[i]);
            }
            else
            {
                ele=Pop(st);
                switch(ele)
                {
                    case '*':
                    case '/':
                            if((expr[i]=='+')||(expr[i]=='-'))
                            {
                                Postfix[j++]=ele;
                                Push(st,expr[i]);
                            }
                            break;
                    default:
                           Push(st,ele);
                           Push(st,expr[i]);
                }
            }
        }
        else
        {
            if(expr[i]=='(')
            {
                Push(st,expr[i]);
            }
            else
            {
                if(expr[i]==')')
                {
                    ele=Pop(st);
                    while(ele!='(')
                    {
                        Postfix[j++]=ele;
                        ele=Pop(st);
                    }
                }
                else
                {
                    Postfix[j++]=expr[i];
                }
            }
        }
    }
    while(top>-1)
    {
        Postfix[j++]=Pop(st);
    }
    Postfix[j]='\0';
    cout<<"\n Postfix expression is:\t"<<Postfix;
}
void Push(char st[20],char ele)
{
    st[++top]=ele;

}
char Pop(char st[20])
{
    char ele;
    ele=st[top--];
    return ele;
}