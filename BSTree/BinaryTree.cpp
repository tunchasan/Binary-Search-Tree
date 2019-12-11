/**
* @file  BSTree
* @description Kabaca 2'li arama ağaçları arasında soy ağaç sayılarına bağlı olarak ekleme , silme işlemi yapan konsol uygulaması.
* @course  2B
* @assignment  3.Ödev
* @date  10.12.2019
* @author  Ahmet Kayacı / G171210010
**/

#include "pch.h"
#include "BinaryTree.h"

int globalInt = -1;

//Agaca sayı alan ve ağaçta gerekli yere yerleştiren fonk.
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

//Her düğüme ait soy sayısını bulan ve toplam soy sayısını hesaplayan fonk.
void BinaryTree::soySayisiBul(Node *root)
{
	if (root == NULL)
		return;

	soySayisiBul(root->left);

	soySayiciGuncelle(root);

	root->familyCount = globalInt;
	//Toplam Soy Sayısı
	toplamSoy += globalInt;

	globalInt = -1;

	soySayisiBul(root->right);

}

//Her düğüme ait soy sayısını güncelleyen fonksiyon.
void BinaryTree::soySayiciGuncelle(Node *root) {

	if (root == NULL)
		return;

	soySayiciGuncelle(root->left);

	//Sayaç
	globalInt++;

	soySayiciGuncelle(root->right);
}

//toplamSay Return eden get fonksiyonu
int BinaryTree::toplamSoyAl()
{
	return toplamSoy;
}

//Agacta postOrder gezinme yapan ve agacı yazdıran fonk.
void BinaryTree::agacYazdir(Node *root)
{
	postorderGezinme(root);
}

//Her agaca ait soy sayısını sıfırlayan fonk.
void BinaryTree::soySayiSifirla() {

	toplamSoy = 0;
}

//Agacı silen fonk.
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

//En küçük ve en büyük sayıyı bulup sildik.
Node * BinaryTree::sayiSil()
{	

	//En küçük sayısı bulduk
	Node*temp = kok;

	while (temp->left->left != NULL)
		temp = temp->left;

	//Eğer en küçük sayısını alt elemanı var ise
	if (temp->left->right != NULL) {

		Node*temp2 = temp->left->right;
		//En küçük sayı silindi.
		delete(temp->left);

		temp->left = temp2;

	}

	else { 
		//En küçük sayı silindi.
		delete(temp->left);

		temp->left = NULL;
	}
	//////////////////////////////////////

	temp = kok;
	
	//En büyük sayıyı bulduk.
	while (temp->right->right != NULL)
		temp = temp->right;

	if (temp->right->left != NULL) {

		Node*temp2 = temp->right->left;
		//En büyük sayı silindi.
		delete(temp->right);

		temp->right = temp2;

	}

	else {

		//En büyük sayı silindi.
		delete(temp->right);

		temp->right = NULL;
	}

	return kok;
}

//En büyük sayıyı bulan fonk.
int BinaryTree::enBuyukSayiAl()
{
	Node*temp = kok;

	//En büyük sayı bulundu.
	while (temp->right != NULL)
		temp = temp->right;

	return temp->Number;
}

//En küçük sayıyı bulan fonk.
int BinaryTree::enKucukSayiAl()
{
	Node*temp = kok;

	while (temp->left != NULL)
		temp = temp->left;

	return temp->Number;
}

//Agacın kokunu döndüren get fonk.
Node * BinaryTree::kokuAl()
{
	return kok;
}

//Agacta postorder gezinerek elemanları yazdıran fonk.
void BinaryTree::postorderGezinme(Node *root) {

	if (root == NULL)
		return;

	agacYazdir(root->left);

	agacYazdir(root->right);
	
	cout << "<" << root->Number << "," << root->familyCount << "> ";
}
