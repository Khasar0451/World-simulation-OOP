#pragma once
#include "Swiat.h"

using namespace std;
class Swiat;

class Organizm {
	
protected:
	string nazwa;
	int sila, inicjatywa, x, y, czas;
	bool czyMaAkcje;
	char symbol;
	virtual Organizm* stworzOrganizmWgKlasy(int x, int y) = 0;
public:
	Organizm();
	virtual void akcja(Swiat* swiat, bool ucieczka = false) = 0;
	virtual void ucieczka(Organizm* org, Swiat* swiat);
	virtual int kolizja(Swiat* swiat, int x, int y, bool obronca = false, Organizm* atakujacy = nullptr) = 0;
	void rozmnazanie(Swiat* swiat);
	void setSila(int x);
	void setCzyMaAkcje(bool x);
	int getCzas();
	int getX();
	int getY();
	int getInicjatywa();
	int getSila();
	string getNazwa();
	char getSymbol();
	virtual bool czyToZwierze() = 0;
	virtual bool czyOdbilAtak(Organizm* atakujacy);
	virtual bool czyWykonaAkcje();
	virtual bool czyUciekaPrzedWalka(Organizm* atakujacy);
	virtual bool dodatkoweWymaganiaWyboruKierunku(int x, int y, Swiat* swiat, bool ucieczka = false);
}; 
