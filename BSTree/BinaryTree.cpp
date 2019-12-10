#include "pch.h"
#include "BinaryTree.h"

Node * BinaryTree::getNumber(Node *tree, int rakam)
{
	if (tree == NULL) {

		tree = tree->createNode(rakam, NULL, NULL);

		return tree;

	}

	else if (tree->Number < rakam || tree->Number == rakam) {

		tree->right = getNumber(tree->right, rakam);

		return tree;
	}

	tree->left = getNumber(tree->left, rakam);

	return tree;
}
