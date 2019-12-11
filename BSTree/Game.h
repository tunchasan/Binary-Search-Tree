#ifndef GAME_H
#define GAME_H

#include "BinaryTree.h"

//Oyun sýnýfý
class Game
{

private:

	int ilkSkor = 0;

	int ikinciSkor = 0;

	BinaryTree *ilkBST;

	BinaryTree *ikinciBST;

public:

	//Yapýcý Fonk.
	Game(BinaryTree *, BinaryTree *);

	void oyunBaslat();

	~Game();
};

#endif


