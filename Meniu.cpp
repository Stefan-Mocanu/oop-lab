//
// Created by Stefan on 19-Apr-23.
//

#include "Meniu.h"
#include "Zboruri.h"
#include "Avioane.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("D:\\Faculatate\\Coduri\\POO\\Pr1\\tastatura.txt");
void Meniu::init(){
    Avioane *av= new Avioane[4];
    av[0].setInmatriculare("YR-MIZ");
    av[1].setInmatriculare("YR-MIR");
    av[2].setInmatriculare("YR-MIV");
    av[3].setInmatriculare("YR-MIB");

    av[0].setModel("Boeing737-300");
    av[1].setModel("Boeing737-800");
    av[2].setModel("Atr-72");
    av[3].setModel("Boeing737MAX");

    av[0].setCapacitate(4000);
    av[1].setCapacitate(5000);
    av[2].setCapacitate(1300);
    av[3].setCapacitate(5700);

    av[0].setConsum100(110);
    av[1].setConsum100(100);
    av[2].setConsum100(80);
    av[3].setConsum100(95);
    for(int i= 0;i<4;i++)Avioane::avi.push_back(av[i]);
    delete[] av;
    Zboruri *zb = new Zboruri[8];
    zb[0].setPlecare("OTP");
    zb[1].setPlecare("OTP");
    zb[2].setPlecare("BCN");
    zb[3].setPlecare("FCO");
    zb[4].setPlecare("FCO");
    zb[5].setPlecare("BCN");
    zb[6].setPlecare("JFK");
    zb[7].setPlecare("OTP");

    zb[0].setDestinatie("BCN");
    zb[1].setDestinatie("FCO");
    zb[2].setDestinatie("LTN");
    zb[3].setDestinatie("BCN");
    zb[4].setDestinatie("BGY");
    zb[5].setDestinatie("JFK");
    zb[6].setDestinatie("LAX");
    zb[7].setDestinatie("BCM");

    zb[0].setDistanta(1975);
    zb[1].setDistanta(1141);
    zb[2].setDistanta(1183);
    zb[3].setDistanta(951);
    zb[4].setDistanta(500);
    zb[5].setDistanta(6162);
    zb[6].setDistanta(3935);
    zb[7].setDistanta(250);

    for(int i=0; i<8;i++)Zboruri::zbo.push_back(zb[i]);
    delete[] zb;
}


void Meniu::adauga_avioane(){
    cout<<"Cate avioane doriti sa introduceti:\n";
    int nr;
    fin>>nr;
    if(!nr)return;
    for(int i=0;i<nr;i++){
        Avioane a;
        fin>>a;
        Avioane::avi.push_back(a);
    }
    Avioane::len_avi+=nr;
}

void Meniu::sterge_avion(){
    string a;
    bool ok=0;
    cout<<"Introdu inmatricularea avionului care trebuie sters din flota: \n";
    fin>>a;
    auto i=Avioane::avi.begin();
    for(;i<Avioane::avi.end();i++){
        if(i->getInmatriculare()==a){ok=1;break;}
    }
    if(!ok)cout<<"Nu exista acest avion"<<endl;
    else{
        Avioane::avi.erase(i);
        Avioane::len_avi--;
    }

}

