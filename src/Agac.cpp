#include "Agac.h"

//Global değişken
//Toplam Soy değerini tutan değişken
int toplam = -1;

//Binary Agaca sayı eklemesi yapan fonksiyon.
Dugum * Agac::dugumEkle(Dugum *dugum, int rakam)
{
	if (dugum == NULL) {

		//Yeni düğüm oluşturduk.
		dugum = new Dugum();

		//Dugumun sag ve soluna NULLL ataması yapıldı.
		dugum->dugumSag = NULL;

		dugum->dugumSol = dugum->dugumSag;
		//Dugume rakam ataması yapıldı.
		dugum->dugumSayi = rakam;
		
		//Oluşturulan dugum kok olarak atandı.
		this->kok = dugum;

		return dugum;

	}

	//Dugum rakamı gelen rakamdan küçük ise , yeni gelen rakam sağ kısma yerleştiriliyor.
	else if (dugum->dugumSayi < rakam || dugum->dugumSayi == rakam) {

		dugum->dugumSag = dugumEkle(dugum->dugumSag, rakam);

		//Oluşturulan dugum kok olarak atandı.
		kok = dugum;

		//Oluşturulan dugum return ediliyor.
		return dugum;
	}

	dugum->dugumSol = dugumEkle(dugum->dugumSol, rakam);

	//Oluşturulan dugum kok olarak atandı.
	kok = dugum;

	return dugum;
}

//Düğümlere ait soy değerlerini recursive hesaplayan fonk.
void Agac::dugumSoyBul(Dugum *dugumKok)
{
	if (dugumKok == NULL)
		return;

	dugumSoyBul(dugumKok->dugumSol);

	dugumSoyBul(dugumKok->dugumSag);

	dugumSoyGuncelle(dugumKok);

	dugumKok->dugumSoy = toplam;

	toplamSoy = toplamSoy + toplam;

	toplam = -1;

}

//Her düğüme ait soy sayısını güncelleyen fonksiyon.
void Agac::dugumSoyGuncelle(Dugum *root) {

	if (root == NULL)
		return;

	dugumSoyGuncelle(root->dugumSol);

	dugumSoyGuncelle(root->dugumSag);

	toplam++;
}

//PostOrder gezinerek ağactaki düğümleri yazdırdık.
void Agac::agacYazdir(Dugum *root)
{
	if (root == NULL)
		return;

	agacYazdir(root->dugumSol);

	agacYazdir(root->dugumSag);

	cout << "<" << root->dugumSayi << "," << root->dugumSoy << "> ";
}

//Postorder recursive olarak ağaçtaki elemanları silen fonksiyon.
void Agac::agaciSil(Dugum *root)
{
	if (root == NULL)
		return;

	agaciSil(root->dugumSol);

	agaciSil(root->dugumSag);

	delete(root);

	root = NULL;
	
}

//En küçük ve en büyük sayıyı bulup sildik.
Dugum * Agac::sayilarSil()
{	
	//Gecici Dugum
	Dugum*temp = kok;

	if (temp->dugumSol != NULL) {

		//En küçük sayı bulundu.
		while (temp->dugumSol->dugumSol != NULL)
			temp = temp->dugumSol;

		if (temp->dugumSol->dugumSag != NULL) {

			Dugum*temp2 = temp->dugumSol->dugumSag;
			//En küçük sayı silindi.
			delete(temp->dugumSol);

			temp->dugumSol = temp2;
		}

		//En küçük sayı silindi.
		else {

			delete(temp->dugumSol);

			temp->dugumSol = NULL;
		}
	}

	else
	{
		kok = temp->dugumSag;

		delete(temp);
	}
	
	
	temp = kok;

	if (temp->dugumSag != NULL) {

		//En büyük sayıyı bulduk.
		while (temp->dugumSag->dugumSag != NULL)
			temp = temp->dugumSag;

		if (temp->dugumSag->dugumSol != NULL) {

			Dugum*temp2 = temp->dugumSag->dugumSol;

			//En büyük sayı silindi.
			delete(temp->dugumSag);

			temp->dugumSag = temp2;
		}

		//En büyük sayı silindi.
		else {

			delete(temp->dugumSag);

			temp->dugumSag = NULL;
		}
	}

	else {

		kok = temp->dugumSol;

		delete(temp);
	}
	
	return kok;
}

//En büyük sayıyı bulan fonksiyon.
int Agac::buyukSayiGetir()
{
	Dugum*temp = kok;

	while (temp->dugumSag != NULL)
		temp = temp->dugumSag;
	//En büyük sayı bulundu.
	return temp->dugumSayi;
}

//En küçük sayıyı bulan fonksiyon.
int Agac::kucukSayiGetir()
{
	Dugum*temp = kok;

	while (temp->dugumSol != NULL)
		temp = temp->dugumSol;
	//En kücük sayı bulundu.
	return temp->dugumSayi;
}

