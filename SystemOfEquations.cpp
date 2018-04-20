#include "SystemOfEquations.h"
#include "MyMatrix.h"
using namespace std;
#include <iostream>


SystemOfEquations::SystemOfEquations()
{

}

SystemOfEquations::~SystemOfEquations()
{

}

void SystemOfEquations::insertNewEquation(Equation e)
{
	equations.push_back(e);
}

void SystemOfEquations::display()
{
	for (int i = 0; i < equations.size(); i++)
	{
		cout << i + 1 << ") ";
	    equations[i].display();
	}
}
void SystemOfEquations::swapEquations(int i, int j)
{
	iter_swap(equations.begin()+ (i-1), equations.begin() + (j - 1));

}

vector <float > SystemOfEquations::solveSystem()
{
	vector <float> solutions;
	int neq = equations.size();
	double determinant = 0;
	float ar[30][30];
	float temp[30][30];
	for (int i = 0; i < neq; i++)
	{
		for (int j = 0; j < neq; j++)
		{
			ar[i][j] = equations[i].getVarCoef(j);
			temp[i][j] = equations[i].getVarCoef(j);
		}

	}

	determinant = MyMatrix (neq, neq, ar).getDeterminant(0,neq,ar);
	
	for (int i = 0; i < neq; i++)
	{
		for (int j = 0; j < neq; j++)
		{
			temp[j][i] = equations[j].getRHS();
		}

		solutions.push_back((float)MyMatrix(neq, neq, temp).getDeterminant(0, neq, temp) / determinant);
		
		
		for (int k = 0; k < neq; k++)
		{
			for (int o = 0; o < neq; o++)
			{
				temp[k][o] = ar[k][o];
			}
		}

	}
	return solutions;
}