void Meniu::adauga_ruta(){
    cout<<"Cate rute doriti sa introduceti:\n";
    int nr;
    fin>>nr;
    if(!nr)return;
    for(int i=0;i<nr;i++){
        Zboruri z;
        fin>>z;
        Zboruri::zbo.push_back(z);
    }
    Zboruri::len_zbo+=nr;
}
void Meniu::sterge_ruta(){
    string a,b;
    int ok=0;
    cout<<"Introdu aeroportul de plecare: \n";
    fin>>a;
    cout<<"Introdu aeroportul de destinatie: \n";
    fin>>b;
    auto i = Zboruri::zbo.begin();
    for(;i<Zboruri::zbo.end();i++){
        if(i->getPlecare()==a && i->getDestinatie()==b){ok=1;break;}
    }
    if(!ok)cout<<"Nu exista acesta ruta"<<endl;
    else{
        Zboruri::zbo.erase(i);
        Zboruri::len_zbo--;
    }
}
void Meniu::avr(){
    cout<<"Introduceti ruta pe care doriti sa o verificati\nPlecare:\n";
    string a,b;
    fin>>a;
    cout<<"Destinatie:\n";fin>>b;
    int dist =0;
    for(auto i=Zboruri::zbo.begin(); i<Zboruri::zbo.end();i++){
        if(i->getPlecare()==a && i->getDestinatie()==b){
            dist = i->getDistanta();
            break;
        }
    }
    if(dist == 0)cout<<"Nu exista aceasta ruta in structura.\n";
    else{
        bool ok=0;
        for(auto i=Avioane::avi.begin();i<Avioane::avi.end();i++){
            if(i->getCapacitate() > dist + 8*(dist/10)) {
                cout << i->getInmatriculare() << " poate zbura cu un consum de "
                     << i->getConsum100() * (dist / 100) + (i->getConsum100() *(dist%100))/100<< " litri de kerosen.\n";
                ok=1;
            }
        }
        if(!ok)cout<<"In flota nu exita niciun avion care poate circula pe aceasta ruta.";
    }
}
void Meniu::rva(){
    cout<<"Introduceti nr. de inmatriculare al avionului:\n";
    string a;
    fin>>a;
    auto index=Avioane::avi.end();
    for(auto i = Avioane::avi.begin();i<=Avioane::avi.end();i++){
        if(i->getInmatriculare()==a){index=i;break;}
    }
    if(index == Avioane::avi.end()){
        cout<<"Acest avion nu exista in flota";
        return;
    }
    bool ok=0;
    for(auto i = Zboruri::zbo.begin();i<Zboruri::zbo.end();i++){
        if(index->getCapacitate() >  i->getDistanta() + 8*(i->getDistanta()/10)) {
            cout << "Pe ruta " << i->getPlecare() << " " << i->getDestinatie()
                 << " se poate zbura cu un consum de "
                 << index->getConsum100() * (i->getDistanta() / 100) + (index->getConsum100() * i->getDistanta())/100<< " litri de kerosen.\n";
            ok = 1;
        }
    }
    if(!ok)cout<<"Avionul nu poate zbura pe nici o ruta inregistrata.";
}
void Meniu::af_avi(){
    cout<<"Inmatriculare/Model/Capacitate de zbor(km)/Consum la 100 de km\n";
    for(auto i = 0;i<Avioane::len_avi;i++)cout<<Avioane::avi[i]<<endl;
}
void Meniu::af_zbo(){
    cout<<"Plecare/Destinatie/Distanta\n";
    for(int i = 0;i<Zboruri::len_zbo;i++)cout<<Zboruri::zbo[i]<<endl;
}
void Meniu::meniu()
{
    init();
    cout<<"Meniu. \nIntroduceti in consola numarul operatiei dorite."<<endl;
    cout<<"1. Adaugati(1)/Stergeti(2) un avion."<<endl;
    cout<<"2. Adaugati(1)/Stergeti(2) o ruta."<<endl;
    cout<<"3. Afiseaza avioanele care pot circula pe o anumita ruta."<<endl;
    cout<<"4. Afiseaza rutele care pot fi circulate de un anumit avion."<<endl;
    cout<<"5. Afiseaza toate avioanele din flota."<<endl;
    cout<<"6. Afiseaza toate rutele disponibile."<<endl;
    cout<<"7. Iesire."<<endl;
    int ok = 1;
    int ciclu =0;
    while(ok) {
        int input;
        cout<< "\nIntrodu codul operatiei dorite: \n";
        fin >> input;
        switch (input) {
            case 11: {
                adauga_avioane();
                break;
            }
            case 12: {
                sterge_avion();
                break;
            }
            case 21: {
                adauga_ruta();
                break;
            }
            case 22: {
                sterge_ruta();
                break;
            }
            case 3: {
                avr();
                break;
            }
            case 4: {
                rva();
                break;
            }
            case 5:{
                af_avi();
                break;
            }
            case 6:{
                af_zbo();
                break;
            }
            case 7: {
                ok = 0;
                break;
            }
            default:
                cout << "Numarul introdus este gresit."<<endl;
        }
        if(ciclu++==2000)ok=0;
    }
}