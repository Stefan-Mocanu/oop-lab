//
// Created by Stefan on 18-Apr-23.
//

#ifndef OOP_AVIOANE_H
#define OOP_AVIOANE_H

#include<iostream>
class Avioane {
    char *inmatriculare, *model;
    int capacitate_zbor, consum100;
public:
    Avioane();
    Avioane(const char *n,const  char *m,int cap,int comb) ;
    Avioane(const Avioane &av);
    char *getInmatriculare() const;
    char *getModel() const;
    int getCapacitate() const;
    int getConsum100() const;
    void setInmatriculare(const char *i);
    void setModel(const char *i);
    void setCapacitate(int i);
    void setConsum100(int i);
    Avioane &operator=(const Avioane &av);


    ~Avioane();
    friend std::ostream& operator<<(std::ostream& os, const Avioane &rhs);
    friend std::istream& operator>>(std::istream& is, Avioane &rhs);
};


#endif //OOP_AVIOANE_H
