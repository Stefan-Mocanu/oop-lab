//
// Created by Stefan on 19-Apr-23.
//

#include "Meniu.h"
#include "Zboruri.h"
#include "Avioane.h"
#include <iostream>
#include <fstream>
#include <memory>
#include "input_invalid.h"
#include "nu_exista.h"
using namespace std;

ifstream fin("D:\\Faculatate\\Coduri\\POO\\Pr1\\tastatura.txt");
void Meniu::init(){
    std::unique_ptr<Avioane> av[4] = {std::make_unique<Avioane>("YR-MIZ","Boeing737-300",4000,110),
                                      std::make_unique<Avioane>("YR-MIR","Boeing737-800",5000,100),
                                      std::make_unique<Avioane>("YR-MIV","Atr-72",1300,80),
                                      std::make_unique<Avioane>("YR-MIB","Boeing737MAX",5700,95)};

    for(auto & i : av)Avioane::avi.push_back(*i);
    //delete[] av;
    std::unique_ptr<Zboruri> zb[8] = {std::make_unique<Zboruri>("OTP","BCN",1975),
                                      std::make_unique<Zboruri>("OTP","FCO",1141),
                                      std::make_unique<Zboruri>("BCN","LTN",1183),
                                      std::make_unique<Zboruri>("FCO","BCN",951),
                                      std::make_unique<Zboruri>("FCO","BGY",500),
                                      std::make_unique<Zboruri>("BCN","JFK",6162),
                                      std::make_unique<Zboruri>("JFK","LAX",3935),
                                      std::make_unique<Zboruri>("OTP","BCM",250)};
    //Zboruri *zb = new Zboruri[8];

    for(auto & i : zb)Zboruri::zbo.push_back(*i);
    //delete[] zb;
}


void Meniu::adauga_avioane(){
    cout<<"Cate avioane doriti sa introduceti:\n";
    int nr;
    fin>>nr;
    try {
        if (nr<1)throw input_invalid();
    }
    catch(const input_invalid &e){
        cout<<e.what();
        cout<<"Anulare operatie.\n";
        return;
    }
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
    try {
        if (!ok)throw input_invalid();
    }
    catch(const input_invalid &e){
        cout<<e.what();
        cout<<"Anulare operatie.\n";
        return;
    }
    Avioane::avi.erase(i);
    Avioane::len_avi--;
}

void Meniu::adauga_ruta(){
    cout<<"Cate rute doriti sa introduceti:\n";
    int nr;
    fin>>nr;
    try {
        if (nr<1)throw input_invalid();
    }
    catch(const input_invalid &e){
        cout<<e.what();
        cout<<"Anulare operatie.\n";
        return;
    }
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
    try {
        if (!ok)throw input_invalid();
    }
    catch(const input_invalid &e){
        cout<<e.what();
        cout<<"Anulare operatie.\n";
        return;
    }
    Zboruri::zbo.erase(i);
    Zboruri::len_zbo--;

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
    try {
        if (dist == 0)throw nu_exista();
    }
    catch (const nu_exista &e){
        cout<<e.what()<<"Anulare operatie.\n\n";
        return;
    }
    bool ok = false;
    for(auto i=Avioane::avi.begin();i<Avioane::avi.end();i++){
        if(i->getCapacitate() > dist + 8*(dist/10)) {
            cout << i->getInmatriculare() << " poate zbura cu un consum de "
                 << i->getConsum100() * (dist / 100) + (i->getConsum100() *(dist%100))/100<< " litri de kerosen.\n";
            ok = true;
        }
    }
    if(!ok)cout<<"In flota nu exita niciun avion care poate circula pe aceasta ruta.";

}
void Meniu::rva(){
    cout<<"Introduceti nr. de inmatriculare al avionului:\n";
    string a;
    fin>>a;
    auto index=Avioane::avi.end();
    for(auto i = Avioane::avi.begin();i<Avioane::avi.end();i++){
        if(i->getInmatriculare()==a){index=i;break;}
    }
    try {
        if (index == Avioane::avi.end())throw nu_exista();
    }
    catch (const nu_exista &e){
        cout<<e.what()<<"Anulare operatie.\n\n";
        return;
    }
    bool ok=false;
    for(auto i = Zboruri::zbo.begin();i<Zboruri::zbo.end();i++){
        if(index->getCapacitate() >  i->getDistanta() + 8*(i->getDistanta()/10)) {
            cout << "Pe ruta " << i->getPlecare() << " " << i->getDestinatie()
                 << " se poate zbura cu un consum de "
                 << index->getConsum100() * (i->getDistanta() / 100) + (index->getConsum100() * i->getDistanta())/100<< " litri de kerosen.\n";
            ok = true;
        }
    }
    if(!ok)cout<<"Avionul nu poate zbura pe nici o ruta inregistrata.";
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
        try{
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
                    Avioane::af_avi();
                    break;
                }
                case 6:{
                    Zboruri::af_zbo();
                    break;
                }
                case 7: {
                    ok = 0;
                    break;
                }
                default:
                    throw input_invalid();
            }
        }
        catch(const input_invalid &e){
            cout<<e.what();
        }
        if(ciclu++==2000)ok=0;
    }
}