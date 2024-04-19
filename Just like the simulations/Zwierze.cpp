#include "Stale.cpp"
#include "Zwierze.h"
#include <vector>
#include <algorithm>

Zwierze::Zwierze() {
	zasieg = DOMYSLNY_ZASIEG;
	czas = 0;
}

bool Zwierze::dodatkoweWymaganiaWyboruKierunku(int x, int y, Swiat* swiat, bool ucieczka) {
	if (ucieczka == true) {
		if (swiat->czyPoleJestPuste(x, y) == false)
			return false;
	}
	if (swiat->czyPoleJestPuste(x, y) == false && czyUnikaSilniejszych()) {
		if (wybierzSilniejszy(swiat->organizmNaPolu(x, y, this)) != this)
			return false;
	}
	return true;
}

int Zwierze::ruch(int& x, int& y, int wybranyKierunek, Swiat* swiat) {
	int status;
	swiat->ruszWKierunku(x, y, wybranyKierunek);
	if (swiat->czyPoleJestPuste(x, y) == false) {
		status = kolizja(swiat, x, y);
		if (status == BEZ_RUCHU)
			return BEZ_RUCHU;
		if (status == SMIERC) {
			return OK;
		}
	}
	return OK;
}

int Zwierze::wybierzKierunek(int x, int y, Swiat* swiat, bool ucieczka) {
	return swiat->wybierzKierunek(x, y, this, ucieczka);
}

void Zwierze::akcja(Swiat* swiat, bool ucieczka) {
	czas++;
	if (czyWykonaAkcje() == false)
		return;
	int wybranyKierunek, tempX, tempY, tempZasieg = zasieg;
	if (ucieczka == true) {
		tempZasieg = 1;
	}
	for (int i = 0; i < tempZasieg; i++)
	{
		tempX = x;
		tempY = y;
		wybranyKierunek = wybierzKierunek(x, y, swiat, ucieczka);
		
		if (wybranyKierunek == BEZ_RUCHU) {
			x = tempX;
			y = tempY;
		}
		if (ruch(x, y, wybranyKierunek, swiat) == BEZ_RUCHU) {
			x = tempX;
			y = tempY;
		}
		else
			swiat->aktualizujMape();
	}
}

void Zwierze::ucieczka(Organizm* org, Swiat* swiat) {
	akcja(swiat, true);
	swiat->dodajKomunikat(swiat->nazwaIPozycja(org) + "ucieka z pola bitwy!");
}

int Zwierze::kolizja(Swiat* swiat, int x, int y, bool obronca, Organizm* atakujacy) {
	Organizm* atakowany = swiat->organizmNaPolu(x, y, this);
	if (atakowany == nullptr)
		return BEZ_RUCHU;
	if (atakowany->getSymbol() == this->getSymbol() && obronca == false) {
		rozmnazanie(swiat);
		atakowany->setCzyMaAkcje(false);
		return BEZ_RUCHU;
	}

	Organizm* przeciwnik;
	if (atakujacy != nullptr)
		przeciwnik = atakujacy;
	else
		przeciwnik = atakowany;
	if (czyUciekaPrzedWalka(przeciwnik)) {
		ucieczka(this, swiat);
		return UCIECZKA;
	}

	if (obronca == false) {
		if (atakowany == nullptr)
			return OK;

		int status = atakowany->kolizja(swiat, x, y, true);
		if (status == UCIECZKA || status == SMIERC)
			return status;

		if (atakowany->czyOdbilAtak(this) == true) {
			swiat->dodajKomunikat(swiat->nazwaIPozycja(atakowany) + " sparowal atak zadany przez " + swiat->nazwaIPozycja(this) + "!");
			return BEZ_RUCHU;
		}
		swiat->dodajKomunikat(swiat->nazwaIPozycja(wybierzSilniejszy(atakowany)) + " skonsumowal " + swiat->nazwaIPozycja(wybierzSlabszy(atakowany)) + "!");
		swiat->usunOrganizm(wybierzSlabszy(atakowany));
	}
	return OK;
}

Organizm* Zwierze::wybierzSlabszy(Organizm* atakowany) {
	if (sila < atakowany->getSila())
		return this;
	else
		return atakowany;
}

Organizm* Zwierze::wybierzSilniejszy(Organizm* atakowany) {
	if (sila > atakowany->getSila())
		return this;
	else
		return atakowany;
}

int Zwierze::getZasieg() {
	return zasieg;
}

bool Zwierze::czyToZwierze() {
	return true;
}

bool Zwierze::czyOdbilAtak(Organizm* atakujacy) {
	return false;
}

bool Zwierze::czyUnikaSilniejszych()
{
	return false;
}