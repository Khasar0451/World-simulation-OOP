#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
public: 
	Owca(int x, int y);
};

