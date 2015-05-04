#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "TreeNode.h"
#include "TreeNode.hpp"

using namespace std;

template<typename T>

class BSTree 
{
public:
	BSTree();
	TreeNode<T> * Search(T data, TreeNode<T> *node);
	TreeNode<T> * Insert(T data, TreeNode<T> *node);
	TreeNode<T> * Delete(T data, TreeNode<T> *node, bool &nodeDeleted);
	TreeNode<T> *root;

protected:
	TreeNode<T> * FindMin(TreeNode<T> *node);
	TreeNode<T> * FindMax(TreeNode<T> *node);
	bool isEqual(double i, double j);
};