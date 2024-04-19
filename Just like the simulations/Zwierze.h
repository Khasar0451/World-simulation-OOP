#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
	bool dodatkoweWymaganiaWyboruKierunku(int x, int y, Swiat* swiat, bool ucieczka = false) override;
	virtual int wybierzKierunek(int x, int y, Swiat* swiat, bool ucieczka = false);
	virtual bool czyOdbilAtak(Organizm* atakujacy) override;
	virtual bool czyUnikaSilniejszych();
	bool czyToZwierze() override;
	void akcja(Swiat* swiat, bool ucieczka = false) override;
	//void rozmnazanie(Swiat* swiat);
	int kolizja(Swiat* swiat, int x, int y, bool obronca = false, Organizm* atakujacy = nullptr) override;
	int ruch(int& x, int& y, int wybranyKierunek, Swiat* swiat);
	int getZasieg();
	void ucieczka(Organizm* org, Swiat* swiat) override;
protected:
	int zasieg;
	Organizm* wybierzSlabszy(Organizm* atakowany);
	Organizm* wybierzSilniejszy(Organizm* atakowany);
public:
	Zwierze();
};