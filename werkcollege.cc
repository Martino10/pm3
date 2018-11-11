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

	void leegPlek(int n, int m) {
		nono[n][m] = 0;
	}//leegPlek

	void vulPlek(int n, int m) {
		nono[n][m] = 1;
	}//vulPlek

	void test() {
		cout << hoi;
	}

	void verandertest() {
		hoi = 10;
	}
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
		vercount = 0; //juiste aantal regels bij printen
		for (k = 0; k < max; k++) { //moet een paar keer gedaan worden
			for (i = 0; i < max; i++) {
				for (n = 0; n < max - 1; n++) {
					//als een locatie 0 is en het getal eronder geen nul
					//schuif dan het getal eronder naar boven
					if (verBeschrijving[n][i] == 0) {
						if (verBeschrijving[n + 1][i] != 0) {
							verBeschrijving[n][i] = verBeschrijving[n + 1][i];
							verBeschrijving[n + 1][i] = 0;
						}
					}
					//in de laatste loop kijken hoe veel rijen
					if (k == (max - 1)) {
						if (verBeschrijving[n][i] != 0) {
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
			for (horprintn = 0; horprintn < max; horprintn++) {
				//als er een 0 staat niet printen
				if (horBeschrijving[i][horprintn] != 0) {
					cout << horBeschrijving[i][horprintn] << " ";
				}
			}
			cout << endl;
		}
		for (k = 0; k < max + 1; k++) {
			cout << "+++"; //onderrand
		}
		cout << "+" << endl;
		//verticale beschrijving
		for (verprintn = 0; verprintn < vercount; verprintn++) {
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

	//coordinaten van de cursor aan het begin
	int cursorx = (max / 2) + 1, cursory = (max / 2) + 1;
	//het randompercentage
	int randperc = 50;
	//de grote van de nonogram
	static const int max = 10;
	//de horizontale beschrijving
	int horBeschrijving[max][max];
	//de verticale beschrijving
	int verBeschrijving[max][max];
	int vercount;
	//het nonogram zelf
	bool nono[max][max];
	int hoi = 5;


};

int cursor() //laat de cursor bewegen
{
	cout << "Dit laat de cursor bewegen" << endl;
	return 0;
}//cursor

int random() //vult het huidige beeld random in mbv gegeven percentage
{
	cout << "Dit maakt het huidige beeld random met het gegeven percentage" << endl;
	return 0;
}//random

int toggle() //klapt het huidige pixel om 0>1 en 1>0
{
	cout << "Dit klapt het huidige pixel om" << endl;
	return 0;
}//toggle

int nul() //maakt alle beschrijvingen 0
{
	cout << "Dit maakt alle beschrijvingen 0" << endl;
	return 0;
}//nul

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


	//submenu van wijzigen
int grootte()
{
	cout << "Wijzigt de grootte van de puzzel" << endl;
	return 0;
}//grootte

int cursorkleur()
{
	cout << "Wijzigt de kleur van het nieuwe punt bij het verplaatsen van de cursor" << endl;
	return 0;
}//cursorkleur

int percentage()
{
	cout << "Wijzigt het random percentage" << endl;
	return 0;
}//percentage

int wijzigen()
{
	bool again = true;
	while (again) {
		cout << "[G]rootte   [C]ursorkleur  [P]ercentage" << endl;
		cin.get();
		char submenuinput = cin.get();
		if (submenuinput) {

			switch (submenuinput) {
			case 'G': { grootte(); break; }
			case 'C': { cursorkleur(); break; }
			case 'P': { percentage(); break; }
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
		cout << "S[C]hoon  C[U]rsor  [R]andom  [T]oggle  [N]ul  [I]nlezen  W[E]gschrijven  [W]ijzigen  [S]toppen [B]eschrijving [P]rinten" << endl;
		char menuinput = cin.get();
		switch (menuinput) {
		case 'C': { n.leeg(); break; }
		case 'U': { cursor(); break; }
		case 'R': { n.vulRandom(); break; }
		case 'T': { toggle(); break; }
		case 'N': { n.beschrijvingReset(); break; }
		case 'I': { inlezen(); break; }
		case 'E': { wegschrijven(); break; }
		case 'W': { wijzigen(); break; }
		case 'B': { n.nieuweBeschrijving(); break; }
		case 'P': {n.drukAf(); break; }
		case 'S': {again = false; break; }
		default: { break; }
		}//switch
		cout << "Druk op ENTER om terug te gaan naar het hoofdmenu";
		cin.get(); //Als er op enter wordt gedrukt gaat hij terug naar het hoofdmenu
		cin.get();
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
