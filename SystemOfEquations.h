#pragma once
#include <vector>
#include "Equation.h"
using namespace std;



class SystemOfEquations
{
private:
	vector <Equation> equations;

public:
	SystemOfEquations();
	~SystemOfEquations();
	void insertNewEquation(Equation);
	void swapEquations(int , int );
	vector <float> solveSystem();
	void display();
};