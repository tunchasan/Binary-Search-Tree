#include <iostream>
#include <fstream>
#include <string>
#include <Node.h>

using namespace std;

int main() {

    //Dosya okuma
	ifstream Dosya("Numbers.txt");
	Node*node = new Node();
    //Liste oluşturduk.
	string satir = "";

	if (Dosya.is_open()) { // Dosya Açıldıysa
		//Satır okundu ve string e atıldı.
		getline(Dosya, satir);
	}
    
	else {

		cout << "Dosya bulunamadi...." << endl << endl;
	}

    string rakam = "";

    //Sayılar bulunuyor.
	for (char harf : satir)
	{
		if (harf == ' ') {

			//cout <<rakam << endl;

			node->createNode((int)harf,NULL,NULL);

			cout << node->Number << endl;

			rakam = "";
		}

		else {
			
			rakam = rakam + harf;
		}
	}

			node->createNode((int)harf,NULL,NULL);

			cout << node->Number << endl;

    system ("pause");
}