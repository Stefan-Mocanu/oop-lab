#include <iostream>
#include <cstring>
#include <fstream>
#include "Avioane.h"
using namespace std;

ifstream fin("tastatura.txt");

class Zboruri{
    char *plecare, *destinatie;
    int distanta;
public:
    Zboruri(){
        plecare = nullptr;
        destinatie = nullptr;
        distanta =0;
    }
    Zboruri(const char *plec, const char *dest, const int dist){
        if(plec != nullptr){
            int len1 = strlen(plec) + 1;
            plecare = new char[len1];
            strcpy(plecare, plec);
        }else{
            plecare = nullptr;
        }
        if(dest != nullptr) {
            int len2 = strlen(dest) + 1;
            destinatie = new char[len2];
            strcpy(destinatie, dest);
        }else{
            destinatie = nullptr;
        }
        distanta = dist;
    }

    Zboruri(const Zboruri &zb){
        int len1 = strlen(zb.plecare) + 1;
        int len2 = strlen(zb.destinatie)  +1;

        if(plecare == nullptr)delete[] plecare;
        if(destinatie == nullptr)delete[] destinatie;

        plecare = new char[len1];
        strcpy(plecare, zb.plecare);

        destinatie = new char[len2];
        strcpy(destinatie, zb.destinatie);

        distanta = zb.distanta;
    }

    char *getPlecare()const{
        return plecare;
    }
    char *getDestinatie()const{
        return destinatie;
    }
    int getDistanta()const{
        return distanta;
    }
    void setPlecare(const char *plec){
        if(plecare != nullptr){
            delete[] plecare;
        }
        int len = strlen(plec) + 1;
        plecare = new char[len];
        strcpy(plecare, plec);
    }
    void setDestinatie(const char *dest){
        if(destinatie!=nullptr){
            delete[] destinatie;
        }
        int len = strlen(dest) + 1;
        destinatie = new char[len];
        strcpy(destinatie, dest);
    }
    void setDistanta(const int dist){
        distanta = dist;
    }
    Zboruri &operator=(const Zboruri &zb){
        setDestinatie(zb.destinatie);
        setPlecare(zb.plecare);
        distanta = zb.distanta;
        return *this;
    }

    ~Zboruri(){
        delete[] destinatie;
        delete[] plecare;
    }
    friend ostream& operator<<(ostream& os, const Zboruri &rhs);
};
bool operator==(const Zboruri &st, const Zboruri &dr){
    return strcmp(st.getDestinatie(),dr.getDestinatie())==0 && strcmp(st.getPlecare(),dr.getPlecare())==0 && st.getDistanta() == dr.getDistanta();
}
bool operator!=(const Zboruri &st, const Zboruri &dr){
    return strcmp(st.getDestinatie(),dr.getDestinatie())!=0 || strcmp(st.getPlecare(),dr.getPlecare())!=0 || st.getDistanta() != dr.getDistanta();
}
ostream& operator<<(ostream& os, const Zboruri &rhs) {
    os << rhs.plecare << ' ' << rhs.destinatie << ' ' << rhs.distanta;
    return os;
}
istream& operator>>(istream& is, Zboruri &rhs){
    char aux[255];
    cout << "Aeroport plecare: ";
    is >> aux;
    rhs.setPlecare(aux);
    cout << "Aeroport destinatie: ";
    is >> aux;
    rhs.setDestinatie(aux);
    cout << "Distanta(km): ";
    is >> aux;
    rhs.setDistanta(atoi(aux));
    return is;
}

void init(Avioane *av,Zboruri *zb){
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
}
Avioane *avi = new Avioane[4];
Zboruri *zbo = new Zboruri[8];
int len_avi = 4, len_zbo = 8;

void adauga_avioane(){
    cout<<"Cate avioane doriti sa introduceti:\n";
    int nr;
    fin>>nr;
    if(!nr)return;
    Avioane *temp = new Avioane[len_avi+nr];
    for(int i=0;i<len_avi;i++){
        temp[i] = avi[i];
    }
    for(int i=len_avi;i<len_avi+nr;i++){
        fin>>temp[i];
    }
    len_avi+=nr;
    delete[] avi;
    avi = temp;
}

