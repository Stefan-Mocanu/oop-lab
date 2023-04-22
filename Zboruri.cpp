//
// Created by Stefan on 18-Apr-23.
//

#include "Zboruri.h"

using namespace std;
vector<Zboruri> Zboruri::zbo;
int Zboruri::len_zbo = 8;

void Zboruri::af_zbo(){
    cout<<"Plecare/Destinatie/Distanta\n";
    for(int i = 0;i<Zboruri::len_zbo;i++)cout<<Zboruri::zbo[i]<<endl;
}

Zboruri::Zboruri(){
    plecare = "";
    destinatie = "";
    distanta = 0;
}
Zboruri::Zboruri(const string plec, const string dest, const int dist){
    plecare = plec;
    destinatie = dest;
    distanta = dist;
}
Zboruri::Zboruri(const Zboruri &zbor){
   plecare = zbor.plecare;
   destinatie = zbor.destinatie;
   distanta = zbor.distanta;
}
Zboruri::~Zboruri()=default;

string Zboruri::getPlecare()const{
    return plecare;
}
string Zboruri::getDestinatie()const{
    return destinatie;
}
int Zboruri::getDistanta()const{
    return distanta;
}
void Zboruri::setPlecare(const string plec){
    plecare = plec;
}
void Zboruri::setDestinatie(const string dest){
    destinatie = dest;
}
void Zboruri::setDistanta(const int dist){
    distanta = dist;
}


bool operator==(const Zboruri &st, const Zboruri &dr){
    return st.getDestinatie()==dr.getDestinatie() && st.getPlecare()==dr.getPlecare() && st.getDistanta() == dr.getDistanta();
}
bool operator!=(const Zboruri &st, const Zboruri &dr){
    return st.getDestinatie()!=dr.getDestinatie() || st.getPlecare()!=dr.getPlecare() || st.getDistanta() != dr.getDistanta();
}
std::ostream& operator<<(std::ostream& os, const Zboruri &rhs) {
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
