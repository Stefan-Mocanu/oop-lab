//
// Created by Stefan on 18-Apr-23.
//

#ifndef _ZBORURI_H_
#define _ZBORURI_H_
#include<iostream>

class Zboruri{
    char *plecare, *destinatie;
    int distanta;
public:
    Zboruri();
    Zboruri(const char *plec, const char *dest, int dist);

    Zboruri(const Zboruri &zb);

    char *getPlecare()const;
    char *getDestinatie()const;
    int getDistanta()const;
    void setPlecare(const char *plec);
    void setDestinatie(const char *dest);
    void setDistanta(int dist);
    Zboruri &operator=(const Zboruri &zb);

    ~Zboruri();
    friend std::ostream& operator<<(std::ostream& os, const Zboruri &rhs);
};


#endif
