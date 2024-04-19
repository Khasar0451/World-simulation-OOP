#include "Trawa.h"
#include "Stale.cpp"

Trawa::Trawa(int x, int y) {
	nazwa = "Trawa";
	this->x = x;
	this->y = y;
	symbol = 't';
	sila = SILA_TRAWY;
}

Organizm* Trawa::stworzOrganizmWgKlasy(int x, int y) {
	return new Trawa(x, y);
}
