#include <iostream>
#include <stdlib.h>     
#include <time.h> 
#include "Swiat.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Lis.h"
#include "Czlowiek.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "WilczeJagody.h"
using namespace std;
int main()
{
    srand(time(NULL));
    Swiat s;
    s.dodajOrganizm(new Czlowiek);
    s.dodajOrganizm(new Owca { 4,2 });
    s.dodajOrganizm(new Owca{ 3,2 });
    s.dodajOrganizm(new Wilk { 7,4 });
    s.dodajOrganizm(new Wilk{ 7, 5});
    s.dodajOrganizm(new Zolw { 4,3 });
    s.dodajOrganizm(new Zolw{ 5,5 });
    s.dodajOrganizm(new Antylopa { 6,6 });
    s.dodajOrganizm(new Antylopa{ 0,6 });
    s.dodajOrganizm(new Lis{ 2,3 });
    s.dodajOrganizm(new Lis{ 9,3 });
    s.dodajOrganizm(new Trawa { 0,3 });
    s.dodajOrganizm(new Trawa{ 7,0 });
    s.dodajOrganizm(new WilczeJagody { 1,5 });
    s.dodajOrganizm(new WilczeJagody { 4,5 });
    s.dodajOrganizm(new BarszczSosnowskiego { 2,2 });
    s.dodajOrganizm(new BarszczSosnowskiego{ 4,8 });
    s.dodajOrganizm(new BarszczSosnowskiego { 8,4 });
    s.dodajOrganizm(new Guarana{ 2,0 });
    s.dodajOrganizm(new Guarana{ 2,8 });
    s.dodajOrganizm(new Mlecz{8,8});
    s.dodajOrganizm(new Mlecz{ 5,9 });

    while (true) {
        s.petlaGry();
    }
 }


