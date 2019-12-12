#ifndef DUGUM_H
#define DUGUM_H

#include <iostream>

using namespace std;

class Dugum {

private:

	friend class Agac;

	int dugumSayi,dugumSoy = -1;

	Dugum *dugumSag,*dugumSol = NULL;

public:

	//Sınıf Kurucusu
	Dugum();

	//dugumSayi get fonk.
	int dugumSayiGetir();

};

#endif