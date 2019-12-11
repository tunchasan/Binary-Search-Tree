#include "pch.h"
#include "BinaryTree.h"

int globalInt = -1;

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

void BinaryTree::findFamilyCount(Node *root)
{
	if (root == NULL)
		return;

	findFamilyCount(root->left);

	updateFamilyCount(root);

	root->familyCount = globalInt;

	totalCount += globalInt;

	globalInt = -1;

	findFamilyCount(root->right);

}

void BinaryTree::updateFamilyCount(Node *root) {

	if (root == NULL)
		return;

	updateFamilyCount(root->left);

	//Sayaç
	globalInt++;

	updateFamilyCount(root->right);
}

int BinaryTree::getTotalCount()
{
	return totalCount;
}

void BinaryTree::writeTree(Node *root)
{
	postorderTravel(root);

	//cout << endl << getTotalCount();
}

void BinaryTree::postorderTravel(Node *root) {

	if (root == NULL)
		return;

	writeTree(root->left);

	writeTree(root->right);
	
	cout << "<" << root->Number << "," << root->familyCount << "> ";
}
