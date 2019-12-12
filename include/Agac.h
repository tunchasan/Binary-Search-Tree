#ifndef AGAC_H
#define AGAC_H

#include "Dugum.h"

class Agac {

public:

	//Agac Koku
	Dugum* kok = NULL;

	//Koke ait soy değeri
	int toplamSoy = 0;

public:

	//Agac sayı ekleyen fonk.
	Dugum* dugumEkle(Dugum*,int);

	//Her bir düğüm için soy sayısı bulan fonk.
	void dugumSoyBul(Dugum*);

	//Soy agacı güncelleyen fonk.
	void dugumSoyGuncelle (Dugum*);

	//Agacı yazdıran fonk.
	void agacYazdir(Dugum*);

	//En büyük ve en küçük sayısı silen fonk.
	Dugum* sayilarSil();

	//En büyük sayiyı bulan fonk.
	int buyukSayiGetir();

	//En kücük sayıyı bulan fonk.
	int kucukSayiGetir();

	//Agacı silen fonk.
	void agaciSil(Dugum*);

};

#endif
