#include "Owca.h"
#include "Stale.cpp"

Owca::Owca(int x, int y) {
	nazwa = "Owca";
	zasieg = DOMYSLNY_ZASIEG;
	symbol = 'O';
	inicjatywa = INICJATYWA_OWCY;
	sila = SILA_OWCY;
	this->x = x;
	this->y = y;
}

Organizm* Owca::stworzOrganizmWgKlasy(int x, int y) {
	return new Owca(x, y);
}
