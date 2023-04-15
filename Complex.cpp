#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
typedef struct complex {
	double real, img;
};

complex addComplex(complex a, complex b){
	complex res;
	res.real = a.real + b.real;
	res.img = a.img + b.img;
	return res;
}

complex subComplex(complex a, complex b){
	complex res;
	res.real = a.real - b.real;
	res.img = a.img - b.img;
	return res;
}

complex mulComplex(complex a, complex b){
	complex res;
	res.real = a.real * b.real - a.img * b.img;
	res.img = a.real * b.img + b.real * a.img;
	return res;
}

complex divComplex(complex a, complex b){
	complex res;
	res.real = (a.real * b.real + a.img * b.img) / (b.real * b.real + b.img * b.img);
	res.img = (a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img);
	return res;
}

void displayComplex(complex c){
	if(c.img > 0){
		cout << c.real << "+" << c.img << "i";
	} else if(c.img < 0) {
		cout << c.real << c.img << "i";
	} else {
		cout << c.real;
	}
}
void main(){
	complex ans;
	complex c1, c2;
	int ch;
	cout << "\nEnter Complex Number 1 (Real): ";
	cin >> c1.real;
	cout << "\nEnter Complex Number 1 (Imaginary): ";
	cin >> c1.img;
	cout << "\nEnter Complex Number 2 (Real): ";
	cin >> c2.real;
	cout << "\nEnter Complex Number 2 (Imaginary): ";
	cin >> c2.img;
	cout << "\n\nReal Number 1: ";
	displayComplex(c1);
	cout << "\nReal Number 2: ";
	displayComplex(c2);
	cout << "\n\n\nWhich arithmetic operation do you want to perform?";
	cout << "\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n\n";
	cout << "\nEnter Choice:";
	cin >> ch;
	switch(ch){
		case 1:
			cout << "\n\nAddition:\n";
			ans = addComplex(c1, c2);
			displayComplex(ans);
			break;
		case 2:
			cout << "\n\nSubtraction:\n";
			ans = subComplex(c1, c2);
			displayComplex(ans);
			break;
		case 3:
			cout << "\n\nMultiplication:\n";
			ans = mulComplex(c1, c2);
			displayComplex(ans);
			break;
		case 4:
			cout << "\n\nDivision:\n";
			ans = divComplex(c1, c2);
			displayComplex(ans);
			break;
		default:
			cout << "\nInvalid Choice!!!";
	}
}