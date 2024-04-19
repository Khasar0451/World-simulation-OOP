#include "WilczeJagody.h"
#include "Stale.cpp"

WilczeJagody::WilczeJagody(int x, int y) {
	nazwa = "Wilcze Jagody";
	this->x = x;
	this->y = y;
	symbol = 'w';
	sila = SILA_WILCZYCH_JAGOD;
}

Organizm* WilczeJagody::stworzOrganizmWgKlasy(int x, int y) {
	return new WilczeJagody(x, y);
}

bool WilczeJagody::czyJestTrujaca() {
	return true;
}