//
// Created by Stefan on 22-Apr-23.
//

#ifndef OOP_PERSONAL_NENAVIGANT_H
#define OOP_PERSONAL_NENAVIGANT_H
#include "Personal.h"
#include "NonNavigant_Jobs.h"
#include <string>
#include <ostream>

class Personal_NeNavigant : public Personal {
    non_navigant_jobs job;
    std::string aeroport_baza;
public:
    Personal_NeNavigant(const std::string &nume, const std::string &prenume, non_navigant_jobs job,
                        const std::string &aeroportBaza);

    Personal_NeNavigant();

    Personal_NeNavigant(Personal_NeNavigant &pers);

    std::string getTipPersonal() const override;

    non_navigant_jobs getJob() const;

    void setJob(non_navigant_jobs job);

    const std::string &getAeroportBaza() const;

    void setAeroportBaza(const std::string &aeroportBaza);
    void afis() const override;
    ~Personal_NeNavigant() override;

};


#endif //OOP_PERSONAL_NENAVIGANT_H
