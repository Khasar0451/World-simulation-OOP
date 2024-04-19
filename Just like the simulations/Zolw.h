#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze
{
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	bool czyWykonaAkcje() override;
public: 
	Zolw(int x, int y);
	
};

