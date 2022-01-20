//
// Created by Mateusz on 19.01.2022.
//

#ifndef TEPPROJEKT_OPTIMIZER_H
#define TEPPROJEKT_OPTIMIZER_H

#include "Max3SatProblem.h"
#include <iostream>
#include <utility>
#include <vector>
#include "Individual.h"
#include "Clause.h"

class Optimizer {
public:
    Optimizer(Max3SatProblem msp, int populationSize, int tournamentSize, double crossingChance, double mutationChance);

    void runIteration();
    void printPopulation();

private:
    int tournamentSize, populationSize;
    double crossingChance, mutationChance;
    void initialize(int ps, int gp);
    std::vector<Individual> population;
    Individual * tournament();
    std::vector<Clause> clauses;

    std::pair<Individual, Individual> giveBirth();
};


#endif //TEPPROJEKT_OPTIMIZER_H
