#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "Shape.h"

using namespace std;

class Rectangle: public Shape
{
public:
	Rectangle(){};
	~Rectangle(){};
protected:
	int width, height;
public:
	void SetSides(int w, int h)
	{ 
		width = w; 
		height = h;
	}
	void CheckValidity()
	{
		/*if (width <= 0)
			throw runtime_error("Invalid width.");
		if (height <= 0)
			throw runtime_error("Invalid height.");*/
		if (width <= 0 || height <= 0)
			throw runtime_error("One of more invalid sides.");
	}
	double GetArea()
	{
		return width * height;
	}
};