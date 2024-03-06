//
// Created by Fernando on 06/03/2024.
//

#include "pl2.h"
inline bool isEven(unsigned int n){
    unsigned int mask = 0b0001;
    if((n & mask) == 1){
        return false;
    }
    return true;
}