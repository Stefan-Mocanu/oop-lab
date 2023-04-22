//
// Created by Stefan on 20-Apr-23.
//

#include "Personal_Navigant.h"

Personal_Navigant::Personal_Navigant(const std::string &Nume,const std::string &Prenume,const std::vector<std::string> &Tip_avioane,const navigant_jobs &Job):
            Personal(Nume,Prenume),tip_avioane(Tip_avioane),job(Job){}

Personal_Navigant::Personal_Navigant() :tip_avioane({}),job(navigant_jobs::insotitor_de_bord){}

Personal_Navigant::Personal_Navigant(const Personal_Navigant &pers): Personal(pers),tip_avioane(pers.tip_avioane),job(pers.job){}

std::string Personal_Navigant::getTipPersonal() const {return "Personal navigant";}
void Personal_Navigant::adaugaTipAvioane(const std::vector<std::string> &adauga){
    for(const auto &elem : adauga){
        tip_avioane.push_back(elem);
    }
}
void Personal_Navigant::stergeTipAvioane(const std::vector<std::string> &sterge){
    for(const auto &elem :sterge){
        bool ok = false;
        for(auto i = tip_avioane.begin();i<tip_avioane.end();i++){
            if(*i == elem){ok=true;tip_avioane.erase(i);break;}
        }
        if(!ok)std::cout<<"Nu exista";
    }
}
std::vector<std::string> Personal_Navigant::getTipAvioane(){
    return tip_avioane;
}
void Personal_Navigant::afis()const{
    Personal::afis();
    switch(job){
        case navigant_jobs::insotitor_de_bord:{std::cout<<"Insotitor de Bord ";break;};
        case navigant_jobs::pilot: {std::cout<<"Pilot ";break;}
        case navigant_jobs::copilot: {std::cout<<"Copilot ";break;}
    }
    for(auto elem : tip_avioane){
        std::cout<<elem;
    }
}



navigant_jobs Personal_Navigant::getJob() const {
    return job;
}

void Personal_Navigant::setJob(navigant_jobs Job) {
    Personal_Navigant::job = Job;
}


