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
#include "Personal.h"
#include "Personal_Navigant.h"
#include "Personal_NeNavigant.h"

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
    vector<string> avs={"Boeing737-300","Atr-72"};
    non_navigant_jobs jb[2] = {non_navigant_jobs::agent_check_in,non_navigant_jobs::tehnic};
    navigant_jobs j[3] ={navigant_jobs::pilot,navigant_jobs::copilot,navigant_jobs::insotitor_de_bord};
    std::shared_ptr<Personal> ps[15] = {std::make_shared<Personal_Navigant>("Perry","Laurie",avs,j[2]),
                                        std::make_shared<Personal_Navigant>("French","Amie",avs,j[2]),
                                        std::make_shared<Personal_Navigant>("Robles","Freya",avs,j[2]),
                                        std::make_shared<Personal_Navigant>("Beltran","Lea",avs,j[2]),
                                        std::make_shared<Personal_Navigant>("Rios","Abigail",avs,j[0]),
                                        std::make_shared<Personal_Navigant>("Sanders","James",avs,j[0]),
                                        std::make_shared<Personal_Navigant>("Watts","Gavin",avs,j[0]),
                                        std::make_shared<Personal_Navigant>("Garner","Gene",avs,j[1]),
                                        std::make_shared<Personal_Navigant>("Garza","Roger",avs,j[1]),
                                        std::make_shared<Personal_Navigant>("Ray","Hayley",avs,j[1]),
                                        std::make_shared<Personal_NeNavigant>("Bryant","Siena",jb[0],"OTP"),
                                        std::make_shared<Personal_NeNavigant>("Kamal","James",jb[0],"FCO"),
                                        std::make_shared<Personal_NeNavigant>("Lopez","Charley",jb[0],"BCN"),
                                        std::make_shared<Personal_NeNavigant>("Mason","Estelle",jb[1],"OTP"),
                                        std::make_shared<Personal_NeNavigant>("Frazier","Jeremy",jb[1],"OTP")};
    for(auto &i:ps){
        Personal::prs.push_back(i);
    }
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

