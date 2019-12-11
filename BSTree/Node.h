#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node {

public:

	int Number = -1;

	Node *right = NULL;

	Node *left = NULL;

	int familyCount = -1;

public:

	//Kurucu
	Node* createNode(int, Node*, Node*);

	Node();

};

#endif