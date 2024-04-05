#include "Lis.h"

Lis::Lis(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y, 'L', 3, 7) {}
void Lis::akcja()
{
	if (getWiek() == 0) {
		postarzWiek();
		return;
	}
	postarzWiek();
	kierunki kierunek = wybierzKierunekLis();
	int x1=0, y1=0;
	if (kierunek == brak) {
		swiat->komunikat(this, "nie moze sie ruszyc ");
		return;
	}
	if (kierunek == lewo) x1 = -1;
	if (kierunek == prawo)x1 = 1;
	if (kierunek == gora)y1 = -1;
	if (kierunek == dol)y1 = 1;
	if (swiat->getMapaOrganizmow()[getX() + x1][getY() + y1] == nullptr)swiat->przestawOrganizm(this, getX() + x1, getY() + y1);
	else {
		Organizm* inny = swiat->getMapaOrganizmow()[getX() + x1][getY() + y1];
		inny->kolizja(this);
	}
}
kierunki Lis::wybierzKierunekLis()
{
	kierunki kierunek = brak;
	//if (!swiat->czySasiadujaceWolne(getX(), getY()))return kierunek;
	int x1 = 0, y1 = 0, i=0;
	while (1) {
		if (i >= 50)return brak;
		int a = rand() % 4;
		if (a == 0) { x1 = 1; y1 = 0; kierunek = prawo; }
		if (a == 1) { x1 = -1; y1 = 0; kierunek = lewo; }
		if (a == 2) { x1 = 0; y1 = -1; kierunek = gora; }
		if (a == 3) { x1 = 0; y1 = 1; kierunek = dol; }
		if (swiat->czyRuchMozliwy(getX() + x1, getY() + y1)) 
		if(swiat->getMapaOrganizmow()[getX() + x1][getY() + y1]==nullptr || swiat->getMapaOrganizmow()[getX()+x1][getY()+y1]->getSila()<=getSila())break;
		i++;
	}
	return kierunek;
}
;