void Meniu::citire_personal() {
    cout<<"Cati angajati sa se citeasca: ";
    int n;
    fin>>n;
    vector<shared_ptr<Personal>> pers;
    for(int i=0;i<n;i++){
        cout<<"\nPersonal navigant(0), nenavigant(1)";
        bool tip;
        fin>>tip;
        if(tip)pers.push_back(std::make_shared<Personal_Navigant>());
        else pers.push_back(std::make_shared<Personal_NeNavigant>());
        cout<<"Nume: ";
        string aux;
        fin>>aux;
        pers[i]->setNume(aux);
        cout<<"Prenume: ";
        fin>>aux;
        pers[i]->setPrenume(aux);
        if(pers[i]->getTipPersonal()=="Personal navigant"){
            shared_ptr<Personal_Navigant> pers1 = dynamic_pointer_cast<Personal_Navigant>(pers[i]);
            cout<<"Pe ce avioane poate zbura angajatul curent(stop pentru oprire): ";
            fin>>aux;
            vector<string> aux1;
            while(aux != "stop"){
                aux1.push_back(aux);
                fin>>aux;
            }
            pers1->adaugaTipAvioane(aux1);
            bool nok=true;
            do {
                cout << "Ce job are angajatul curent (0 insotitor de bord / 1 copilot / 2 pilot): ";
                int x;
                fin >> x;
                try{
                    switch (x) {
                        case 0: {
                            pers1->setJob(navigant_jobs::insotitor_de_bord);
                            nok = false;
                            break;
                        }
                        case 1: {
                            pers1->setJob(navigant_jobs::copilot);
                            nok = false;
                            break;
                        }
                        case 2: {
                            pers1->setJob(navigant_jobs::pilot);
                            nok = false;
                            break;
                        }
                        default: throw input_invalid();

                    }

                }
                catch(const input_invalid &e){
                    cout<<e.what()<<"Se repeta operatia.\n";
                }
            }
            while(nok);
        }
        else{
            shared_ptr<Personal_NeNavigant> pers1 = dynamic_pointer_cast<Personal_NeNavigant>(pers[i]);
            cout<<"Ce aeroport are ca baza angajatul curent: ";
            fin>>aux;
            pers1->setAeroportBaza(aux);
            int x;
            bool nok=true;
            do {
                try{
                    cout<<"Ce job are angajatul curent (0 agent check in / 1 tehnic): ";
                    fin >> x;

                    switch (x) {
                        case 0: {
                            pers1->setJob(non_navigant_jobs::agent_check_in);
                            nok=false;
                            break;
                        }
                        case 1: {
                            pers1->setJob(non_navigant_jobs::tehnic);
                            nok=false;
                            break;
                        }
                        default: throw input_invalid();

                    }

                }
                catch(const input_invalid &e){
                    cout<<e.what()<<"Se repeta operatia.\n";
                }
            }
            while(nok);
        }
    }
    Personal::adauga_ps(pers);
}
void Meniu::rvp(){
    cout<<"Introduceti aeroportul de verificat.";
    string aero;
    fin>>aero;
    bool ok = false;
    for(auto elem: Personal::prs){
        if(elem->getTipPersonal()=="Personal NeNavigant"){
            shared_ptr<Personal_NeNavigant> ang = dynamic_pointer_cast<Personal_NeNavigant>(elem);
            if(ang->getAeroportBaza()==aero){cout<<*ang<<" ";ok=true;}
        }
    }
    if(!ok)cout<<"Nu exista nici un angajat nenavigant asociat acestui aeroport.";
}
void Meniu::avp() {
    cout<<"Dati nr. de inmatriculare al avionului pe care doriti sa-l verificati: ";
    string avion;
    fin>>avion;
    bool ok1=false;
    for(auto elem:Avioane::avi)if(avion == elem.getInmatriculare()){avion = elem.getModel();ok1=true;break;}
    if(!ok1){
        try{
            throw nu_exista();
        }
        catch (nu_exista& e){
            cout<<e.what()<<"Anulare operatie\n";
        }
    }
    cout<<"Introduceti joburile pe doriti sa le verificati (0 insotitor de bord/ 1 pilot / 2 copilot / 3 oprire)";
    bool nok = true;
    vector<navigant_jobs> jbs;
    do {
        try{
            int x;
            fin >> x;
            switch (x) {
                case 0: {
                    bool ok = true;
                    for(auto elem: jbs)if(elem == navigant_jobs::insotitor_de_bord) ok =false;
                    if(ok){jbs.push_back(navigant_jobs::insotitor_de_bord); if(jbs.size()==3)nok=false; }
                    break;
                }
                case 1: {
                    bool ok = true;
                    for(auto elem: jbs)if(elem == navigant_jobs::pilot) ok =false;
                    if(ok){jbs.push_back(navigant_jobs::pilot); if(jbs.size()==3)nok=false; }
                    break;
                }
                case 2: {
                    bool ok = true;
                    for(auto elem: jbs)if(elem == navigant_jobs::copilot) ok =false;
                    if(ok){jbs.push_back(navigant_jobs::copilot); if(jbs.size()==3)nok=false; }
                    break;
                }
                case 3:{
                    nok =false;
                    break;
                }
                default: throw input_invalid();

            }

        }
        catch(const input_invalid &e){
            cout<<e.what()<<"Se repeta operatia.\n";
        }
    }
    while(nok);
    ok1 = true;
    vector<shared_ptr<Personal_Navigant>> ang;
    for(auto elem: Personal::prs){
        if(elem->getTipPersonal() == "Personal navigant"){
            auto elem2 = dynamic_pointer_cast<Personal_Navigant>(elem);
            for(auto elem1:jbs)if(elem2->getJob() == elem1){ang.push_back(elem2);ok1=false;break;}
        }
    }
    if(ok1)cout<<"Nici un angajat navigant nu poate circula pe avionul selectat.\n";
    else{
        for(auto elem: ang)cout<<*elem<<"\n";
    }
}
void Meniu::pva(){
    cout<<"Dati codul angajatului de verificat: ";
    int x;
    fin>>x;
    bool ok=false;
    auto ang = *Personal::prs.begin();
    for(auto elem = Personal::prs.begin(); elem<Personal::prs.end();elem++){
        if((*elem)->getCodAngajat() == x){ang = *elem;ok=true;break;}
    }
    if(!ok){cout<<"Nu s-a gasit nici un angajat cu codul introdus.\n";return;}
    try{
        if(ang->getTipPersonal() =="Personal navigant")throw input_invalid();
    }catch(input_invalid &e){
        cout<<e.what()<<"Anulare operatie.\n";return;
    }
    auto ang1 = dynamic_pointer_cast<Personal_NeNavigant>(ang);
    vector<Zboruri> fls;
    for(auto elem: Zboruri::zbo){
        if(ang1->getAeroportBaza() == elem.getPlecare() || ang1->getAeroportBaza() == elem.getDestinatie())
        {
            fls.push_back(elem);
        }
    }
    if(size(fls)){
        for(const auto &elem: fls)cout<<elem<<"\n";
    }
    else cout<<"Nu exista nici o ruta disponibila.";
}
void Meniu::pvr(){
    cout<<"Dati codul angajatului de verificat: ";
    int x;
    fin>>x;
    bool ok=false;
    auto ang = *Personal::prs.begin();
    for(auto elem = Personal::prs.begin(); elem<Personal::prs.end();elem++){
        if((*elem)->getCodAngajat() == x){ang = *elem;ok=true;break;}
    }
    if(!ok){cout<<"Nu s-a gasit nici un angajat cu codul introdus.\n";return;}
    try{
        if(ang->getTipPersonal() =="Personal NeNavigant")throw input_invalid();
    }catch(input_invalid &e){
        cout<<e.what()<<"Anulare operatie.\n";return;
    }
    auto ang1 = dynamic_pointer_cast<Personal_Navigant>(ang);
    vector<Avioane> avs;
    for(auto elem: Avioane::avi){
        for(auto elem1: ang1->getTipAvioane()){
            if(elem.getModel() == elem1){avs.push_back(elem);break;}
        }
    }
    if(size(avs)){
        for(const auto &elem: avs)cout<<elem<<"\n";
    }
    else cout<<"Nu exista nici un avion in flota pe care angajatul poate zbura.";
}
void Meniu::sterge_personal(){
    cout<<"Dati codul angajatului de sters: ";
    int x;
    fin>>x;
    bool ok=false;
    for(auto elem = Personal::prs.begin(); elem<Personal::prs.end();elem++){
        if((*elem)->getCodAngajat() == x){Personal::prs.erase(elem);ok=true;break;}
    }
    if(ok)cout<<"Element sters\n";
    else cout<<"Nu s-a gasit nici un angajat cu codul introdus.\n";
}
void Meniu::meniu()
{
    init();
    cout<<"Meniu. \nIntroduceti in consola numarul operatiei dorite."<<endl;
    cout<<"11/12. Adaugati(1)/Stergeti(2) un avion."<<endl;
    cout<<"21/22. Adaugati(1)/Stergeti(2) o ruta."<<endl;
    cout<<"3. Afiseaza avioanele care pot circula pe o anumita ruta."<<endl;
    cout<<"4. Afiseaza rutele care pot fi circulate de un anumit avion."<<endl;
    cout<<"5. Afiseaza toate avioanele din flota."<<endl;
    cout<<"6. Afiseaza toate rutele disponibile."<<endl;
    cout<<"7. Citeste n angajati.";
    cout<<"8. Afiseaza personalul nenavigant care are baza pe un aeroport."<<endl;
    cout<<"9. Afiseaza personalul navigant care poate circula pe un avion."<<endl;
    cout<<"10. Afiseaza rutele care au un capat care este baza unui angajat nenavigant."<<endl;
    cout<<"13. Afiseaza avioanele pe care poate circula un angajat navigant."<<endl;
    cout<<"14. Afiseaza toti angajatii."<<endl;
    cout<<"15. Sterge un angajat."<<endl;
    cout<<"16. Iesire."<<endl;
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
                    citire_personal();
                    break;
                }
                case 8: {
                    rvp();
                    break;
                }
                case 9: {
                    avp();
                    break;
                }
                case 10: {
                    pvr();
                    break;
                }
                case 13: {
                    pva();
                    break;
                }
                case 14: {
                    Personal::afiseaza_ps();
                    break;
                }
                case 15: {
                    sterge_personal();
                    break;
                }
                case 16: {
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