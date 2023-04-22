//
// Created by Stefan on 22-Apr-23.
//

#ifndef OOP_INPUT_INVALID_H
#define OOP_INPUT_INVALID_H
#include<exception>

class input_invalid : public std::exception{
public:
    input_invalid();
    const char* what() const noexcept override;
};


#endif //OOP_INPUT_INVALID_H
