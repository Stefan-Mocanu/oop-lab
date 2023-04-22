//
// Created by Stefan on 18-Apr-23.
//

#ifndef OOP_AVIOANE_H
#define OOP_AVIOANE_H

#include<iostream>
#include<string>
#include<vector>
class Avioane {
    std::string inmatriculare, model;
    int capacitate_zbor, consum100;
public:
    static std::vector<Avioane> avi;
    static int len_avi;
    static void af_avi();
    Avioane();
    Avioane(std::string n,std::string m,int cap,int comb) ;
    Avioane(const Avioane &av);
    std::string getInmatriculare() const;
    std::string getModel() const;
    int getCapacitate() const;
    int getConsum100() const;
    void setInmatriculare(std::string i);
    void setModel(std::string i);
    void setCapacitate(int i);
    void setConsum100(int i);
    Avioane &operator=(const Avioane &av);

    friend std::ostream& operator<<(std::ostream& os, const Avioane &rhs);
    friend std::istream& operator>>(std::istream& is, Avioane &rhs);
};


#endif //OOP_AVIOANE_H
