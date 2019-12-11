#ifndef GAME_H
#define GAME_H

#include "BinaryTree.h"

//Oyun s�n�f�
class Game
{

private:

	int ilkSkor = 0;

	int ikinciSkor = 0;

	BinaryTree *ilkBST;

	BinaryTree *ikinciBST;

public:

	//Yap�c� Fonk.
	Game(BinaryTree *, BinaryTree *);

	void oyunBaslat();

	~Game();
};

#endif


