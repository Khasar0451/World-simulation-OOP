#pragma once
#include "Roslina.h"

class Trawa : public Roslina
{
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
public:
	Trawa(int x, int y);
};

