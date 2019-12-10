#include "pch.h"
#include "Node.h"

Node *Node::createNode(int number, Node *right, Node *left)
{
	//Assign parametres to class fields
	Node *newNode = new Node();

	newNode->left = left;

	newNode->right = right;

	newNode->Number = number;

	return newNode;
}

//Empty Constructor
Node::Node() {

}