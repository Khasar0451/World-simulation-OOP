#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
	Organizm* stworzOrganizmWgKlasy(int x, int y) override;
public:
	Wilk(int x, int y);
};