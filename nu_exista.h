//
// Created by Stefan on 22-Apr-23.
//

#ifndef OOP_NU_EXISTA_H
#define OOP_NU_EXISTA_H
#include<exception>

class nu_exista : public std::exception{
public:
    nu_exista();
    const char* what() const noexcept override;
};


#endif //OOP_NU_EXISTA_H
