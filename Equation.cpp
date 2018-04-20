#include "Equation.h"
#include <iostream>

Equation::Equation()
{
	cout << "Enter Number Of Variables In Equation" << endl;
	cin >> n;
	cout << "Enter Coefficients Of These Variables In Order" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter Coefficient Of Variable : " << i + 1 << endl;
		float temp;
		cin >> temp;
		LHS.push_back(temp);
	}
	cout << "Enter Absolute Value Of The Equation " <<endl;
	cin >> RHS;
}



Equation::Equation(int v)
{
	n = v;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter Coefficient Of Variable : " << i + 1 << endl;
		float temp;
		cin >> temp;
		LHS.push_back(temp);
	}
	cout << "Enter Absolute Value Of The Equation " << endl;
	cin >> RHS;
}

Equation::~Equation()
{



}

void Equation::display()
{
	for (int i = 0; i < n; i++)
	{
		if(i==0)
			cout << LHS[i] << "X" << i + 1 << " ";
		else 
			if (LHS[i] > 0 )
				cout << "+ " <<LHS[i] << "X" << i + 1 << " ";
			else
				cout <<" "<< LHS[i] << "X" << i + 1 << " ";
	}
	cout << "= " << RHS << endl;
}

int Equation::getVarSize()
{
	return n;
}


float Equation::getVarCoef(int i)
{
	return LHS[i];
}

float Equation::getRHS()
{
	return RHS;
}