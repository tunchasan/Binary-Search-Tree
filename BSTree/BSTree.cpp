#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "BinaryTree.h"

using namespace std;

int main() {

	//Dosya okuma
	ifstream Dosya("Numbers.txt");

	//Liste oluşturduk.
	string satir = "";

	BinaryTree*tree = new BinaryTree();

	Node*root = NULL;

	if (Dosya.is_open()) { // Dosya Açıldıysa
		//Satır okundu ve string e atıldı.
		getline(Dosya, satir);
	}

	else {

		cout << "Dosya bulunamadi...." << endl << endl;
	}

	string sNumber = "";

	int Number = 0;

	//Sayılar bulunuyor.
	for (char harf : satir)
	{
		if (harf == ' ') {

			stringstream geek(sNumber);

			geek >> Number;

			root = tree->getNumber(root,Number);

			sNumber = "";
		}

		else {

			sNumber = sNumber + harf;
		}
	}

	stringstream geek(sNumber);

	geek >> Number;

	root = tree->getNumber(root, Number);

	system("pause");
}