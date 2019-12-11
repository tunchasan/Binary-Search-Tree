#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

//Dugum sýnýfý
class Node {

private:

	friend class BinaryTree;

	int Number = -1;

	Node *right = NULL;

	Node *left = NULL;

	int familyCount = -1;

public:

	//Kurucu
	Node* createNode(int, Node*, Node*);

	int getNumber();

	Node();

};

#endif