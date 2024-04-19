#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze
{
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
	bool czyUciekaPrzedWalka(Organizm* atakujacy) override;
public: 
	Antylopa(int x, int y);
};

