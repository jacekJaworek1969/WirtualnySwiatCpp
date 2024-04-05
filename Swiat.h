#pragma once
#include "Organizm.h"
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <conio.h>
struct koordynaty2 { //nie dzialalo dla zwyklych koordynatow
	int x;
	int y;
};
class Organizm;
class Swiat
{
private:
	int tura;
	int szerokosc;
	int wysokosc;
	std::vector< std::vector< Organizm* > > mapaOrganizmow;
	std::list<Organizm*> listaOrganizmow;
	std::queue<Organizm*> doUsuniecia;	
	std::queue<std::string> komunikaty;
	friend std::ostream& operator<<(std::ostream& out, const Swiat& swiat);	
public:
	
	Swiat(int szerokosc, int wysokosc);

	//gettery
	int getSzerokosc() const { return szerokosc; }
	int getWysokosc() const { return wysokosc; }
	int getTura() const { return tura; }
	const std::vector< std::vector< Organizm* > >& getMapaOrganizmow() const { return mapaOrganizmow; }
	const std::list <Organizm* >& getListaOrganizmow() const { return listaOrganizmow; };
	void ustawSwiat();
	void wykonajTure();
	Organizm* dodajOrganizm(char symbol, int x, int y);
	void dodajCzlowieka(Organizm* organizm);
	void przestawOrganizm(Organizm* organizm,int x1, int x2);
	void przegonOrganizm(Organizm* atakujacy, Organizm* broniacy);
	void tarczaPrzegon(Organizm* atakujacy, Organizm* broniacy);
	void usunOrganizm(Organizm* organizm);
	void usunOrganizmyZListy();	
	bool czyRuchMozliwy(int x, int y);
	bool czyPoleWolne(int x, int y);
	bool czySasiadujaceWolne(int x, int y);
	bool czySasiadujaceWolnePredkosc(int x, int y, int predkosc);
	void komunikat(Organizm* organizm, std::string text);
	void wyswietlKomunikaty();
	void zastapOrganizm(Organizm* atakujacy, Organizm* broniacy);
	bool jestZwierzeciem(Organizm* organizm);
	//void komunikat(Organizm* organizm, std::string text, Organizm* organizm2, std::strin text2);
	koordynaty2 znajdzWolnePole(Organizm* organizm);
	void zapiszDoPliku();
	void wczytajPlik(std::string& nazwaPliku, Organizm* czlowiek);
};
