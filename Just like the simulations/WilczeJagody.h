#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina
{
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
	bool czyJestTrujaca() override;
public:
	WilczeJagody(int x, int y);
};