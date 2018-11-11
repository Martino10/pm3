#include "pch.h"
#include <iostream>
#include <cstdlib> //random
#include <ctime>
using namespace std;

int leesGetal() {
	int vorigGetal = -1;
	int input = cin.get();
	while (input != 10)
	{
		if (input > 47  && input < 58) {
			int inputGetal = input - '0';
			if (vorigGetal == -1) {
				vorigGetal = inputGetal;
			}
			else {
				vorigGetal = vorigGetal * 10 + inputGetal;
			}
		}
		input = cin.get();
	}
	return vorigGetal;
	vorigGetal = -1;
}//inputNumber

class nonogram {
public:
	void vulRandom() {
		int i, n, random;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				random = rand() % 100;
				if (random <= randperc) {
					nono[i][n] = 1;
				}
				else {
					nono[i][n] = 0;
				}
			}
		}
	}//vulRandom

	void leeg() {
		int i, n;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				nono[i][n] = 0;
			}
		}
	}//leeg

	void leegPlek(int n, int m) {
		nono[n][m] = 0;
	}//leegPlek

	void vulPlek(int n, int m) {
		nono[n][m] = 1;
	}//vulPlek

	void drukAf() {
		int i, n, k, m;
		for (m = 0; m < max +1; m++) {
			cout << "+++";
		}
		cout << "+" << endl;
		for (i = 0; i < max; i++) {
			cout << "+ ";
			for (n = 0; n < max; n++) {
				if (nono[i][n] == 1)
					cout << " X ";
				else
					cout << "   ";
			}
			cout << " +" << endl;
		}
		for (k = 0; k < max +1; k++) {
			cout << "+++";
		}
		cout << "+" << endl;
	}//drukAf

	void NieuweBeschrijvingHor() {

		int i, n, count=0;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				if (nono[i][n] == 1) {
					count++;
					horBeschrijving[i][n] = 0;
				}
				else {
					if (count > 0) {
						horBeschrijving[i][n] = count;
						count = 0;
					}
					else {
						horBeschrijving[i][n] = 0;
					}
				}

			}
			if (count > 0) {
				horBeschrijving[i][n-1] = count;
				count = 0;
			}
		
		}
	}
	
	void printBeschrijvingHor() {
		int i, n;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				if (horBeschrijving[i][n] != 0) {
					cout << horBeschrijving[i][n] << " ";
				}
			}
			cout << endl;
		}
	}

	void nieuweBeschrijvingVer() {
		int i, n, count = 0;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				if (nono[n][i] == 1) {
					count++;
					verBeschrijving[n][i] = 0;
				}
				else {
					if (count > 0) {
						verBeschrijving[n][i] = count;
						count = 0;
					}
					else {
						verBeschrijving[n][i] = 0;
					}
				}

			}
			if (count > 0) {
				verBeschrijving[n-1][i] = count;
				count = 0;
			}

		}
	}

	void printBeschrijvingVer() {
		int i, n;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				if (verBeschrijving[n][i] != 0) {
					cout << verBeschrijving[n][i] << " ";
				}
			}
			cout << endl;
		}
	}

	int randperc = 50;
	static const int max = 10;
	int horBeschrijving[max][max];
	int verBeschrijving[max][max];
	bool nono[max][max];


};

int main()
{
	
	//random getallen
	srand(time(NULL));
	nonogram n;
	n.vulRandom();
	n.drukAf();
	n.NieuweBeschrijvingHor();
	n.printBeschrijvingHor();
	cout << endl;
	n.nieuweBeschrijvingVer();
	n.printBeschrijvingVer();
}//main
