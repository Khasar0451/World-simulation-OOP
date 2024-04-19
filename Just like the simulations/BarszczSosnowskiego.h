#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina
{
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
	void dodatkoweAkcje(Swiat* swiat) override;
	bool czyJestTrujaca() override;
	bool dodatkoweWymaganiaWyboruKierunku(int x, int y, Swiat* swiat, bool ucieczka = false) override;
public:
	BarszczSosnowskiego(int x, int y);
};

