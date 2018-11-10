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
		int i, n;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				nono[i][n] = (rand() % 2);
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
		int i, n, k;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				if (nono[i][n] == 1)
					cout << " X ";
				else
					cout << "   ";
			}
			cout << " |" << endl;
		}
		for (k = 0; k < max; k++) {
			cout << "---";
		}
		cout << endl;
	}//drukAf


	static const int max = 50;
	bool nono[max][max];


};



int main()
{
	
	//random getallen
	srand(time(NULL));
	nonogram n;
	cout << leesGetal();
}//main
