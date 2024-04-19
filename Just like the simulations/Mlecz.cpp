#include "Mlecz.h"
#include "Stale.cpp"

Mlecz::Mlecz(int x, int y) {
	nazwa = "Mlecz";
	this->x = x;
	this->y = y;
	symbol = 'm';
	sila = SILA_MLECZA;
	proby = ILOSC_PROB_MLECZA;
}

Organizm* Mlecz::stworzOrganizmWgKlasy(int x, int y) {
	return new Mlecz(x, y);
}