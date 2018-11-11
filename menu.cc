#include <iostream>
#include <cstdlib> //random
#include <ctime>
using namespace std;

int schoon() //maakt huidig beeld leeg
{
	cout << "Dit maakt het huidige beeld leeg" << endl;
	return 0;
}//schoon

int cursor() //laat de cursor bewegen
{
	cout << "Dit laat de cursor bewegen" << endl;
	return 0;
}//random

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
		cout << "Druk op ENTER om terug te gaan naar het hoofdmenu";
		return 0;
	}//grootte

	int cursorkleur()
	{
		cout << "Wijzigt de kleur van het nieuwe punt bij het verplaatsen van de cursor" << endl;
		cout << "Druk op ENTER om terug te gaan naar het hoofdmenu";
		return 0;
	}//cursorkleur

	int percentage()
	{
		cout << "Wijzigt het random percentage" << endl;
		cout << "Druk op ENTER om terug te gaan naar het hoofdmenu";
		return 0;
	}//percentage

int wijzigen()
{
	cout << "[G]rootte   [C]ursorkleur  [P]ercentage" << endl;
	cin.get();
	char submenuinput=cin.get();
	if (submenuinput) {

		switch (submenuinput) {
		case 'G': { grootte(); break; }
		case 'C': { cursorkleur(); break; }
		case 'P': { percentage(); break; }
		default: { return 0; }
		}//switch
	}//submenuinput
	cin.get(); //Als er op enter wordt gedrukt gaat hij terug naar het hoofdmenu
	cin.get();
	int hoofdmenu();
	hoofdmenu();
	return 0;
}//Submenu: wijzigen
	
int stoppen()
{
	cout << "Stopt het programma" << endl;
	return 0;
}//stoppen

int hoofdmenu()
{
	cout << "S[C]hoon  C[U]rsor  [R]andom  [T]oggle  [N]ul  [I]nlezen  W[E]gschrijven  [W]ijzigen  [S]toppen" << endl;
	char menuinput=cin.get();
	if(menuinput){
	
		switch(menuinput){
			case 'C': { schoon(); break; }
			case 'U': { cursor(); break; }
			case 'R': { random(); break; }
			case 'T': { toggle(); break; }
			case 'N': { nul(); break; }
			case 'I': { inlezen(); break; }
			case 'E': { wegschrijven(); break; }
			case 'W': { wijzigen(); break; }
			case 'S': { stoppen(); break; }
			default: { return 0; }
		}//switch
	}//menuinput
	cout << "Druk op ENTER om terug te gaan naar het hoofdmenu";
	cin.get(); //Als er op enter wordt gedrukt gaat hij terug naar het hoofdmenu
	cin.get();
	int hoofdmenu();
	hoofdmenu();
	return 0;
}//hoofdmenu

int main()
{
	hoofdmenu();	
}//main