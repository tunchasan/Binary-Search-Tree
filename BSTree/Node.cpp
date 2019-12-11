/**
* @file  BSTree
* @description Kabaca 2'li arama a�a�lar� aras�nda soy a�a� say�lar�na ba�l� olarak ekleme , silme i�lemi yapan konsol uygulamas�.
* @course  2B
* @assignment  3.�dev
* @date  10.12.2019
* @author  Ahmet Kayac� / G171210010
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