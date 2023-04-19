//
// Created by Stefan on 18-Apr-23.
//

#include "Zboruri.h"
#include<iostream>
#include <cstring>
Zboruri::Zboruri(){
    plecare = nullptr;
    destinatie = nullptr;
    distanta =0;
}
Zboruri::Zboruri(const char *plec, const char *dest, const int dist){
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

Zboruri::Zboruri(const Zboruri &zb){
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

char *Zboruri::getPlecare()const{
    return plecare;
}
char *Zboruri::getDestinatie()const{
    return destinatie;
}
int Zboruri::getDistanta()const{
    return distanta;
}
void Zboruri::setPlecare(const char *plec){
    if(plecare != nullptr){
        delete[] plecare;
    }
    int len = strlen(plec) + 1;
    plecare = new char[len];
    strcpy(plecare, plec);
}
void Zboruri::setDestinatie(const char *dest){
    if(destinatie!=nullptr){
        delete[] destinatie;
    }
    int len = strlen(dest) + 1;
    destinatie = new char[len];
    strcpy(destinatie, dest);
}
void Zboruri::setDistanta(const int dist){
    distanta = dist;
}
Zboruri &Zboruri::operator=(const Zboruri &zb){
    setDestinatie(zb.destinatie);
    setPlecare(zb.plecare);
    distanta = zb.distanta;
    return *this;
}

Zboruri::~Zboruri(){
    delete[] destinatie;
    delete[] plecare;
}

bool operator==(const Zboruri &st, const Zboruri &dr){
    return strcmp(st.getDestinatie(),dr.getDestinatie())==0 && strcmp(st.getPlecare(),dr.getPlecare())==0 && st.getDistanta() == dr.getDistanta();
}
bool operator!=(const Zboruri &st, const Zboruri &dr){
    return strcmp(st.getDestinatie(),dr.getDestinatie())!=0 || strcmp(st.getPlecare(),dr.getPlecare())!=0 || st.getDistanta() != dr.getDistanta();
}
std::ostream& operator<<(std::ostream& os, const Zboruri &rhs) {
    os << rhs.plecare << ' ' << rhs.destinatie << ' ' << rhs.distanta;
    return os;
}
std::istream& operator>>(std::istream& is, Zboruri &rhs){
    char aux[255];
    std::cout << "Aeroport plecare: ";
    is >> aux;
    rhs.setPlecare(aux);
    std::cout << "Aeroport destinatie: ";
    is >> aux;
    rhs.setDestinatie(aux);
    std::cout << "Distanta(km): ";
    is >> aux;
    rhs.setDistanta(atoi(aux));
    return is;
}
