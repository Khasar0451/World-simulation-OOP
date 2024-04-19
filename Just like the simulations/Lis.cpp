#include "Lis.h"
#include "Stale.cpp"

Lis::Lis(int x, int y) {
	nazwa = "Lis";
	this->x = x;
	this->y = y;
	symbol = 'L';
	inicjatywa = INICJATYWA_LISA;
	sila = SILA_LISA;
	zasieg = DOMYSLNY_ZASIEG;
}

Organizm* Lis::stworzOrganizmWgKlasy(int x, int y) {
	return new Lis(x, y);
}

bool Lis::czyUnikaSilniejszych() {
	return true;
}
