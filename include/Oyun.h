#ifndef OYUN_H
#define OYUN_H

#include "Agac.h"

//Oyun sınıfı
class Oyun
{

private:

	Agac *benimAgac , *rakipAgac = NULL;

public:

	//Yapıcı Fonk.
	Oyun(Agac *, Agac *);

	//Oyun Kuralları
	bool oyunKurallari();

	//Oyunu başlatan fonksiyon
	void oyunuBaslat();

};

#endif


