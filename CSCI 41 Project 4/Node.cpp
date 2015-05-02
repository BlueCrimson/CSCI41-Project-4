#include "stdafx.h"
#include "Node.h"

Node::Node()
{
	nextNodePtr = 0;
}

Node* Node::GetNext()
{
	return nextNodePtr;
}

void Node::SetNext(Node* nodePtr)
{
	nextNodePtr = nodePtr;
}