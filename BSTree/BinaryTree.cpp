/**
* @file  BSTree
* @description Kabaca 2'li arama a�a�lar� aras�nda soy a�a� say�lar�na ba�l� olarak ekleme , silme i�lemi yapan konsol uygulamas�.
* @course  2B
* @assignment  3.�dev
* @date  10.12.2019
* @author  Ahmet Kayac� / G171210010
**/

#include "pch.h"
#include "BinaryTree.h"

int globalInt = -1;

//Agaca say� alan ve a�a�ta gerekli yere yerle�tiren fonk.
Node * BinaryTree::sayiAl(Node *tree, int rakam)
{
	if (tree == NULL) {

		tree = tree->createNode(rakam, NULL, NULL);

		kok = tree;

		return tree;

	}

	else if (tree->Number < rakam || tree->Number == rakam) {

		tree->right = sayiAl(tree->right, rakam);

		kok = tree;

		return tree;
	}

	tree->left = sayiAl(tree->left, rakam);

	kok = tree;

	return tree;
}

//Her d���me ait soy say�s�n� bulan ve toplam soy say�s�n� hesaplayan fonk.
void BinaryTree::soySayisiBul(Node *root)
{
	if (root == NULL)
		return;

	soySayisiBul(root->left);

	soySayiciGuncelle(root);

	root->familyCount = globalInt;
	//Toplam Soy Say�s�
	toplamSoy += globalInt;

	globalInt = -1;

	soySayisiBul(root->right);

}

//Her d���me ait soy say�s�n� g�ncelleyen fonksiyon.
void BinaryTree::soySayiciGuncelle(Node *root) {

	if (root == NULL)
		return;

	soySayiciGuncelle(root->left);

	//Saya�
	globalInt++;

	soySayiciGuncelle(root->right);
}

//toplamSay Return eden get fonksiyonu
int BinaryTree::toplamSoyAl()
{
	return toplamSoy;
}

//Agacta postOrder gezinme yapan ve agac� yazd�ran fonk.
void BinaryTree::agacYazdir(Node *root)
{
	postorderGezinme(root);
}

//Her agaca ait soy say�s�n� s�f�rlayan fonk.
void BinaryTree::soySayiSifirla() {

	toplamSoy = 0;
}

//Agac� silen fonk.
void BinaryTree::agaciSil(Node *root)
{
	if (root == NULL)
		return;

	agaciSil(root->left);

	delete(root);

	root = NULL;

	if (root == NULL)
		return;

	agaciSil(root->right);
}

//En k���k ve en b�y�k say�y� bulup sildik.
Node * BinaryTree::sayiSil()
{	

	//En k���k say�s� bulduk
	Node*temp = kok;

	while (temp->left->left != NULL)
		temp = temp->left;

	//E�er en k���k say�s�n� alt eleman� var ise
	if (temp->left->right != NULL) {

		Node*temp2 = temp->left->right;
		//En k���k say� silindi.
		delete(temp->left);

		temp->left = temp2;

	}

	else { 
		//En k���k say� silindi.
		delete(temp->left);

		temp->left = NULL;
	}
	//////////////////////////////////////

	temp = kok;
	
	//En b�y�k say�y� bulduk.
	while (temp->right->right != NULL)
		temp = temp->right;

	if (temp->right->left != NULL) {

		Node*temp2 = temp->right->left;
		//En b�y�k say� silindi.
		delete(temp->right);

		temp->right = temp2;

	}

	else {

		//En b�y�k say� silindi.
		delete(temp->right);

		temp->right = NULL;
	}

	return kok;
}

//En b�y�k say�y� bulan fonk.
int BinaryTree::enBuyukSayiAl()
{
	Node*temp = kok;

	//En b�y�k say� bulundu.
	while (temp->right != NULL)
		temp = temp->right;

	return temp->Number;
}

//En k���k say�y� bulan fonk.
int BinaryTree::enKucukSayiAl()
{
	Node*temp = kok;

	while (temp->left != NULL)
		temp = temp->left;

	return temp->Number;
}

//Agac�n kokunu d�nd�ren get fonk.
Node * BinaryTree::kokuAl()
{
	return kok;
}

//Agacta postorder gezinerek elemanlar� yazd�ran fonk.
void BinaryTree::postorderGezinme(Node *root) {

	if (root == NULL)
		return;

	agacYazdir(root->left);

	agacYazdir(root->right);
	
	cout << "<" << root->Number << "," << root->familyCount << "> ";
}
