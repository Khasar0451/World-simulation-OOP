#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
	bool czyWzmacnia() override;
public:
	Guarana(int x, int y);
};

