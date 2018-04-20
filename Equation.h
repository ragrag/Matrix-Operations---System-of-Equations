#pragma once
#include <vector>
using namespace std;
class Equation
{

private :
	int n;
	vector <float > LHS;
	float RHS;
public :
	Equation();
	Equation(int);
	~Equation();
	int getVarSize();
	float getVarCoef(int);
	float getRHS();
	void display();
};