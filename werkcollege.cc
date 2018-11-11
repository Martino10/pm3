#include "pch.h"
#include <iostream>
#include <cstdlib> //random
#include <ctime>
using namespace std;

//als er input gevraagd wordt van de gebruiker wordt het hiermee
//omgezet tot iets nuttigs
int leesGetal() {
	int vorigGetal = -1; //als het getal stopt
	int input = cin.get();
	while (input != 10) //tot enter
	{
		if (input > 47 && input < 58) { //als getal
			int inputGetal = input - '0';
			if (vorigGetal == -1) { //als er geen getal voorstond
				vorigGetal = inputGetal;
			}
			else { //als er wel een getal voorstond
				vorigGetal = vorigGetal * 10 + inputGetal;
			}
		}
		input = cin.get();
	}
	return vorigGetal; //geef getal terug
	vorigGetal = -1;
}//inputNumber

class nonogram {
public:
	//vult de nonogram willekeurig
	void vulRandom() {
		int i, n, random;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				random = rand() % 100; //getal tussen 0 en 99
				if (random < randperc) {
					nono[i][n] = 1;
				}
				else {
					nono[i][n] = 0;
				}
			}
		}
	}//vulRandom

	//maakt de nonogram leeg
	void leeg() {
		int i, n;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				nono[i][n] = 0;
			}
		}
	}//leeg

	//berekent de horizontale beschrijving
	void NieuweBeschrijvingHor() {
		//variabelen voor loop en tellen
		int i, n, count = 0;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				//zwart vlak
				if (nono[i][n] == 1) {
					count++;
					horBeschrijving[i][n] = 0;
				}
				//geen zwart vlak
				else {
					//ervoor wel zwart
					if (count > 0) {
						horBeschrijving[i][n] = count;
						count = 0;
					}
					else { //ervoor niet zwart
						horBeschrijving[i][n] = 0;
					}
				}

			}
			//laatste in de rij zwart
			if (count > 0) {
				horBeschrijving[i][n - 1] = count;
				count = 0;
			}
		}
	}

	void testBeschrijvingHor(){
		//variabelen voor loop en tellen
		int i, n, count = 0;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				//zwart vlak
				if (nono[i][n] == 1) {
					count++;
					hortest[i][n] = 0;
				}
				//geen zwart vlak
				else {
					//ervoor wel zwart
					if (count > 0) {
						hortest[i][n] = count;
						count = 0;
					}
					else { //ervoor niet zwart
						hortest[i][n] = 0;
					}
				}

			}
			//laatste in de rij zwart
			if (count > 0) {
				hortest
[i][n - 1] = count;
				count = 0;
			}
		}
	}

	void testBeschrijvingVer() {
		int i, n, count = 0;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				//zwart
				if (nono[n][i] == 1) {
					count++;
					vertest[n][i] = 0;
				}
				//niet zwart
				else {//vorige zwart
					if (count > 0) {
						vertest[n][i] = count;
						count = 0;
					}
					else { //vorige niet zwart
						vertest[n][i] = 0;
					}
				}

			}
			//laatste in rij zwart
			if (count > 0) {
				vertest[n - 1][i] = count;
				count = 0;
			}

		}
	}

	//berkent de verticale beschrijving
	void nieuweBeschrijvingVer() {
		int i, n, count = 0;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				//zwart
				if (nono[n][i] == 1) {
					count++;
					verBeschrijving[n][i] = 0;
				}
				//niet zwart
				else {//vorige zwart
					if (count > 0) {
						verBeschrijving[n][i] = count;
						count = 0;
					}
					else { //vorige niet zwart
						verBeschrijving[n][i] = 0;
					}
				}

			}
			//laatste in rij zwart
			if (count > 0) {
				verBeschrijving[n - 1][i] = count;
				count = 0;
			}

		}
	}

	//zodat er geen lege ruimtes onder staan
	void aanpassenVer() {
		int i, n, k;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				verOptimaal[i][n] = verBeschrijving[i][n];
			}
		}
		
		vercount = 0; //juiste aantal regels bij printen
		for (k = 0; k < max; k++) { //moet een paar keer gedaan worden
			for (i = 0; i < max; i++) {
				for (n = 0; n < max - 1; n++) {
					//als een locatie 0 is en het getal eronder geen nul
					//schuif dan het getal eronder naar boven
					if (verOptimaal[n][i] == 0) {
						if (verOptimaal[n + 1][i] != 0) {
							verOptimaal[n][i] = verOptimaal[n + 1][i];
							verOptimaal[n + 1][i] = 0;
						}
					}
					//in de laatste loop kijken hoe veel rijen
					if (k == (max - 1)) {
						if (verOptimaal[n][i] != 0) {
							if (n > vercount) {
								vercount = n;
							}
						}
					}
				}
			}
		}
	}

	//nieuwe beschrijving laten genereren
	void nieuweBeschrijving() {
		NieuweBeschrijvingHor();
		nieuweBeschrijvingVer();
		aanpassenVer();
	}
	void printCursor() {

	}

	//maakt alle beschrijvingen 0
	//hierdoor is de beschrijving weg
	void beschrijvingReset() {
		int i, n;
		for (i = 0; i < max; i++) {
			for (n = 0; n < max; n++) {
				verBeschrijving[i][n] = 0;
				horBeschrijving[i][n] = 0;
			}
		}
	}

	//drukt de nonogram af
	void drukAf() {
		bool goedhor = true;
		bool goedver = true;
		testBeschrijvingHor();
		testBeschrijvingVer();
		//variabelen voor de loop
		int i, n, k, m, horprintn, verprinti, verprintn;
		for (m = 0; m < max + 1; m++) {
			cout << "+++"; //bovenrand
		}
		cout << "+" << endl; //rand links
		for (i = 0; i < max; i++) {
			cout << "+ "; //rand links
			for (n = 0; n < max; n++) {
				if (nono[i][n] == 1)
					cout << " X "; //zwart
				else
					cout << "   "; //wit
			}
			cout << " + "; //rand rechts
			//horizontale beschrijving elke rij
			goedhor = true;
			for (horprintn = 0; horprintn < max; horprintn++) {
				//als er een 0 staat niet printen
				if (horBeschrijving[i][horprintn] != 0) {
					cout << horBeschrijving[i][horprintn] << " ";
					if (horBeschrijving[i][horprintn] != hortest[i][horprintn]) {
						goedhor = false;
					}
				}
			}
			if (goedhor) {
				cout << "V" << endl;
			}
			else {
				cout << endl;
			}
		}
		for (k = 0; k < max + 1; k++) {
			cout << "+++"; //onderrand
		}
		cout << "+" << endl;
		//verticale beschrijving
		cout << "  ";
		for (verprintn = 0; verprintn < max; verprintn++) {
			goedver = true;
			for (verprinti = 0; verprinti < max; verprinti++) {
				if (verBeschrijving[verprinti][verprintn] != vertest[verprinti][verprintn]) {
					goedhor = false;
				}
			}
			if (goedver) {
				cout << " V ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;

		for (verprintn = 0; verprintn < vercount +1; verprintn++) {
			cout << "  ";
			for (verprinti = 0; verprinti < max; verprinti++) {
				
				if (verOptimaal[verprintn][verprinti] != 0) {
					cout << " " << verOptimaal[verprintn][verprinti] << " ";
				}
				else {
					cout << "   ";
				}
			}
			cout << endl;
		}
	}//drukAf

	void cursorControl() {
		int i, n;
		bool again = true;
		while (again)
		{
			cout << "[w]boven, [s]beneden, [a]links, [d]rechts, [t]oggle, [q]hoofdmenu" << endl;
			char beweeg = cin.get();
			if (beweeg) {
				switch (beweeg) {
				case 'w': { 
					if (cursory > 0) {
						cursory = cursory - 1;
					} break; }
				case 's': { 
					if (cursory < max - 1) {
						cursory = cursory + 1;
					} break; }
				case 'a': { 
					if (cursorx > 0) {
						cursorx = cursorx - 1;
					} break; }
				case 'd': { 
					if (cursorx < max - 1) {
						cursorx = cursorx + 1;
					} break; }
				case 't': {
					if (nono[cursory][cursorx] == 0) {
						nono[cursory][cursorx] = 1;
					}
					else {
						nono[cursory][cursorx] = 0;
					}break; }
				case 'q': { again = false; }
				}
			}
			cursorPrint();
		}
		
	}

	//drukAf met cursor
	void cursorPrint() {
		bool goedhor = true;
		bool goedver = true;
		testBeschrijvingHor();
		testBeschrijvingVer();
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
			goedhor = true;
			for (horprintn = 0; horprintn < max; horprintn++) {
				if (horBeschrijving[i][horprintn] != 0) {
					cout << horBeschrijving[i][horprintn] << " ";
					if (horBeschrijving[i][horprintn] != hortest[i][horprintn]) {
						goedhor = false;
					}
				}
			}
			if (goedhor) {
				cout << "V" << endl;
			}
			else {
				cout << endl;
			}
		}
		for (k = 0; k < max + 1; k++) {
			cout << "+++";
		}
		cout << "+" << endl;
		//verticale beschrijving
		cout << "  ";
		for (verprintn = 0; verprintn < max; verprintn++) {
			goedver = true;
			for (verprinti = 0; verprinti < max; verprinti++) {
				if (verBeschrijving[verprinti][verprintn] != vertest[verprinti][verprintn]) {
					goedver = false;
				}
			}
			if (goedver) {
				cout << " V ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;
		for (verprintn = 0; verprintn < vercount + 1; verprintn++) {
			cout << "  ";
			for (verprinti = 0; verprinti < max; verprinti++) {

				if (verOptimaal[verprintn][verprinti] != 0) {
					cout << " " << verOptimaal[verprintn][verprinti] << " ";
				}
				else {
					cout << "   ";
				}
			}
			cout << endl;
		}
	}//drukAf
	
	//coordinaten van de cursor aan het begin
	int cursorx = (max / 2) + 1, cursory = (max / 2) + 1;
	//het randompercentage
	int randperc = 50;
	//de grote van de nonogram
	static const int max = 10;
	//de horizontale beschrijving
	int horBeschrijving[max][max];
	int hortest[max][max];
	//de verticale beschrijving
	int verOptimaal[max][max];
	int verBeschrijving[max][max];
	int vertest[max][max];
	int vercount;
	//het nonogram zelf
	bool nono[max][max];
	int hoi = 5;


};

int inlezen() //leest beschrijving in uit een file
{
	cout << "Dit leest de huidige beschrijving in uit een file" << endl;
	return 0;
}//inlezen

int wegschrijven() //schrijft huidige beschrijving weg naar een file
{
	cout << "Dit schrijft huidige beschrijving weg naar een file" << endl;
	return 0;
}//wegschrijven

int wijzigen()
{
	bool again = true;
	while (again) {
		cout << "[G]rootte   [C]ursorkleur  [P]ercentage" << endl;
		cin.get();
		char submenuinput = cin.get();
		if (submenuinput) {

			switch (submenuinput) {
			//case 'G': { grootte(); break; }
			//case 'C': { cursorkleur(); break; }
			//case 'P': { percentage(); break; }
			default: { return 0; }
			}//switch
		}//submenuinput
		cout << "Druk op ENTER om terug te gaan naar het hoofdmenu";
		cin.get(); //Als er op enter wordt gedrukt gaat hij terug naar het hoofdmenu
		cin.get();
	}
	return 0;
}//Submenu: wijzigen

int stoppen()
{
	cout << "Stopt het programma" << endl;
	return 0;
}//stoppen

//hoofdmenu

int hoofdmenu(nonogram &n)
{
	bool again = true;
	while (again) {
		cout << "s[c]hoon, c[u]rsor, [r]andom, [n]ul, [i]nlezen, w[e]gschrijven, [w]ijzigen, [q]stoppen, [b]eschrijving, [p]rinten" << endl;
		char menuinput = cin.get();
		switch (menuinput) {
		case 'c': { n.leeg(); break; }
		case 'u': { n.cursorControl(); break; }
		case 'r': { n.vulRandom(); break; }
		case 'n': { n.beschrijvingReset(); break; }
		case 'i': { inlezen(); break; }
		case 'e': { wegschrijven(); break; }
		case 'w': { wijzigen(); break; }
		case 'b': { n.nieuweBeschrijving(); break; }
		case 'p': { n.drukAf(); break; }
		case 'q': {again = false; break; }
		default: { break; }
		}//switch
		cin.get(); //Als er op enter wordt gedrukt gaat hij terug naar het hoofdmenu
	}

	//int hoofdmenu();
	//hoofdmenu();
	return 0;
}//hoofdmenu


int main()
{

	//random getallen
	srand(time(NULL));
	nonogram n;
	n.leeg();
	n.nieuweBeschrijving();
	hoofdmenu(n);
	//hoofdmenu(n);
}//main
