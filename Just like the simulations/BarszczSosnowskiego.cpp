#include "BarszczSosnowskiego.h"
#include "Stale.cpp"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y) {
	nazwa = "Barszcz Sosnowskiego";
	this->x = x;
	this->y = y;
	symbol = 'b';
	sila = SILA_BARSZCZU_SOSNOWSKIEGO;
}

bool BarszczSosnowskiego::czyJestTrujaca() {
	return true;
}

void BarszczSosnowskiego::dodatkoweAkcje(Swiat* swiat) {
	vector<int> kierunkiDoZabicia = swiat->jakieDostepneKierunki(x, y, this);
	int tempX, tempY;
	for (int kierunek : kierunkiDoZabicia) {
		swiat->kopiujKoordynaty(x, y, tempX, tempY);
		swiat->ruszWKierunku(tempX, tempY, kierunek);
		swiat->dodajKomunikat("Smiertelna aura Barszczu Sosnowskiego zabija " + swiat->nazwaIPozycja(swiat->organizmNaPolu(tempX, tempY, this)));
		swiat->zabijOrganizmNaPolu(this, tempX, tempY);
	}	
}

bool BarszczSosnowskiego::dodatkoweWymaganiaWyboruKierunku(int x, int y, Swiat* swiat, bool ucieczka) {
	if (swiat->organizmNaPolu(x, y, this) != nullptr)
		if(swiat->organizmNaPolu(x,y,this)->czyToZwierze())
			return true;
	return false;
}

Organizm* BarszczSosnowskiego::stworzOrganizmWgKlasy(int x, int y) {
	return new BarszczSosnowskiego(x, y);
}
