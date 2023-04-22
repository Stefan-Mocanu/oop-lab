//
// Created by Stefan on 22-Apr-23.
//

#include "input_invalid.h"
input_invalid::input_invalid() =default;

const char *input_invalid::what() const noexcept {
        return "\nINPUT INVALID.\n";
    }