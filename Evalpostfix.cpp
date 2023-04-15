#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
void Push(int[],int);
int Pop(int[]);
int top=-1;
int eval(int,int,char);
int main()
{
    char expr[40];
    int st[20],ele,i,op1,op2,res;
    cout<<"\nEnter Expression\n";
    i=0;
    while((expr[i++]=getchar())!='\n');
    expr[--i]='\0';
    for(i=0;expr[i]!='\0';i++)
    {
        if((expr[i]>='0')&&(expr[i]<='9'))
                 Push(st,expr[i]-'0');
        else
        {
            op2=Pop(st);
            op1=Pop(st);
            res=eval(op1,op2,expr[i]);
            Push(st,res);
        }
    }
    res=Pop(st);
    cout<<"\nResult of expression is:"<<res;
}
void Push(int st[20],int ele)
{
    st[++top]=ele;
}
int Pop(int st[20])
{
    int ele;
    ele=st[top--];
    return ele;
}
int eval(int op1,int op2,char o)
{
    switch(o)
    {
        case '+':
                return(op1+op2);
                break;
        case '-':
                return(op1-op2);
                break;
        
        case '*':
               return(op1*op2);
               break;
            
        case '/':
               return(op1/op2);
    }
    return op1/op2;
}