//
// Created by Stefan on 20-Apr-23.
//

#include "Personal.h"
#include<iostream>

int Personal::coduri_de_angajat=100;
std::vector<std::shared_ptr<Personal>> Personal::prs;
const std::string &Personal::getNume() const {
    return nume;
}

void Personal::setNume(const std::string &Nume) {
    Personal::nume = Nume;
}

const std::string &Personal::getPrenume() const {
    return prenume;
}

void Personal::setPrenume(const std::string &Prenume) {
    Personal::prenume = Prenume;
}

int Personal::getCodAngajat() const {
    return cod_angajat;
}

void Personal::setCodAngajat(int CodAngajat) {
    cod_angajat = CodAngajat;
}

Personal::~Personal() = default;
void Personal::afis() const{
    std::cout<<getCodAngajat()<<" Nume: "<<getNume()<<((std::size(getNume())<6)?"\t":"")<<"\tPrenume: "
                <<getPrenume()<<((std::size(getPrenume())<6)?"\t":" ");
}

std::ostream& operator<<(std::ostream& out, const Personal& pers){
    pers.afis();
    return out;
}

Personal::Personal(const std::string &nume, const std::string &prenume) : nume(nume), prenume(prenume),cod_angajat(Personal::coduri_de_angajat++){}
Personal::Personal():cod_angajat(Personal::coduri_de_angajat++) {}
Personal::Personal(const Personal &pers) : nume(pers.nume),prenume(pers.prenume),cod_angajat(Personal::coduri_de_angajat++){}

void Personal::adauga_ps(std::vector<std::shared_ptr<Personal>> ad) {
    for(auto elem : ad)prs.push_back(elem);
}
void Personal::afiseaza_ps() {
    for(auto elem : prs)std::cout<<*elem<<std::endl;
}