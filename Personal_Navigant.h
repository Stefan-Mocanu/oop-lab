//
// Created by Stefan on 20-Apr-23.
//

#ifndef OOP_PERSONAL_NAVIGANT_H
#define OOP_PERSONAL_NAVIGANT_H
#include "Personal.h"
#include "Navigant_Jobs.h"
#include <vector>
#include <string>
class Personal_Navigant : public Personal {
    std::vector<std::string> tip_avioane;
    navigant_jobs job;
public:
    Personal_Navigant();
    Personal_Navigant(const Personal_Navigant &pers);
    Personal_Navigant(const std::string &Nume,const std::string &Prenume,const std::vector<std::string> &Tip_avioane,const navigant_jobs &Job);
    std::string getTipPersonal() const override;
    void adaugaTipAvioane(const std::vector<std::string>& adauga);
    void stergeTipAvioane(const std::vector<std::string> &sterge);
    std::vector<std::string> getTipAvioane();

    navigant_jobs getJob() const;

    void setJob(navigant_jobs job);

    void afis()const override;
};


#endif //OOP_PERSONAL_NAVIGANT_H
