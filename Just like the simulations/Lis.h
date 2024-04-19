#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
	bool czyUnikaSilniejszych() override;
public: 
	Lis(int x, int y);
};

