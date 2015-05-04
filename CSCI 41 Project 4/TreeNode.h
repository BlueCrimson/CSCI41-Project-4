#pragma once
#include <iostream>
#include <stdexcept>
#include <stdio.h>

using namespace std;

template <typename T>

class TreeNode 
{
public:
	TreeNode();
	TreeNode(T value);
	int Compare(T value);
	TreeNode *GetLeft();
	void SetLeft(TreeNode *node);
	TreeNode *GetRight();
	void SetRight(TreeNode *node);
	T GetData() const;
	void Print();
	void SetData(const T &value);

private:
	TreeNode *left;
	TreeNode *right;
	T data;
	bool isEqual(double i, double j);
};