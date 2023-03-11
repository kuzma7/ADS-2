// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    else {
        double num = 1;
        for (uint16_t i = 1; i <= n; i++) {
            num = value * num;
        }
        return num;
    }
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 1;
    for (uint16_t i = 1; i <= count; i++) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = x;
    for (uint16_t i = 2; i <= count; i++) {
        result = result + calcItem(x, 2 * i - 1) * pown(-1, i - 1);
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 1;
    for (uint16_t i = 2; i <= count; i++) {
        result = result + calcItem(x, 2 * i - 2) * pown(-1, i - 1);
    }
    return result;
}
