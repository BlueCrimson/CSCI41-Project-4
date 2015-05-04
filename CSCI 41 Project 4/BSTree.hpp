#include "stdafx.h"
#include "BSTree.h"
#include "TreeNode.h"
#include <stdexcept>

template <typename T>
BSTree<T>::BSTree() : root(0)
{

}

template <typename T>
TreeNode<T> *BSTree<T>::Search(T data, TreeNode<T> *node)
{
	if (node == NULL)
		throw runtime_error("Tree node is invalid.");
	
	int result = node->Compare(data);

	if (result == 0)
		return node;
	else if (result < 0)
		return Search(data, node->GetLeft());
	else
		return Search(data, node->GetRight());
}

template <typename T>
TreeNode<T> *BSTree<T>::FindMin(TreeNode<T> *node)
{
	if (node != NULL)
	{
		while (node->GetLeft() != NULL)
			node = node->GetLeft();
	}
	return node;
}

template <typename T>
TreeNode<T> *BSTree<T>::FindMax(TreeNode<T> *node)
{
	if (node == NULL)
		return NULL;
	else if (node->GetRight() == NULL)
		return node;
	else
		return FindMax(node->GetRight());
}

template <typename T>
TreeNode<T> *BSTree<T>::Insert(T data, TreeNode<T> *node)
{
	if (node == NULL)
		node = new TreeNode<T>(data);
	else if (data < node->GetData())
		node->SetLeft(Insert(data, node->GetLeft()));
	else if (data > node->GetData())
		node->SetRight(Insert(data, node->GetRight()));
	return node;
}

template <typename T>
TreeNode<T> *BSTree<T>::Delete(T data, TreeNode<T> *node, bool &nodeDeleted)
{
	TreeNode<T> *temp;
	nodeDeleted = false;

	if (node == NULL)
		throw runtime_error ("Tree node is invalid.");

	int result = node->Compare(data);
	if (result == 0)
	{
		temp = node;
		if (node->GetLeft() == NULL)
			node = node->GetRight();
		else if (node->GetRight() == NULL)
			node = node->GetLeft();
		delete temp;
		nodeDeleted = true;
	}
	else if (data < node->GetData())
		node->SetLeft(Delete(data, node->GetLeft(), nodeDeleted));
	else if (data > node->GetData())
		node->SetRight(Delete(data, node->GetRight(), nodeDeleted));
	else if (node->GetLeft() != NULL && node->GetRight() != NULL)
	{
		temp = FindMin(node->GetRight());
		node->SetData(temp->GetData());
		node->SetRight(Delete(node->GetData(), node->GetRight(), nodeDeleted));
	}

	return node;
}

