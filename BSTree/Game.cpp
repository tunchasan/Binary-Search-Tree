/**
* @file  BSTree
* @description Kabaca 2'li arama aðaçlarý arasýnda soy aðaç sayýlarýna baðlý olarak ekleme , silme iþlemi yapan konsol uygulamasý.
* @course  2B
* @assignment  3.Ödev
* @date  10.12.2019
* @author  Ahmet Kayacý / G171210010
**/

#include "pch.h"
#include "Game.h"

//Kurucu Fonksiyon
Game::Game(BinaryTree *fBST, BinaryTree *sBST)
{
	ilkBST = fBST;

	ikinciBST = sBST;
}

void Game::oyunBaslat()
{
	//Tur sayýsý
	int gameCount = 0;

	while (1) {

		gameCount++;

		//Agaclara ait toplam soy sayýsýný bulduk.
		////////////////////////////////////////////////////

		ilkBST->soySayisiBul(ilkBST->kokuAl());

		int firstFC = ilkBST->toplamSoyAl();

		ikinciBST->soySayisiBul(ikinciBST->kokuAl());

		int secondFC = ikinciBST->toplamSoyAl();

		////////////////////////////////////////////////////

		cout << endl;

		cout << "Benim Agac Postorder : " << endl;

		ilkBST->agacYazdir(ilkBST->kokuAl());

		cout << endl;

		cout << "Benim Agac Toplam Soy : " << ilkBST->toplamSoyAl();

		cout << endl << "--------------------------------------------" << endl << endl;

		cout << "Rakip Agac Postorder : " << endl;

		ikinciBST->agacYazdir(ikinciBST->kokuAl());

		cout << endl;

		cout << "Rakip Agac Toplam Soy : " << ikinciBST->toplamSoyAl();

		cout << endl << endl;

		////////////////////////////////////////////////////

		//Turu 1.agac kazanýrsa
		if (firstFC < secondFC) {

			cout << "----TEBRIKLER TURU KAZANDINIZ ----" << endl << endl;

			cout << "SKOR" << endl;

			ilkSkor++;

			cout << "Benim : " << ilkSkor << endl;

			cout << "Rakip : " << ikinciSkor << endl;

			ilkBST->soySayiSifirla(); ikinciBST->soySayiSifirla();

			ilkBST->sayiAl(ilkBST->kokuAl(),ikinciBST->enBuyukSayiAl());

			ilkBST->sayiAl(ilkBST->kokuAl(), ikinciBST->enKucukSayiAl());

			ikinciBST->kok = ikinciBST->sayiSil();
		} 

		//Turu 2.agac kazanýrsa
		else if (firstFC > secondFC) {

			cout << "----TEBRIKLER TURU KAZANDINIZ ----" << endl << endl;

			cout << "SKOR" << endl;

			ikinciSkor++;

			cout << "Benim : " << ilkSkor << endl;

			cout << "Rakip : " << ikinciSkor << endl;

			ilkBST->soySayiSifirla(); ikinciBST->soySayiSifirla();

			ikinciBST->sayiAl(ikinciBST->kokuAl(), ilkBST->enBuyukSayiAl());

			ikinciBST->sayiAl(ikinciBST->kokuAl(), ilkBST->enKucukSayiAl());

			ilkBST->kok = ilkBST->sayiSil();
		}

		//Toplam soy sayýlarý eþitse kazanan yok.
		else if (ilkSkor == ikinciSkor) {

			cout << "----BU TURDA KAZANAN YOK ----" << endl << endl;

			cout << "SKOR" << endl;

			cout << "Benim : " << ilkSkor << endl;

			cout << "Rakip : " << ikinciSkor << endl;
		}

		cout << endl << gameCount << ". Oyun sona erdi." << endl;

		//Oyun Kurallarý
		////////////////////////////////////////////////////////////////////////////////

		//Ýlk aðaç 10 kez kazandýysa
		if ((ilkSkor > ikinciSkor) && ilkSkor == 10) {

			cout << endl << "----- KAZANAN Benim Agac ------" << endl << endl;

			ilkBST->agaciSil(ilkBST->kokuAl());

			ikinciBST->agaciSil(ikinciBST->kokuAl());

			break;
		}
			
		//Ýkinci aðaç 10 kez kazandýysa
		else if ((ikinciSkor > ilkSkor) && ikinciSkor == 10) {

			cout << endl << "----- KAZANAN Rakip Agac ------" << endl << endl;

			ilkBST->agaciSil(ilkBST->kokuAl());

			ikinciBST->agaciSil(ikinciBST->kokuAl());

			break;
		}

		//Tur sayýsý 100 veya 100 den fazla ise
		else if (gameCount >= 100) {

			if (ilkSkor > ikinciSkor) {

				cout << endl << "----- KAZANAN Benim Agac ------" << endl << endl;

				ilkBST->agaciSil(ilkBST->kokuAl());

				ikinciBST->agaciSil(ikinciBST->kokuAl());

				break;
			}

			else if (ikinciSkor > ilkSkor) {

				cout << endl << "----- KAZANAN Rakip Agac ------" << endl << endl;

				ilkBST->agaciSil(ilkBST->kokuAl());

				ikinciBST->agaciSil(ikinciBST->kokuAl());

				break;
			}

			else {

				cout << endl << "----- KAZANAN YOK ------" << endl << endl;

				ilkBST->agaciSil(ilkBST->kokuAl());

				ikinciBST->agaciSil(ikinciBST->kokuAl());

				break;
			}
				
		}
			
		//1.agacta hiç eleman kalmadýysa
		else if (ilkBST->kokuAl() == NULL) {

			cout << endl << "----- KAZANAN Rakip Agac ------" << endl << endl;

			//Çöp oluþumunu önlemek için ikinci aðaç silindi.
			ikinciBST->agaciSil(ikinciBST->kokuAl());

			break;
		}

		//2.agacta hiç eleman kalmadýysa
		else if (ikinciBST->kokuAl() == NULL) {

			cout << endl << "----- KAZANAN Rakip Agac ------" << endl << endl;

			//Çöp oluþumunu önlemek için ilk aðaç silindi.
			ilkBST->agaciSil(ilkBST->kokuAl());

			break;
		}

		////////////////////////////////////////////////////////////////////////////////

		system("pause");
	}
}

Game::~Game()
{

}
