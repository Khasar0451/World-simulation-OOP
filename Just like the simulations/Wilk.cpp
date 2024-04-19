#include "Wilk.h"
#include "Stale.cpp"

Wilk::Wilk(int x, int y) {
	nazwa = "Wilk";
	zasieg = DOMYSLNY_ZASIEG;	
	symbol = 'W';
	inicjatywa = INICJATYWA_WILKA;
	sila = SILA_WILKA;
	this->x = x;
	this->y = y;
}

Organizm* Wilk::stworzOrganizmWgKlasy(int x, int y) {
	return new Wilk(x, y);
}
