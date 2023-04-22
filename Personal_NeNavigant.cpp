//
// Created by Stefan on 22-Apr-23.
//

#include "Personal_NeNavigant.h"

Personal_NeNavigant::Personal_NeNavigant(const std::string &nume, const std::string &prenume, non_navigant_jobs job,
                                         const std::string &aeroportBaza) : Personal(nume, prenume), job(job),
                                                                            aeroport_baza(aeroportBaza) {}

Personal_NeNavigant::Personal_NeNavigant() = default;

non_navigant_jobs Personal_NeNavigant::getJob() const {
    return job;
}

Personal_NeNavigant::Personal_NeNavigant(Personal_NeNavigant &pers): Personal(pers),
                                        job(pers.job),aeroport_baza(pers.aeroport_baza){}

std::string Personal_NeNavigant::getTipPersonal() const{
    return "Personal NeNavigant";
}

void Personal_NeNavigant::setJob(non_navigant_jobs Job) {
    Personal_NeNavigant::job = Job;
}

const std::string &Personal_NeNavigant::getAeroportBaza() const {
    return aeroport_baza;
}

void Personal_NeNavigant::setAeroportBaza(const std::string &aeroportBaza) {
    aeroport_baza = aeroportBaza;
}
void Personal_NeNavigant::afis() const{
    this->Personal::afis();
    switch(job){
            case non_navigant_jobs::agent_check_in:{std::cout<<"agent check in ";break;}
            case non_navigant_jobs::tehnic:{std::cout<<"tehnic";break;}
    }
    std::cout<< " aeroport_baza: "<< aeroport_baza;
}


Personal_NeNavigant::~Personal_NeNavigant() = default;
