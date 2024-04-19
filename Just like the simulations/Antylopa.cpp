#include "Antylopa.h"
#include "Stale.cpp"

Antylopa::Antylopa(int x, int y) {
	nazwa = "Antylopa";
	this->x = x;
	this->y = y;
	symbol = 'A';
	inicjatywa = INICJATYWA_ANTYLOPY;
	sila = SILA_ANTYLOPY;
	zasieg = ZASIEG_ANTYLOPY;
}

Organizm* Antylopa::stworzOrganizmWgKlasy(int x, int y) {
	return new Antylopa(x, y);
}

bool Antylopa::czyUciekaPrzedWalka(Organizm* atakujacy) {
	return rand() % 100 < ANTYLOPA_SZANSA_NA_UCIECZKE;
}
