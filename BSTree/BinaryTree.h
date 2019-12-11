#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

class BinaryTree {

private:

	//Root of the tree.
	Node* root = NULL;

	int totalCount = 0;

public:

	//Getting number for assining the tree.
	Node*getNumber(Node*,int);

	int findTotalFamilCount();

	//Find the familyCount for each node.
	void findFamilyCount(Node*);

	//Write the Binary Tree
	void postorderTravel(Node*);

	//
	void updateFamilyCount (Node*);

	//getfamily Total Count
	int getTotalCount();

	//write tree
	void writeTree(Node*);
};

#endif
