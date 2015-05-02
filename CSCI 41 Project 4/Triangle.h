#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "Shape.h"

using namespace std;

class Triangle: public Shape
{
protected:
	int a, b, c;
public:
	void CheckValidity()
	{
		/*
		if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (b + c <= a) || (c + a <= b))
			return false;
		else
			return true;
		*/
		if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (b + c <= a) || (c + a <= b))
			throw runtime_error("One or more invalid sides.");
	}
	void SetSides(int _a, int _b, int _c)
	{
		a = _a;
		b = _b;
		c = _c;
	}

	double GetArea()
	{
		double p = (a + b + c) / 2.0;
		double Area = (p * (p - a) * (p - b) * (p - c));
		double result = sqrt(static_cast<double>(Area));
		return result;
	}
};