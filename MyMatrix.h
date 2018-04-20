#pragma once
using namespace std;
#include <utility>
class MyMatrix
{

public :
	int row;
	int column;
	float data[30][30] = { 0 };

public :
	
	MyMatrix(int, int, float[30][30]);
	MyMatrix(int, int);
	MyMatrix();
	~MyMatrix();
	void setSize(int, int);
	pair <int , int> getSize();
	void setValues(float[30][30]);
	void setValues(int, int ,float[30][30]);
	double getDeterminant(double , int, float [30][30]);
	

	static MyMatrix zeroMatrix(int, int);	static MyMatrix identityMatrix(int);

	MyMatrix transpose();
	MyMatrix inverse();


	MyMatrix sum(MyMatrix);
	MyMatrix multiply(MyMatrix);
	MyMatrix scalarMultiply(int);

	bool validForMultiplication(MyMatrix);
	bool validForSum(MyMatrix);
	bool isSymmetric();
	bool isSquare();
	bool equals(MyMatrix);	void display();
};
