//
// Created by Stefan on 18-Apr-23.
//

#include "Avioane.h"
#include <iostream>
#include <cstring>

using namespace std;

Avioane::Avioane(){
    inmatriculare = nullptr;
    model = nullptr;
    capacitate_zbor = 0;
    consum100 = 0;
}
Avioane::Avioane(const char *n,const  char *m,const  int cap,const  int comb) {
    if (n != nullptr) {
        int len1 = strlen(n) + 1;
        inmatriculare = new char[len1];
        strcpy(inmatriculare, n);
    }else{
        inmatriculare = nullptr;
    }
    if (m != nullptr){
        int len2 = strlen(m) + 1;
        model = new char[len2];
        strcpy(model, m);
    }else{
        model = nullptr;
    }
    capacitate_zbor = cap;
    consum100 = comb;
}
Avioane::Avioane(const Avioane &av){
    int len1 = strlen(av.model) + 1;
    int len2 = strlen(av.inmatriculare) + 1;
    inmatriculare = new char[len2];
    model = new char[len1];
    strcpy(inmatriculare, av.inmatriculare);
    strcpy(model, av.model);
    capacitate_zbor = av.capacitate_zbor;
    consum100 = av.consum100;
}
char *Avioane::getInmatriculare() const{
    return inmatriculare;
}
char *Avioane::getModel() const{
    return model;
}
int Avioane::getCapacitate() const{
    return capacitate_zbor;
}
int Avioane::getConsum100() const{
    return consum100;
}
void Avioane::setInmatriculare(const char *i){
    if(inmatriculare!=nullptr){
        delete[] inmatriculare;
    }
    int len1 = strlen(i)+1;
    inmatriculare = new char[len1];
    strcpy(inmatriculare, i);
}
void Avioane::setModel(const char *i){
    if(model!=nullptr){
        delete[] model;
    }
    int len1 = strlen(i)+1;
    model = new char[len1];
    strcpy(model, i);
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


Avioane::~Avioane(){
    delete[] inmatriculare;
    delete[] model;
}

bool operator==(const Avioane &lhs, const Avioane &rhs){
    return strcmp(lhs.getModel(),rhs.getModel())==0 && lhs.getCapacitate() == rhs.getCapacitate() && lhs.getConsum100() == rhs.getConsum100();
} //Inmatriculare nu este introdus ca criteriu de comparatie, deoarece nu pot exista 2 avioane cu aceeasi inmatriculare
bool operator!=(const Avioane &lhs, const Avioane &rhs){
    return strcmp(lhs.getModel(),rhs.getModel())!=0 || lhs.getCapacitate() != rhs.getCapacitate() || lhs.getConsum100() != rhs.getConsum100();
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
