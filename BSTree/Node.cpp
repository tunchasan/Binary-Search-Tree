/**
* @file  BSTree
* @description Kabaca 2'li arama ağaçları arasında soy ağaç sayılarına bağlı olarak ekleme , silme işlemi yapan konsol uygulaması.
* @course  2B
* @assignment  3.Ödev
* @date  10.12.2019
* @author  Ahmet Kayacı / G171210010
**/

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

int Node::getNumber()
{
	return Number;
}

//Empty Constructor
Node::Node() {}