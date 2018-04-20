#include <iostream>
using namespace std;
#include "MyMatrix.h"
#include "SystemOfEquations.h"
#include "Equation.h"
#include <conio.h>


void mainScreen();
void matrixScreen();
void matrixOperations();
void equationScreen();

void mainScreen()
{
	
	int selection = -1;
	while (selection != 1 && selection != 2)
	{
		system("CLS");
		cout << "Raggi 144711 CS" << endl;
		cout << "1- Matrix" << endl;
		cout << "2- Equations" << endl;
		cin >> selection;
	}
	if (selection == 1)
	{
		matrixScreen();
		return;
	}
	if (selection == 2)
	{
		equationScreen();
		return;
	}
}

void equationScreen()
{	
	system("CLS");
	SystemOfEquations sys;
	int n;
	cout << "Enter Number Of Unknown Variables: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Equation " << i + 1 << endl;
		sys.insertNewEquation(Equation(n));
	}

	startEquations:
		int selection = -1;
		while (selection != 1 && selection != 2 && selection !=3)
		{
			system("CLS");
			cout << "1 - Swap Equations" << endl;
			cout << "2 - Solve System" << endl;
			cout << "3 - Back To Main Screen" << endl;
			cin >> selection;
		}
		if (selection == 1)
		{
			system("CLS");
			sys.display();
			int l, r;
			cout << "Enter First Equation" << endl;
			cin >> l;
			cout << "Enter Second Equation" << endl;
			cin >> r;
			sys.swapEquations(l, r);
			system("CLS");
			sys.display();
			cout << "\nEquations Swapped!" << endl;

			cout << "Press any key to go back" << endl;
			_getch();
			goto startEquations;
			
		}
		if (selection == 2)
		{
			system("CLS");
			cout << "Solution Of System : " << endl;
			vector <float> results = sys.solveSystem();

			for (int i = 0; i < results.size(); i++)
			{
				cout << "x" << i + 1 << " = " << results[i] << endl;
			}

			cout << "Press any key to go back" << endl;
			_getch();
			goto startEquations;

		}

		if (selection == 3)
		{
			mainScreen();
			return;

		}

}

