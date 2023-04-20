//
// Created by Stefan on 18-Apr-23.
//

#ifndef _ZBORURI_H_
#define _ZBORURI_H_
#include<iostream>
#include<string>
#include<vector>

class Zboruri{
    std::string plecare, destinatie;
    int distanta;
public:
    static std::vector<Zboruri> zbo;
    static int len_zbo;
    Zboruri();
    Zboruri(std::string plec, std::string dest, int dist);
    Zboruri(Zboruri &zbor);
    ~Zboruri();

    std::string getPlecare()const;
    std::string getDestinatie()const;
    int getDistanta()const;
    void setPlecare(std::string plec);
    void setDestinatie(std::string dest);
    void setDistanta(int dist);

    friend std::ostream& operator<<(std::ostream& os, const Zboruri &rhs);
    friend std::istream& operator>>(std::istream& is, Zboruri &rhs);
};


#endif