void sterge_avion(){
    char a[255];
    bool ok=0;
    cout<<"Introdu inmatricularea avionului care trebuie sters din flota: \n";
    fin>>a;
    for(int i=0;i<len_avi;i++){
        if(strcmp(avi[i].getInmatriculare(),a)==0){ok=1;break;}
    }
    if(!ok)cout<<"Nu exista acest avion"<<endl;
    else{
        Avioane *aux = new Avioane[len_avi-1];
        int j=0;
        for(int i=0;i<len_avi;i++){
            if(strcmp(avi[i].getInmatriculare(),a)!=0){
                aux[j] = avi[i];
                j++;
            }
        }
        delete[] avi;
        avi = aux;
        len_avi--;

    }

}
void adauga_ruta(){
    cout<<"Cate rute doriti sa introduceti:\n";
    int nr;
    fin>>nr;
    if(!nr)return;
    Zboruri *temp = new Zboruri[len_zbo+nr];
    for(int i=0;i<len_zbo;i++){
        temp[i] = zbo[i];
    }
    for(int i=len_zbo;i<len_zbo+nr;i++){
        fin>>temp[i];
    }
    len_zbo+=nr;
    delete[] zbo;
    zbo = temp;
}
void sterge_ruta(){
    char a[255],b[255];
    int ok=0;
    cout<<"Introdu aeroportul de plecare: \n";
    fin>>a;
    cout<<"Introdu aeroportul de destinatie: \n";
    fin>>b;
    for(int i=0;i<len_zbo;i++){
        if(strcmp(zbo[i].getPlecare(),a)==0 && strcmp(zbo[i].getDestinatie(),b)==0){ok=1;break;}
    }
    if(!ok)cout<<"Nu exista acesta ruta"<<endl;
    else{
        Zboruri *aux = new Zboruri[len_zbo-1];
        int j=0;
        for(int i=0;i<len_zbo;i++){
            if(strcmp(zbo[i].getPlecare(),a)!=0 || strcmp(zbo[i].getDestinatie(),b)!=0) {
                aux[j] = zbo[i];
                j++;
            }
        }
        delete[] zbo;
        zbo = aux;
        len_zbo--;
    }
}
void avr(){
    cout<<"Introduceti ruta pe care doriti sa o verificati\nPlecare:\n";
    char a[255],b[255];
    fin>>a;
    cout<<"Destinatie:\n";fin>>b;
    int dist =0;
    for(int i=0; i<len_zbo;i++){
        if(strcmp(zbo[i].getPlecare(),a)==0 && strcmp(zbo[i].getDestinatie(),b)==0){
            dist = zbo[i].getDistanta();
            break;
        }
    }
    if(dist == 0)cout<<"Nu exista aceasta ruta in structura.\n";
    else{
        bool ok=0;
        for(int i=0;i<len_avi;i++){
            if(avi[i].getCapacitate() > dist + 8*(dist/10)) {
                cout << avi[i].getInmatriculare() << " poate zbura cu un consum de "
                     << avi[i].getConsum100() * (dist / 100) + (avi[i].getConsum100() *(dist%100))/100<< " litri de kerosen.\n";
                ok=1;
            }
        }
        if(!ok)cout<<"In flota nu exita niciun avion care poate circula pe aceasta ruta.";
    }
}
void rva(){
    cout<<"Introduceti nr. de inmatriculare al avionului:\n";
    char a[255];
    fin>>a;
    int index=-1;
    for(int i = 0;i<=len_avi;i++){
        if(strcmp(avi[i].getInmatriculare(),a)==0){index=i;break;}
    }
    if(index == -1){
        cout<<"Acest avion nu exista in flota";
        return;
    }
    bool ok=0;
    for(int i = 0;i<len_zbo;i++){
        if(avi[index].getCapacitate() >  zbo[i].getDistanta() + 8*(zbo[i].getDistanta()/10)) {
            cout << "Pe ruta " << zbo[i].getPlecare() << " " << zbo[i].getDestinatie()
                 << " se poate zbura cu un consum de "
                 << avi[index].getConsum100() * (zbo[i].getDistanta() / 100) + (avi[index].getConsum100() *zbo[i].getDistanta())/100<< " litri de kerosen.\n";
            ok = 1;
        }
    }
    if(!ok)cout<<"Avionul nu poate zbura pe nici o ruta inregistrata.";
}
void af_avi(){
    cout<<"Inmatriculare/Model/Capacitate de zbor(km)/Consum la 100 de km\n";
    for(int i = 0;i<len_avi;i++)cout<<avi[i]<<endl;
}
void af_zbo(){
    cout<<"Plecare/Destinatie/Distanta\n";
    for(int i = 0;i<len_zbo;i++)cout<<zbo[i]<<endl;
}
void meniu()
{

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

int main(){

    init(avi, zbo);
    meniu();
    delete[] avi;
    delete[] zbo;
    return 0;
}
