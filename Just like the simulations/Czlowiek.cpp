#include "Czlowiek.h"
#include "Stale.cpp"
#include <conio.h>

Czlowiek::Czlowiek() {
	nazwa = "Czlowiek";
	x = CZLOWIEK_PUNKT_STARTOWY;
	y = CZLOWIEK_PUNKT_STARTOWY;
	symbol = 'C';
	inicjatywa = INICJATYWA_CZLOWIEKA;
	sila = SILA_CZLOWIEKA;
	zasieg = DOMYSLNY_ZASIEG;
}

bool Czlowiek::czyUciekaPrzedWalka(Organizm* atakujacy) {
	if (wybierzSilniejszy(atakujacy) != this)
		return niesmiertelny;
	return false;
}

int Czlowiek::wybierzKierunek(int x, int y, Swiat* swiat, bool ucieczka) {
	while (true)
	{		
		int command = 0;
		while (command == 0 || command == 0xE0) {
			command = _getch();
		}
		if (czas >= limitCzasu + LIMIT_TUR_NIESMIERTELNOSCI) {
			niesmiertelny = false;
		}
		switch (command) {
		case STRZALKA_GORA:
			return POLNOC;
		case STRZALKA_DOL:
			return POLUDNIE;
		case STRZALKA_LEWO:
			return ZACHOD;
		case STRZALKA_PRAWO:
			return WSCHOD;
		case 'p':
			cout << "NIESMIERTELNOSC" << endl;
			niesmiertelny = true;
			limitCzasu = czas;
			break;
		}
	}
}

Organizm* Czlowiek::stworzOrganizmWgKlasy(int x, int y) {
	return nullptr;
}
