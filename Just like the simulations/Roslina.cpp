#include "Roslina.h"
#include "Stale.cpp"

Roslina::Roslina() {
	proby = ILOSC_PROB_ROSLINY;
	inicjatywa = INICJATYWA_ROSLINY;
	czas = 0;
}

bool Roslina::czyUdaSieRozprzestrzenic() {
	return (rand() % 100 < SZANSA_NA_ROZPRZESTRZENIENIE);
}

void Roslina::akcja(Swiat* swiat, bool ucieczka) {
	czas++;
	for (int i = 0; i < proby; i++) {
		if(czyUdaSieRozprzestrzenic())
			rozmnazanie(swiat);
	}
	dodatkoweAkcje(swiat);
}

int Roslina::kolizja(Swiat* swiat, int x, int y, bool obronca, Organizm* atakujacy) {
	if (czyJestTrujaca()) {
		swiat->dodajKomunikat(swiat->nazwaIPozycja(swiat->organizmNaPolu(x, y, this)) + " zjada trujace " + swiat->nazwaIPozycja(this));
		swiat->zabijOrganizmNaPolu(this, x, y);	
		swiat->usunOrganizm(this);
		return SMIERC;
	}
	if (czyWzmacnia()) {
		wzmocnienie(GUARANA_WZMOCNIENIE, x, y, swiat);
	}
	swiat->usunOrganizm(this);
}

void Roslina::wzmocnienie(int silaWzmocnienia, int x, int y, Swiat* swiat) {
	Organizm* org = swiat->organizmNaPolu(x, y, this);
	org->setSila(org->getSila() + silaWzmocnienia);
}

bool Roslina::czyJestTrujaca() {
	return false;
}

void Roslina::dodatkoweAkcje(Swiat* swiat) {
	return;
}

bool Roslina::czyWzmacnia() {
	return false;
}

bool Roslina::czyToZwierze() {
	return false;
}