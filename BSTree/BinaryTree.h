#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

class BinaryTree {

private:

	//Root of the tree.
	Node* root = NULL;

public:

	//Getting number for assining the tree.
	Node*getNumber(Node*,int);

};

#endif
