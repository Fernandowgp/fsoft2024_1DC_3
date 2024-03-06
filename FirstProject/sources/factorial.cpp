//
// Created by Fernando on 06/03/2024.
//
#include "factorial.h"
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}