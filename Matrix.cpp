#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>
using namespace std;
//defining row and col size to 10
#define MAXROWS 10
#define MAXCOLS 10

//creating matrix structure
typedef struct matrix{
	int r,c;
	int m[MAXROWS][MAXCOLS];
};

matrix getmat()
{
 matrix t;
 int r,c,i,j;
 //here r=rows c=cols and i=row itterator and j=cols itterator

 //getting size of matrix
 cout<<"\nEnter Numbers of rows: ";
 cin>>r;
 cout<<"\nEnter Number of columns: ";
 cin>>c;

 //getting elements of matrix
 cout<<"\nEnter MATRIX elements :\n";

 //loop for rows
 for(i=0;i<r;i++)
 {
  //loop for cols
	for(j=0;j<c;j++)
	{
		cout<<"\nEnter element of order [ ROW : "<<i+1<<"][ COLOUMN : "<<j+1<<"] : ";
		cin>>t.m[i][j];
	 }
 }
 // setting order/size of matrix
	t.r=r;
	t.c=c;
  return t;
}

void printmat(matrix t)
{
 int i,j;
 //i=row itterator j=cols itterator
 cout<<"\nTHE MATRIX IS: \n";
 //loop for rows
 for(i=0;i<t.r;i++)
 {
  //loop for cols
	for(j=0;j<t.c;j++)
	cout<<"  "<< t.m[i][j]<<"  " ;
	cout<<"\n";

 }
}

matrix add(matrix m1,matrix m2)
{
 matrix t;
 int i,j;
 if((m1.r==m2.r)&&(m1.c==m2.c))
 {
	 for(i=0;i<m1.r;i++)
		{
			for(j=0;j<m1.c;j++)
				t.m[i][j]=m1.m[i][j]+m2.m[i][j];
		}
 t.r=m1.r;
 t.c=m2.c;
 return t;
 }
 else
 {
  cout << "\n SIZE OF TWO MATRISES MUST BE SAME FOR ADDITION:";
 }
}

matrix sub(matrix m1,matrix m2)
{
 matrix t;
 int i,j;
 if((m1.r==m2.r)&&(m1.c==m2.c))
 {
	 for(i=0;i<m1.r;i++)
		{
			for(j=0;j<m1.c;j++)
				t.m[i][j]=m1.m[i][j]-m2.m[i][j];
		}
 t.r=m1.r;
 t.c=m2.c;
 return t;
 }
 else
 {
  cout << "\n SIZE OF TWO MATRISES MUST BE SAME FOR SUBSTRACTION:";
 }
}

matrix mult(matrix m1, matrix m2)
{
 matrix m3;
 int i,j,k;
 if(m1.c==m2.r)
 {
  m3.r=m1.r;
  m3.c=m2.c;
  for (i=0;i<m1.r;i++)
  {
	for(j=0;j<m2.c;j++)
		{
		  m3.m[i][j]=0;
			for(k=0;k<m2.r;k++)
				{
				       m3.m[i][j]=m1.m[i][k]*m2.m[k][j];
				}
		}
  }
   return m3;

 }
 else
 {
  cout<<"\n NUMBER OF ROWS OF FIRST MATRIX MUST BE SAME AS NUMBER OF COLUMN OF SECOND";
 }

}
int main()
{
 matrix m1,m2,m3,m4,m5;
 char ch;
 cout << "\t\t\t\t>>WELCOME TO MATRIX<<" ;
 m1=getmat();
 printmat(m1);
 m2=getmat();
 printmat(m2);
 do
 {
     cout<<"\nOPTION\tCHOICE:";
     cout<<"\nADDITION\tA/a";
     cout<<"\nSUBSTRACTION\tS/s";
     cout<<"\nMULTIPLICATION\tM/m";
     cout<<"\nDIVISION\tD/d";
     cout<<"\nEXIT\tX/x";
	do
		{
		    ch=getchar();
		}while(strchr("AaSsMmDdXx",ch)==NULL);

	switch(ch)
	{
		case 'A':
		case 'a':
			 m3=add(m1,m2);
			 cout<<"\nADDITION IS :";
			 printmat(m3);
			 break;
		case 'S':
		case 's':
			 m4=sub(m1,m2);
			 cout<<"\nSUBSTRACTION IS :";
			 printmat(m4);
			 break;
		case 'M':
		case 'm':
			 m5=mult(m1,m2);
			 cout<<"\nMULTIPLICATION IS :";
			 printmat(m5);

	}

 }while(ch!='x' && ch!='X');


}