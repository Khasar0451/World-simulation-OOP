#include "Organizm.h"
#include "Stale.cpp"

Organizm::Organizm() {
	czyMaAkcje = true;
	czas = 0;
}

int Organizm::getInicjatywa() {
	return inicjatywa;
}

int Organizm::getCzas() {
	return czas;
}

int Organizm::getSila() {
	return sila;
}

void Organizm::rozmnazanie(Swiat* swiat) {
	int kierunek = swiat->wybierzKierunek(x, y, this, false, true);
	int tempX, tempY;
	if (kierunek == BLAD)
		return;
	swiat->kopiujKoordynaty(x, y, tempX, tempY);
	swiat->ruszWKierunku(tempX, tempY, kierunek);
	Organizm* nowyOrganizm = stworzOrganizmWgKlasy(tempX, tempY);
	swiat->noweOrganizmy.push_back(nowyOrganizm);
	swiat->dodajKomunikat("Powstala nowa " + swiat->nazwaIPozycja(nowyOrganizm));
}

void Organizm::setSila(int x) {
	sila = x;
}

void Organizm::setCzyMaAkcje(bool x) {
	czyMaAkcje = x;
}

int Organizm::getX() {
	return x;
}

int Organizm::getY() {
	return y;
}

char Organizm::getSymbol() {
	return symbol;
}

string Organizm::getNazwa() {
	return nazwa;
}

void Organizm::ucieczka(Organizm* org, Swiat* swiat) {
	return;
}

bool Organizm::czyOdbilAtak(Organizm* atakujacy) {
	return false;
}

bool Organizm::czyWykonaAkcje() {
	return czyMaAkcje;
}

bool Organizm::czyUciekaPrzedWalka(Organizm* atakujacy) {
	return false;
}

bool Organizm::dodatkoweWymaganiaWyboruKierunku(int x, int y, Swiat* swiat, bool ucieczka) {
	return true;
}
