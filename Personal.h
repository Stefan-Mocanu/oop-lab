//
// Created by Stefan on 20-Apr-23.
//

#ifndef OOP_PERSONAL_H
#define OOP_PERSONAL_H
#include<string>
#include<vector>
#include<iostream>
#include<memory>
class Personal {
protected:
    std::string nume,prenume;
    int cod_angajat;
    static int coduri_de_angajat;
public:
    static std::vector<std::shared_ptr<Personal>> prs;
    Personal(const std::string &nume, const std::string &prenume);
    Personal();
    Personal(const Personal &pers);
    const std::string &getNume() const;

    void setNume(const std::string &nume);

    const std::string &getPrenume() const;

    void setPrenume(const std::string &prenume);

    virtual ~Personal();

    int getCodAngajat() const;

    void setCodAngajat(int codAngajat);

    virtual std::string getTipPersonal() const = 0;
    virtual void afis()const;
    friend std::ostream& operator<<(std::ostream& out, const Personal& pers);

    static void adauga_ps(std::vector<std::shared_ptr<Personal>> ad);
    static void afiseaza_ps();
};


#endif //OOP_PERSONAL_H
