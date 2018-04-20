#include "MyMatrix.h"
#include <algorithm>
#include <math.h>
#include <iostream>
#include <iomanip>



MyMatrix::MyMatrix()
{
	cout << "Enter Size of Rows" << endl;
	cin >> row;
	cout << "Enter Size of Columns" << endl;
	cin >> column;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << "r" << i+1 << "c" << j+1 << ": " << endl;
			cin >> data[i][j];
		}
	}

}

MyMatrix::MyMatrix(int r, int c)
{
	
	row = r;
	column = c;
	
}

MyMatrix::MyMatrix(int r, int c, float d[30][30])
{
	row = r;
	column = c;
	setValues(d);
}

MyMatrix::~MyMatrix()
{

}

void MyMatrix::setSize(int r, int c)
{
	row = r;
	column = c;
}


pair<int,int> MyMatrix::getSize()
{
	return make_pair(row, column);
}


void MyMatrix::setValues(float d[30][30])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			data[i][j] = d[i][j];
	}
}

void MyMatrix::setValues(int r, int c, float d[30][30])
{
	row = r;
	column = c;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			data[i][j] = d[i][j];
	}
}

MyMatrix MyMatrix::zeroMatrix(int x, int y)
{
	float d[30][30] = { 0 };
	return MyMatrix(x, y, d);

}

bool MyMatrix::isSquare()
{
	return (row == column);
}

MyMatrix MyMatrix::identityMatrix(int x)
{
	
	float d[30][30] = { 0 };
	for (int i = 0; i < x; i++)
		d[i][i] = 1;

	return MyMatrix(x, x,d);
	
}


MyMatrix MyMatrix::transpose()
{
	float newData[30][30];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			newData[j][i] = data[i][j];
		}
	}
	return MyMatrix (column, row, newData);
}



double MyMatrix::getDeterminant( double determinant , int rc ,float d[30][30] )
{
	
	float submat[30][30];

	int n, m;
	if (rc == 2)
	{
		return((d[0][0] * d[1][1]) - (d[1][0] * d[0][1]));
	}
	else
	{
		for (int i = 0; i < rc; i++)
		{
			n = 0;
			for (int j = 1; j < rc; j++)
			{
				m= 0;
				for (int k = 0; k < rc; k++)
				{
					if (k == i)
					{
						continue;
					}
					submat[n][m] = d[j][k];
					m++;
				}
				n++;
			}
			determinant += (pow(-1, i) * d[0][i] * getDeterminant( 0, rc-1, submat));
		}
	}
	return (double) determinant;
}



MyMatrix MyMatrix::inverse()
{
	if(isSquare())
		if (getDeterminant(0, row,data) != 0)
		{
			int i, j, k;
			float temp;
			for (int i = 0; i < row; i++)			
				for (int j = 0; j < 2 * row; j++)
					if (j == (i + row))
						data[i][j] = 1;

			for (i = row; i > 1; i--)
			{
				if (data[i - 1][1] < data[i][1])
					for (j = 0; j < row * 2; j++)
					{
						temp = data[i][j];
						data[i][j] = data[i - 1][j];
						data[i - 1][j] = temp;
					}
			}


			for (i = 0; i < row; i++)
			{
				for (j = 0; j < row * 2; j++)
					if (j != i)
					{
						temp = data[j][i] / data[i][i];
						for (k = 0; k < row * 2; k++)
							data[j][k] -= data[i][k] * temp;
					}
			}

			for (i = 0; i < row; i++)
			{
				temp = data[i][i];
				for (j = 0; j < row * 2; j++)
					data[i][j] = data[i][j] / temp;
			}

			for (i = 0; i < row; i++)
			{
				for (int j = 0; j < row; j++)
					data[i][j] = data[i][j + row];
			}
			return *this;
		}
	
	cout << "This Matrix is uninvertable, Data not changed" << endl;;
		return *this;
	
}




bool MyMatrix::validForMultiplication(MyMatrix m)
{

	pair <int, int> r = m.getSize();
	int temp = r.first;
	r.first = r.second;
	r.second = temp;
	if (getSize() == r)
		return true;
	return false;
	
}

bool MyMatrix::validForSum(MyMatrix m)
{
	return (getSize() == m.getSize());
}


MyMatrix MyMatrix::sum(MyMatrix m)
{
	if (validForSum(m))
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				data[i][j] += m.data[i][j];
			}
		}
		return *this;
	}
	else 
		cout << "The two Matrices are not valid for summation, values not changed";
	return *this;
}

MyMatrix MyMatrix::multiply(MyMatrix m)
{
	if (validForMultiplication(m))
	{

		float newData[30][30] = { 0 };
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < m.column; j++)
			{
				for (int k = 0; k < column; k++)
					newData[i][j] += (data[i][k] * m.data[k][j]);
			}
		}
		return  MyMatrix(row, m.column, newData);
	}
	else 
		cout << "The two Matrices are not valid for multiplication, values not changed";
	return *this;
}

MyMatrix MyMatrix::scalarMultiply(int x)
{
	float newData[30][30] = { 0 };
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			newData[i][j] = data[i][j] * x;
		}
	}
	return MyMatrix(row, column, newData);
}

bool MyMatrix::isSymmetric()
{
	return (row == column && equals(transpose()));
}

bool MyMatrix::equals(MyMatrix m)
{
	if(getSize() == m.getSize())
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (data[i][j] != m.data[i][j])
					return false;
			}
		}
	else return false;
	return true;
}



void MyMatrix::display()
{
	streamsize prec = cout.precision();
	cout.precision(2);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			cout << data[i][j] << " ";
		cout<< endl;
	}
	cout.precision(prec);
}

