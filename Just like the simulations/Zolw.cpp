#include "Zolw.h" 
#include "Stale.cpp"

Zolw::Zolw(int x, int y) {
	nazwa = "Zolw";
	this->x = x;
	this->y = y;
	symbol = 'Z';
	inicjatywa = INICJATYWA_ZOLWIA;
	sila = SILA_ZOLWIA;
	zasieg = DOMYSLNY_ZASIEG;
}

Organizm* Zolw::stworzOrganizmWgKlasy(int x, int y) {
	return new Zolw(x, y);
}

bool Zolw::czyOdbilAtak(Organizm* atakujacy) {
	if (atakujacy->getSila() <= ZOLW_MAKSYMALNA_ODBIJANA_SILA)
		return true;
	else
		return false;
}

bool Zolw::czyWykonaAkcje() {
	return rand() % 100 + 1 > ZOLW_SZANSA_NA_BRAK_AKCJI;
}