#pragma once
#include "Zwierze.h"
#include <iostream>
using namespace std;

class Czlowiek : public Zwierze
{
	int limitCzasu;
	bool niesmiertelny = false;
	bool czyUciekaPrzedWalka(Organizm* atakujacy) override;
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
	int wybierzKierunek(int x, int y, Swiat* swiat, bool ucieczka) override;
public:
	Czlowiek();
};

