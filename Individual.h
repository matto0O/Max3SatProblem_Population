//
// Created by Mateusz on 19.01.2022.
//

#ifndef TEPPROJEKT_INDIVIDUAL_H
#define TEPPROJEKT_INDIVIDUAL_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Max3SatProblem.h"
#include "Clause.h"

class Individual {
public:
    Individual(int aog, double mc, double cc);

    Individual(const Individual &s);

    Individual(const Individual& p1, Individual &p2);

    std::pair<Individual,Individual> cross(Individual parent2);
    void mutate();
    bool* getGenes();
    int getFitness(std::vector<Clause> clauses);


    string to_string();

private:
    int amountOfGenes;
    double mutationChance, crossingChance;
    bool* genes;

    void setGenesToOtherParents(Individual &p1, Individual &p2);
};


#endif //TEPPROJEKT_INDIVIDUAL_H
