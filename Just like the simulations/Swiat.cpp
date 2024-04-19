#include "Swiat.h"
#include "Stale.cpp"
#include <algorithm>
#include <conio.h>
Swiat::Swiat() {
	cout << "Podaj wymiary mapy (x y): ";
	cin >> szerokoscMapy >> wysokoscMapy;
	mapa = new char* [wysokoscMapy];
	for (int i = 0; i < wysokoscMapy; ++i)
		mapa[i] = new char[szerokoscMapy];
	wyczyscMape();
}

bool Swiat::czyNaObszarzeMapy(int x, int y) {
	if (x < 0 || x >= szerokoscMapy || y < 0 || y >= wysokoscMapy)
		return false;
	else
		return true;
}

bool Swiat::czyPoleJestPuste(int x, int y) {
	if (mapa[y][x] == ' ')
		return true;
	else
		return false;
}

void Swiat::ustawSymbolNaMapie(Organizm* organizm) {
	mapa[organizm->getY()][organizm->getX()] = organizm->getSymbol();
}

void Swiat::wyczyscMape() {
	for (size_t i = 0; i < wysokoscMapy; i++)
	{
		for (size_t j = 0; j < szerokoscMapy; j++)
		{
			mapa[i][j] = ' ';
		}
	}
}

void Swiat::petlaGry() {
	rysujSwiat();
	wykonajAkcje();
	dodanieNowychOrganizmow();
	aktualizujMape();
	system("cls");
}

void Swiat::wykonajAkcje() {
	for (Organizm* organizm : wszystkieOrganizmy) {
		organizm->akcja(this);
		ustawSymbolNaMapie(organizm);
	}
}

void Swiat::aktualizujMape() {
	wyczyscMape();
	for (Organizm* organizm : wszystkieOrganizmy) {
		ustawSymbolNaMapie(organizm);
		organizm->setCzyMaAkcje(true);
	}
}

void Swiat::wypiszAutora() {
	cout << "Lukasz Surma	188725\n\n";
}

void Swiat::dodajKomunikat(string s) {
	komunikaty.push_back(s);
}

void Swiat::wypiszKomunikaty() {
	for (string s : komunikaty) {
		cout << s << endl;
	}
	komunikaty.clear();
}

string Swiat::nazwaIPozycja(Organizm* org) {
	return org->getNazwa() + " (" + to_string(org->getX()) + ", " + to_string(org->getY()) + ")";
}

void Swiat::rysujSwiat() {
	wypiszAutora();
	for (size_t i = 0; i < wysokoscMapy; i++) {
		for (size_t j = 0; j < szerokoscMapy; j++) {
			cout << mapa[i][j];
		}
		cout << endl;
	}
	wypiszKomunikaty();
}

void Swiat::dodanieNowychOrganizmow() {
	for (Organizm* o : noweOrganizmy) {
		dodajOrganizm(o);
	}
	noweOrganizmy.clear();
}

void Swiat::dodajOrganizm(Organizm* organizm) {
	wszystkieOrganizmy.push_back(organizm);
	sort(wszystkieOrganizmy.begin(), wszystkieOrganizmy.end(), 
		[](Organizm* const& a, Organizm* const& b) {	
			if (a->getInicjatywa() == b->getInicjatywa())
				return a->getCzas() > b->getCzas();
			else
				return a->getInicjatywa() > b->getInicjatywa();  });
	ustawSymbolNaMapie(organizm);
}

void Swiat::usunOrganizm(Organizm* organizm) {
	for (Organizm* org : wszystkieOrganizmy) {
		if (org == organizm) {
			wszystkieOrganizmy.erase(remove(wszystkieOrganizmy.begin(), wszystkieOrganizmy.end(), organizm));
			return;
		}
	}
}

void Swiat::zabijOrganizmNaPolu(Organizm* nieTenOrganizm, int x, int y) {
	usunOrganizm(organizmNaPolu(x, y, nieTenOrganizm));
}

Organizm* Swiat::organizmNaPolu(int x, int y, Organizm* nieTenOrganizm) {
	for (Organizm* organizm : wszystkieOrganizmy) {
		if (organizm->getX() == x && organizm->getY() == y && organizm != nieTenOrganizm)
			return organizm;
	}
	return nullptr;
}

void Swiat::kopiujKoordynaty(int x, int y, int& celX, int& celY) {
	celX = x;
	celY = y;
}

void Swiat::ruszWKierunku(int& x, int& y, int kierunek) {
	switch (kierunek)
	{
	case POLNOC:
		y -= 1;
		break;
	case WSCHOD:
		x += 1;
		break;
	case POLUDNIE:
		y += 1;
		break;
	case ZACHOD:
		x -= 1;
		break;
	}
}

vector<int> Swiat::jakieDostepneKierunki(int x, int y, Organizm* organizm, bool ucieczka, bool tylkoCzyPuste) {
	vector<int> v;
	if (czyDostepnyKierunek(x, y - 1, organizm, ucieczka, tylkoCzyPuste) == true)
		v.push_back(POLNOC);
	if (czyDostepnyKierunek(x + 1, y, organizm, ucieczka, tylkoCzyPuste) == true)
		v.push_back(WSCHOD);
	if (czyDostepnyKierunek(x, y + 1, organizm, ucieczka, tylkoCzyPuste) == true)
		v.push_back(POLUDNIE);
	if (czyDostepnyKierunek(x - 1, y, organizm, ucieczka, tylkoCzyPuste) == true)
		v.push_back(ZACHOD);
	return v;
}

bool Swiat::czyDostepnyKierunek(int x, int y, Organizm* organizm, bool ucieczka, bool tylkoCzyPuste) {
	if (czyNaObszarzeMapy(x, y) == true) {
		if (tylkoCzyPuste == true)
			return czyPoleJestPuste(x, y);
		if (organizm->dodatkoweWymaganiaWyboruKierunku(x,y,this))
			return true;
	}
}

int Swiat::wybierzKierunek(int x, int y, Organizm* organizm, bool ucieczka, bool tylkoCzyPuste) {
	int ilosc;
	vector<int> dostepneKierunki = jakieDostepneKierunki(x, y, organizm, ucieczka, tylkoCzyPuste);
	ilosc = dostepneKierunki.size();
	if (ilosc == 0)
		return BLAD;
	return dostepneKierunki[rand() % ilosc];
}