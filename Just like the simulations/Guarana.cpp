#include "Guarana.h"
#include "Stale.cpp"
Guarana::Guarana(int x, int y) {
	nazwa = "Guarana";
	this->x = x;
	this->y = y;
	symbol = 'g';
	sila = SILA_GUARANY;
}

Organizm* Guarana::stworzOrganizmWgKlasy(int x, int y) {
	return new Guarana(x, y);
}

bool Guarana::czyWzmacnia() {
	return true;
}