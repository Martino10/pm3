#include <iostream>
using namespace std;

int submenuC()
{
	return 0;
}//submenuC

int submenuR()
{
	return 0;
}//submenuR

int submenuS()
{
	return 0;
}//submenuS

int submenuP()
{
	cout << "HOi";
	return 0;
}//submenuP

int hoofdmenu()
{
	cout << "Voer een karakter in. Kies sChoon, Random, Parameters of Stoppen." << endl;
	char menuinput=cin.get();
	while(menuinput){
	
		switch(menuinput){
			case 'C': { submenuC(); break;}
			case 'R': { submenuR(); break;}
			case 'S': { submenuS(); break;}
			case 'P': { submenuP(); break;}
			default: { break; }
		}//switch
	}//menuinput
	return 0;
}//hoofdmenu

int main()
{
	hoofdmenu();
}//main
