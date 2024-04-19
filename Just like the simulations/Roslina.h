#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
	int proby;
	void wzmocnienie(int silaWzmocnienia, int x, int y, Swiat* swiat);
	void akcja(Swiat* swiat, bool ucieczka = false) override;
//	void rozprzestrzenianie(Swiat* swiat);
	bool czyUdaSieRozprzestrzenic();
	bool czyToZwierze();
	virtual void dodatkoweAkcje(Swiat* swiat);
	virtual bool czyJestTrujaca();
	virtual bool czyWzmacnia();
public:
	Roslina();
	int kolizja(Swiat* swiat, int x, int y, bool obronca = false, Organizm* atakujacy = nullptr) override;
};