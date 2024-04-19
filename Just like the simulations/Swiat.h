#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Organizm.h"
using namespace std;

class Organizm;

class Swiat {
	int szerokoscMapy, wysokoscMapy;
	vector<Organizm*> wszystkieOrganizmy;
	vector<string> komunikaty;
	char** mapa;	//bedzie malloc
	void wykonajAkcje();
	void rysujSwiat();
	void wyczyscMape();
	void ustawSymbolNaMapie(Organizm* organizm);
	void wypiszAutora();
	void wypiszKomunikaty();		
	void dodanieNowychOrganizmow();
	bool czyDostepnyKierunek(int x, int y, Organizm* organizm, bool ucieczka, bool tylkoCzyPuste = false);
	void poczatekGry();
public:
	vector<Organizm*> noweOrganizmy;
	Swiat();
	void petlaGry();
	void dodajOrganizm(Organizm* organizm);
	void usunOrganizm(Organizm* organizm);
	void zabijOrganizmNaPolu(Organizm* o, int x, int y);
	void kopiujKoordynaty(int x, int y, int& celX, int& celY);
	void dodajKomunikat(string s);
	void aktualizujMape();
	void ruszWKierunku(int& x, int& y, int kierunek);
	bool czyNaObszarzeMapy(int x, int y);
	bool czyPoleJestPuste(int x, int y);
	string nazwaIPozycja(Organizm* org);
	Organizm* organizmNaPolu(int x, int y, Organizm* org);
	vector<int> jakieDostepneKierunki(int x, int y, Organizm* organizm, bool ucieczka = false, bool tylkoCzyPuste = false);
	virtual int wybierzKierunek(int x, int y, Organizm* organizm, bool ucieczka = false, bool tylkoCzyPuste = false);
};