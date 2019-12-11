/**       
* @file  BSTree
* @description Kabaca 2'li arama ağaçları arasında soy ağaç sayılarına bağlı olarak ekleme , silme işlemi yapan konsol uygulaması.
* @course  2B
* @assignment  3.Ödev
* @date  10.12.2019
* @author  Ahmet Kayacı / G171210010
**/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "BinaryTree.h"
#include "Game.h"

using namespace std;

//Verilen string de sayıları bulan ve Binary Tree ye , ekleme için yollayan fonksiyon.
Node* findNumbers(Node*root , string line , BinaryTree *tree) {

	string sNumber = "";

	int Number = 0;

	//Sayılar bulunuyor.
	for (char harf : line)
	{
		if (harf == ' ') {

			stringstream geek(sNumber);

			geek >> Number;

			//Tree sınıfınında getNumber fonksiyonu ile sayıyı yolladık.
			root = tree->sayiAl(root, Number);

			sNumber = "";
		}

		else {

			sNumber = sNumber + harf;
		}
	}

	stringstream geek(sNumber);

	geek >> Number;

	//Tree sınıfınında getNumber fonksiyonu ile sayıyı yolladık.
	root = tree->sayiAl(root, Number);

	return root;
}

int main() {

	//Dosya okuma
	ifstream Dosya("benim.txt");

	//Liste oluşturduk.
	string satir = "";

	BinaryTree*ilkAgac = new BinaryTree();

	Node*ilkKok = NULL;

	BinaryTree*ikinciAgac = new BinaryTree();

	Node*ikinciKok = NULL;

	//Benim.txt dosyasını okuduk ve satir değişkenine attık.

	if (Dosya.is_open()) { // Dosya Açıldıysa
		//Satır okundu ve string e atıldı.
		getline(Dosya, satir);
	}

	else {

		cout << "Dosya bulunamadi...." << endl << endl;
	}

	ilkKok = findNumbers(ilkKok, satir, ilkAgac);

	//////////////////////////////////////////////////////////
	/////////////DOSYA OKUMA for Second Tree//////////////////

	//Dosya okuma
	ifstream Dosya1("rakip.txt");

	//Liste oluşturduk.
	satir = "";

	if (Dosya1.is_open()) { // Dosya Açıldıysa
		//Satır okundu ve string e atıldı.
		getline(Dosya1, satir);
	}

	else {

		cout << "Dosya bulunamadi...." << endl << endl;
	}

	ikinciKok = findNumbers(ikinciKok, satir, ikinciAgac);

	//Oyun nesnesi oluşturduk.
	Game *oyun = new Game(ilkAgac,ikinciAgac);

	//Oyunu Başlat
	oyun->oyunBaslat();

	//Oyun nesnesini çöp oluşturmamak için sildik.
	delete(oyun);

	system("pause");
}