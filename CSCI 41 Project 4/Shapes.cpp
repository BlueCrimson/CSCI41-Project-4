//----------------------------------------------------------------------------------------//
// Programmer: Kevin Ngo
// Class: CSCI 41
// Instructor: Dr. Ming Li
// Project 3: Linked Lists, Exception Handling, Pointers
//----------------------------------------------------------------------------------------//

#include "stdafx.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "BSTree.h"
#include "BSTree.hpp"

using namespace std;

BSTree<double> *RectTree = new BSTree<double>();
BSTree<double> *TrglTree = new BSTree<double>();

void PrintAreaInOrder(TreeNode<double> *node)
{
	if (node == NULL)
		return;
	PrintAreaInOrder(node->GetLeft());
	cout << node->GetData() << endl;
	PrintAreaInOrder(node->GetRight());
}

void PromptRectArea()
{
	double area; 
	cout << "Select an area value to delete: ";
	cin >> area;
	try
	{
		RectTree->Delete(area, RectTree->root);
		cout << "Area found and deleted." << endl;
	}
	catch(runtime_error &err)
	{
		cout << "Area not found." << endl;
	}
}

void ReadRectData()
{
	if (RectTree->root != 0)
		return;

	ifstream inFileRect;
	inFileRect.open("C:\\Rsides.txt");

	if (inFileRect.fail())
		throw runtime_error("Error opening file.");

	Rectangle rect;
	int w, h;
	while (true)
	{
		w = 0; h = 0;
		inFileRect >> w >> h;
		rect.SetSides(w, h);
		try 
		{ 
			rect.CheckValidity();
			if (RectTree->root == 0)
				RectTree->root = new TreeNode<double>(rect.GetArea());
			else 
				RectTree->Insert(rect.GetArea(), RectTree->root);
		}
		catch(runtime_error &err)
		{
			cout << err.what() << endl;
		}
		if (inFileRect.eof())
			break;
	}
}

/*
void PrintTrglArea()
{
	Node* curr = TrglList->head;
	while (curr != 0)
	{
		curr->PrintNodeData();
		curr = curr->GetNext();
	}
}

void PromptTrglArea()
{
	double area;
	cout << "Select an area value to delete: ";
	cin >> area;
	Node* node = TrglList->Search(area);
	try
	{
		TrglList->RemoveNode(node);
		cout << "Area found and deleted." << endl;
	}
	catch(runtime_error &err)
	{
		cout << "Area not found." << endl;
	}

}

void ReadTrglData()
{
	if (TrglList->head != 0)
		return;

	ifstream inFileTrgl;
	inFileTrgl.open("C:\\Tsides.txt");

	if (inFileTrgl.fail())
		throw runtime_error("Error opening file.");

	Triangle trgl;
	int a, b, c;
	while (true)
	{
		a = 0; b = 0; c = 0;
		inFileTrgl >> a >> b >> c;
		trgl.SetSides(a, b, c);
		try 
		{ 
			trgl.CheckValidity();
			TrglNode* node = new TrglNode(trgl);
			if (TrglList->head == 0)
				TrglList->head = node;
			else 
				TrglList->InsertInOrder(node);
		}
		catch(runtime_error &err)
		{
			cout << err.what() << endl;
		}
		if (inFileTrgl.eof())
			break;
	}
}
*/
int _tmain(int argc, _TCHAR* argv[])
{
	

	char option = '0';
	while(option != '3')
	{
		cout << "Select one of the following options to search area values: " << endl;
		cout << "		1. Rectangle" << endl;
		cout << "		2. Triangle" << endl;
		cout << "		3. Quit" << endl;

		cin >> option;
		if(option == '1')
		{
			try
			{
				ReadRectData();
			}
			catch (runtime_error &err)
			{
				cout << err.what() << endl;
				system("PAUSE");
				exit(1);
			}
			PrintAreaInOrder(RectTree->root);
			PromptRectArea();
		}
		/*else if(option == '2')
		{
			try
			{
				ReadTrglData();
			}
			catch (runtime_error &err)
			{
				cout << err.what() << endl;
				system("PAUSE");
				exit(1);
			}
			PrintTrglArea();
			PromptTrglArea();
		}
		else if(option == '3')
		{
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "Invalid option." << endl;
		}*/
	}
	system("PAUSE");
	return 0;
}

