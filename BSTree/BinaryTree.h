#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

class BinaryTree {

private:

	friend class Game;

	//Root of the tree.
	Node* kok = NULL;

	int toplamSoy = 0;

public:

	//Agac say� ekleyen fonk.
	Node* sayiAl(Node*,int);

	//Her bir d���m i�in soy say�s� bulan fonk.
	void soySayisiBul(Node*);

	//Postorder Agacta gezinme
	void postorderGezinme(Node*);

	//Soy agac� g�ncelleyen fonk.
	void soySayiciGuncelle (Node*);

	//toplam Soy agac�n� return eden fonk.
	int toplamSoyAl();

	//Agac� yazd�ran fonk.
	void agacYazdir(Node*);

	//En b�y�k ve en k���k say�s� silen fonk.
	Node* sayiSil();

	//En b�y�k sayiy� bulan fonk.
	int enBuyukSayiAl();
	//En k�c�k say�y� bulan fonk.
	int enKucukSayiAl();
	//Agac�n kokunu alan fonk.
	Node* kokuAl();
	//Soy say�s�n� s�f�rlayan fonk.
	void soySayiSifirla();
	//Agac� silen fonk.
	void agaciSil(Node*);

};

#endif
