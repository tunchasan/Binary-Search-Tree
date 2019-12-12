#include <sstream>
#include <iostream>
#include <fstream>

#include "Agac.h"
#include "Oyun.h"

using namespace std;

//Global Değişkenler

Agac *benimAgac, *rakipAgac;

//Sayıları bulan ve ağaca atan fonksiyon.
void sayiBul(Agac*agac, string satir);

int sayiCevir(string);

int main() {

	//Dosya okuma
	ifstream Dosya("benim.txt");

	ifstream Dosya1("rakip.txt");

	string satir = "";

	//Benim.txt dosyasını okuduk ve satir değişkenine attık.
	if (Dosya.is_open())
		getline(Dosya, satir);

	benimAgac = new Agac();

	//benim agaca ait sayıların bulunması ve yollanması için sayıBul fonk. çağrıldı.
	sayiBul(benimAgac, satir);

	satir = "";

	//Satır okundu ve string e atıldı.
	if (Dosya1.is_open()) 
		getline(Dosya1, satir);

	rakipAgac = new Agac();

	//Rakip.txt dosyasını okuduk ve satir değişkenine attık.
	sayiBul(rakipAgac, satir);

	//Oyun nesnesine gerekli iki ağacıda parametre olarak yolladık.
	Oyun *oyun = new Oyun(benimAgac,rakipAgac);

	system("pause");
}

//String to number çevirici
int sayiCevir(string sayi) {

	int Sayi = 0;

	stringstream geek(sayi);

	geek >> Sayi;

	return Sayi;
}

//Verilen string de sayıları bulan ve Binary Tree ye , ekleme için yollayan fonksiyon.
void sayiBul(Agac *agac, string satir) {

	string sayi = "";

	//Boşluk ile ayrılan sayıları bulan döngü
	for (char ch : satir)
	{
		if (ch == ' ') {

			//Bulunan sayıyı ağaca ekliyoruz.
			agac->kok = agac->dugumEkle(agac->kok, sayiCevir(sayi));

			sayi = "";
		}

		else
			sayi = sayi + ch;
	}

	//Bulunan sayıyı ağaca ekliyoruz.
	agac->kok = agac->dugumEkle(agac->kok, sayiCevir(sayi));
}
