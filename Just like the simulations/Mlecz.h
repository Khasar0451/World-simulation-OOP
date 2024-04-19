#pragma once
#include "Roslina.h"

class Mlecz : public Roslina
{
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
public:
	Mlecz(int x, int y);
};

