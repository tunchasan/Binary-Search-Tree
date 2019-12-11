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

	//Agac sayý ekleyen fonk.
	Node* sayiAl(Node*,int);

	//Her bir düðüm için soy sayýsý bulan fonk.
	void soySayisiBul(Node*);

	//Postorder Agacta gezinme
	void postorderGezinme(Node*);

	//Soy agacý güncelleyen fonk.
	void soySayiciGuncelle (Node*);

	//toplam Soy agacýný return eden fonk.
	int toplamSoyAl();

	//Agacý yazdýran fonk.
	void agacYazdir(Node*);

	//En büyük ve en küçük sayýsý silen fonk.
	Node* sayiSil();

	//En büyük sayiyý bulan fonk.
	int enBuyukSayiAl();
	//En kücük sayýyý bulan fonk.
	int enKucukSayiAl();
	//Agacýn kokunu alan fonk.
	Node* kokuAl();
	//Soy sayýsýný sýfýrlayan fonk.
	void soySayiSifirla();
	//Agacý silen fonk.
	void agaciSil(Node*);

};

#endif
