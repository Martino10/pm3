#include <iostream>
#include <cstdlib> //random
#include <ctime>
using namespace std;

int leesGetal() {
	int vorigGetal = -1;
	int input = cin.get();
	while (input != 10)
	{
		if (input > 47 && input < 58) {
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
		int i, n, k, m, horprintn, verprinti, verprintn;


		for (m = 0; m < max + 1; m++) {
			cout << "+++";
		}
		cout << "+" << endl;
		for (i = 0; i < max; i++) {
			cout << "+ ";
			for (n = 0; n < max; n++) {
				if (nono[i][n] == 1) {
					if (i == cursory && n == cursorx)
						cout << " * ";
					else 
						cout << " X ";
				}
				else {
					if (i == cursory && n == cursorx)
						cout << " - ";
					else
						cout << "   ";
				}
			}
			cout << " + ";
			for (horprintn = 0; horprintn < max; horprintn++) {
				if (horBeschrijving[i][horprintn] != 0) {
					cout << horBeschrijving[i][horprintn] << " ";
				}
			}
			cout << endl;
		}
		for (k = 0; k < max + 1; k++) {
			cout << "+++";
		}
		cout << "+" << endl;
		for (verprintn = 0; verprintn < max; verprintn++) {
			cout << "  ";
			for (verprinti = 0; verprinti < max; verprinti++) {

				if (verBeschrijving[verprintn][verprinti] != 0) {
					cout << " " << verBeschrijving[verprintn][verprinti] << " ";
				}
				else {
					cout << "   ";
				}
			}
			cout << endl;
		}
	}//drukAf

	void NieuweBeschrijvingHor() {

		int i, n, count = 0;
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
				horBeschrijving[i][n - 1] = count;
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
				verBeschrijving[n - 1][i] = count;
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

	void cursorControl() {
		int i, n;
		cout << "Type w om de cursor naar boven te bewegen, s voor omlaag, a voor naar links en d voor naar rechts." << endl;
			char beweeg = cin.get();
		if (beweeg) {
			switch (beweeg) {
			case 'w': { cursory = cursory - 1; break; }
			case 's': { cursory = cursory + 1; break; }
			case 'a': { cursorx = cursorx - 1; break; }
			case 'd': { cursorx = cursorx + 1; break; }
			}
		}
		drukAf();
	}

	void beschrijvingReset() {
		int i, n;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				verBeschrijving[i][n] = 0;
				horBeschrijving[i][n] = 0;
			}
		}
	}

	int cursorx = (max / 2) + 1, cursory = (max / 2) + 1;
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
	n.NieuweBeschrijvingHor();
	n.nieuweBeschrijvingVer();
	n.drukAf();
	n.cursorControl();
}//main