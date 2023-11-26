//
// Created by rathi on 11/23/2023.
//

#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <random>
#pragma once

class RandomIndex {
    std::mt19937 eng;
    std::uniform_int_distribution<> distr;
public:
    // Corrected the constructor name and added the correct return type (none).
    RandomIndex(int lower, int upper)
        : eng(std::random_device()())
        , distr(lower, upper)
    {}

    int operator()() {
        return distr(eng);
    }
};


#endif //RANDOMNUMBERGENERATOR_H
