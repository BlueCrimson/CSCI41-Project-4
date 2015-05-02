#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;

class Shape
{
public:
	virtual void CheckValidity() = 0;
	virtual double GetArea() = 0;
};