#include "Oyun.h"

//Global Değişkenler
int benimSkor, rakipSkor, gameCount = 0;

//Kurucu Fonksiyon
Oyun::Oyun(Agac *BT1, Agac *BT2)
{
	benimAgac = BT1;

	rakipAgac = BT2;

	//Oyun Başlatıldı.
	oyunuBaslat();
}

//Oyun Kuralları Kontrol
bool Oyun::oyunKurallari() {

	gameCount++;

	//Oyun Kuralları

	//İlk ağaç 10 kez kazandıysa
	if (benimSkor == 10 || rakipSkor == 10) {

		if (benimSkor > rakipSkor) {

			cout << endl << "----- KAZANAN Benim Agac ------" << endl << endl;

			return false;
		}

		else if (rakipSkor > benimSkor) {

			cout << endl << "----- KAZANAN Rakip Agac ------" << endl << endl;

			return false;
		}

	}

	//Tur sayısı 100 veya 100 den fazla ise
		else if (gameCount >= 100) {

			if (benimSkor > rakipSkor) {

				cout << endl << "----- KAZANAN Benim Agac ------" << endl << endl;

				return false;
			}

			else if (rakipSkor > benimSkor) {

				cout << endl << "----- KAZANAN Rakip Agac ------" << endl << endl;

				return false;
			}

			else {

				cout << endl << "----- KAZANAN YOK ------" << endl << endl;

				return false;
			}

		}

		//1.agacta hiç eleman kalmadıysa
		else if (benimAgac->kok == NULL) {

			cout << endl << "----- KAZANAN Rakip Agac ------" << endl << endl;

			return false;
		}

		//2.agacta hiç eleman kalmadıysa
		else if (rakipAgac->kok == NULL) {

			cout << endl << "----- KAZANAN Rakip Agac ------" << endl << endl;

			return false;

		}

		return true;

}

void Oyun::oyunuBaslat()
{

	do {

		//Benim Agac Soy sayısı bulundu.
		benimAgac->dugumSoyBul(benimAgac->kok);
		//Rakip Agac Soy sayısı bulundu.
		rakipAgac->dugumSoyBul(rakipAgac->kok);

		cout << endl << "Benim Agac Postorder : " << endl;
		//Benim agacı yazdırdık.
		benimAgac->agacYazdir(benimAgac->kok);
		//Toplam soy değeri yazdırıldı.
		cout << endl << "Benim Agac Toplam Soy : " << benimAgac->toplamSoy;

		cout << endl << "--------------------------------------------" << endl << endl;

		cout << "Rakip Agac Postorder : " << endl;
		//Rakip agacı yazdırdık.
		rakipAgac->agacYazdir(rakipAgac->kok);
		//Toplam soy değeri yazdırıldı.
		cout << endl <<"Rakip Agac Toplam Soy : " << rakipAgac->toplamSoy << endl << endl;

		//Benim agacın toplam soy sayısı daha az ise;
		if (benimAgac->toplamSoy < rakipAgac->toplamSoy) {

			int buyukSayi = rakipAgac->buyukSayiGetir();

			int kucukSayi = rakipAgac->kucukSayiGetir();

			cout << "----TEBRIKLER TURU KAZANDINIZ ----" << endl << endl << "SKOR"<<endl;

			benimSkor++;

			cout << "Benim : " << benimSkor << endl << "Rakip : " << rakipSkor << endl;

			benimAgac->toplamSoy = 0;

			rakipAgac->toplamSoy = benimAgac->toplamSoy;

			benimAgac->dugumEkle(benimAgac->kok, buyukSayi);

			benimAgac->dugumEkle(benimAgac->kok, kucukSayi);

			rakipAgac->kok = rakipAgac->sayilarSil();
		}

		//Rakip agacın toplam soy sayısı daha az ise;
		else if (benimAgac->toplamSoy > rakipAgac->toplamSoy) {

			int buyukSayi = benimAgac->buyukSayiGetir();

			int kucukSayi = benimAgac->kucukSayiGetir();

			cout << "----TEBRIKLER TURU KAZANDINIZ ----" << endl << endl << "SKOR" << endl;

			rakipSkor++;

			cout << "Benim : " << benimSkor << endl << "Rakip : " << rakipSkor << endl;

			benimAgac->toplamSoy = 0;

			rakipAgac->toplamSoy = 0;

			rakipAgac->dugumEkle(rakipAgac->kok, buyukSayi);

			rakipAgac->dugumEkle(rakipAgac->kok, kucukSayi);

			benimAgac->kok = benimAgac->sayilarSil();
		}

		//Soy sayıları eşitse kazanan yok.
		else if (benimAgac->toplamSoy == rakipAgac->toplamSoy) {

			cout << "----BU TURDA KAZANAN YOK ----" << endl << endl;

			cout << "SKOR" << endl;

			cout << "Benim : " << benimSkor << endl;

			cout << "Rakip : " << rakipSkor << endl;

			benimAgac->toplamSoy = 0;

			rakipAgac->toplamSoy = benimAgac->toplamSoy;
		}

		cout << endl << "***********************************************************" << endl;

		//Her tur sonunda oyun kurallarını kontrol ediyoruz.
		if (!oyunKurallari()) {

			//Agac düğümlerini sildik.
			if(benimAgac->kok != NULL)
			benimAgac->agaciSil(benimAgac->kok);

			//Agac düğümlerini sildik.
			if (rakipAgac->kok != NULL)
			rakipAgac->agaciSil(rakipAgac->kok);

			//Oyun nesnesini çöp oluşturmamak için sildik.
			delete(this);
			
			break;
		}
			
		system("pause");

	} while (true);
}