void matrixOperations()
{
	
	system("CLS");
	MyMatrix one;

 startOperations:
	
	int selection = -1;
	while (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5 && selection != 6 && selection != 7 && selection != 8 && selection != 9 && selection != 10 && selection != 11)
	{
		system("CLS");
		cout << "1 - Change Matrix Values" << endl;
		cout << "2 - Display" << endl;
		cout << "3 - Sum with Another Matrix" << endl;
		cout << "4 - Multiply by Another Matrix" << endl;
		cout << "5 - Scalar Multiply" << endl;
		cout << "6 - Transpose" << endl;
		cout << "7 - Inverse" << endl;
		cout << "8 - Get Determinant" << endl;
		cout << "9 - Check Symmetry" << endl;
		cout << "10 - Check Equality" << endl;
		cout << "\n11 - Back" << endl;
		cin >> selection;
	}
	if (selection == 1)
	{
		matrixOperations();
		return;
	}
	if (selection == 2)
	{
		system("CLS");
		one.display();
		cout << "Press any key to go back" << endl;
		_getch();
		goto startOperations;
	}
	if (selection == 3)
	{
		system("CLS");
		cout << "Enter Values Of The Second Matrix" << endl;
		MyMatrix two;
		system("CLS");
		cout << "THe Sum Of Matrix" << endl;
		one.display();
		cout << "And" << endl;
		two.display();
		cout << endl;
		MyMatrix three = one.sum(two);
		three.display();
		
		cout << "Press any key to go back" << endl;
		_getch();
		goto startOperations;
	}

	if (selection == 4)
	{
		system("CLS");
		cout << "Enter Values Of The Second Matrix" << endl;
		MyMatrix two;
		system("CLS");
		cout << "THe Product Of Matrix" << endl;
		one.display();
		cout << "And" << endl;
		two.display();
		cout << endl;
		MyMatrix three = one.multiply(two);
		three.display();

		cout << "Press any key to go back" << endl;
		_getch();
		goto startOperations;
	}

	if (selection == 5)
	{
		system("CLS");
		int k;
		cout << "Enter Value Of Multiplication" << endl;
		cin >> k;
		MyMatrix two = one.scalarMultiply(k);
	
		cout << "THe Product Of Matrix" << endl;
		one.display();
		cout << "By " << k << " Is : "<< endl;
		two.display();
		cout << endl;

		cout << "Press any key to go back" << endl;
		_getch();
		goto startOperations;
	}

	if (selection == 6)
	{
		system("CLS");
		MyMatrix two = one.transpose();
		cout << "THe Transpose Of Matrix" << endl;
		one.display();
		cout << "Is : "<< endl;
		two.display();
		cout << endl;

		cout << "Press any key to go back" << endl;
		_getch();
		goto startOperations;
	}

	if (selection == 7)
	{
		system("CLS");
		MyMatrix temp = one;
		cout << "THe Inverse Of Matrix" << endl;
		one.display();
		cout << "Is : " << endl;
		MyMatrix two = temp.inverse();
		two.display();
		cout << endl;

		cout << "Press any key to go back" << endl;
		_getch();
		goto startOperations;
	}

	if (selection == 8)
	{
		system("CLS");
		
		cout << "THe Determinant Of The Matrix" << endl;
		one.display();
		cout << "Is : " << endl;
	
		if (!one.isSquare())
			cout << "This Matrix Isn't A Square matrix" << endl;
		else cout << one.getDeterminant( 0, one.row,one.data) << endl;
		cout << "Press any key to go back" << endl;
		_getch();
		goto startOperations;
	}

	if (selection == 9)
	{
		system("CLS");
	
		one.isSymmetric()?	cout << "This Matrix Is Symmetric" << endl:	cout << "This Matrix Is Not Symmetric" << endl;

		cout << "Press any key to go back" << endl;
		_getch();
		goto startOperations;
	}

	if (selection == 10)
	{
		system("CLS");
		cout << "Enter Values Of The Second Matrix" << endl;
		MyMatrix two;
		system("CLS");
		cout << "Matrix" << endl;
		one.display();
		cout << "And" << endl;
		two.display();
		cout << endl;
		one.equals(two) ? cout << "Are Equal\n" : cout << "Are Not Equal\n";
		

		cout << "Press any key to go back" << endl;
		_getch();
		goto startOperations;
	}

	if (selection == 11)
	{
		matrixScreen();
		return;
	}

}
void matrixScreen()
{
startMatrixScreen : 	
	int selection = -1;
	while (selection != 1 && selection != 2 && selection != 3 && selection != 4)
	{
		system("CLS");
		cout << "-------- Matrix --------" << endl;
		cout << "1 - Matrix Operations" << endl;
		cout << "2 - Get Identity Matrix (n)" << endl;
		cout << "3 - Get Zeroes Matrix (n x n)" << endl;
		cout << "4 - Back to Main Screen" << endl;
		cin >> selection;
	}

	if (selection == 1)
	{
		matrixOperations();
		return;
	}

	if (selection == 2)
	{
		int n;
		cout << "Enter Size" << endl;
		cin >> n;
		MyMatrix identity = MyMatrix::identityMatrix(n);
		system("CLS");

		cout << "The Identiy Matrix Of Size " <<n <<" Is : "<< endl;
		identity.display();
		cout << "Press any key to go back" << endl;
		_getch();
		goto startMatrixScreen;
	}

	if (selection == 3)
	{
		int n,m;
		cout << "Enter Size of Rows " << endl;
		cin >> n;
		cout << "Enter Size of Columns " << endl;
		cin >> m;
		MyMatrix zero = MyMatrix::zeroMatrix(n,m);
		system("CLS");

		cout << "The Zero Matrix Of Size " << n <<" x " <<m << " Is : " << endl;
		zero.display();
		cout << "Press any key to go back" << endl;
		_getch();
		goto startMatrixScreen;
	}

	if (selection == 4)
	{
		mainScreen();
		return;
	}

}

void main()
{

	mainScreen();
	
}