//
// Created by Stefan on 18-Apr-23.
//

#include "Avioane.h"
#include <iostream>
#include <string>

using namespace std;

vector<Avioane> Avioane::avi;
int Avioane::len_avi = 4;

void Avioane::af_avi(){
    cout<<"Inmatriculare/Model/Capacitate de zbor(km)/Consum la 100 de km\n";
    for(auto i = 0;i<Avioane::len_avi;i++)cout<<Avioane::avi[i]<<endl;
}
Avioane::Avioane(){
    inmatriculare = "";
    model = "";
    capacitate_zbor = 0;
    consum100 = 0;
}
Avioane::Avioane(const string n,const  string m,const  int cap,const  int comb) {
    inmatriculare = n;
    model = m;
    capacitate_zbor = cap;
    consum100 = comb;
}
Avioane::Avioane(const Avioane &av){
    inmatriculare = av.inmatriculare;
    model = av.model;
    capacitate_zbor = av.capacitate_zbor;
    consum100 = av.consum100;
}
string Avioane::getInmatriculare() const{
    return inmatriculare;
}
string Avioane::getModel() const{
    return model;
}
int Avioane::getCapacitate() const{
    return capacitate_zbor;
}
int Avioane::getConsum100() const{
    return consum100;
}
void Avioane::setInmatriculare(const string new_inmatric){
    inmatriculare = new_inmatric;
}
void Avioane::setModel(const string new_model){
    model = new_model;
}
void Avioane::setCapacitate(const int i){
    capacitate_zbor = i;
}
void Avioane::setConsum100(const int i){
    consum100 = i;
}
Avioane &Avioane::operator=(const Avioane &av){
    setInmatriculare(av.inmatriculare);
    setModel(av.model);
    capacitate_zbor = av.capacitate_zbor;
    consum100 = av.consum100;
    return *this;
}

bool operator==(const Avioane &lhs, const Avioane &rhs){
    return lhs.getModel()==rhs.getModel() && lhs.getCapacitate() == rhs.getCapacitate() && lhs.getConsum100() == rhs.getConsum100();
} //Inmatriculare nu este introdus ca criteriu de comparatie, deoarece nu pot exista 2 avioane cu aceeasi inmatriculare
bool operator!=(const Avioane &lhs, const Avioane &rhs){
    return lhs.getModel()!=rhs.getModel() || lhs.getCapacitate() != rhs.getCapacitate() || lhs.getConsum100() != rhs.getConsum100();
}
ostream& operator<<(ostream& os, const Avioane &rhs) {
    os << rhs.inmatriculare << ' ' << rhs.model << ' ' << rhs.capacitate_zbor << ' ' << rhs.consum100;
    return os;
}
istream& operator>>(istream& is, Avioane &rhs){
    char aux[255];
    cout << "Inmatriculare: ";
    is >> aux;
    rhs.setInmatriculare(aux);
    cout << "Model: ";
    is >> aux;
    rhs.setModel(aux);
    cout << "Capacitate zbor(km): ";

    is >> aux;
    rhs.setCapacitate(atoi(aux));
    cout << "Consum100: ";
    is >> aux;
    rhs.setConsum100(atoi(aux));
    return is;

}
