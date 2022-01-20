//
// Created by Mateusz on 19.01.2022.
//

#include "Individual.h"
#include <iostream>

Individual::Individual(int aog, double mc, double cc) {
    amountOfGenes = aog;
    mutationChance = mc;
    crossingChance = cc;
    genes = new bool[amountOfGenes];
    for(int i=0;i<amountOfGenes;i++)
        genes[i] = (rand() % 2 == 1);
}

Individual::Individual(const Individual &s) {
    amountOfGenes = s.amountOfGenes;
    mutationChance = s.mutationChance;
    crossingChance = s.crossingChance;
    genes = new bool[amountOfGenes];
    for(int i=0; i<amountOfGenes; i++)
        genes[i] = s.genes[i];
}

Individual::Individual(const Individual &p1, Individual &p2) {
    amountOfGenes = p1.amountOfGenes;
    mutationChance = p1.mutationChance;
    crossingChance = p1.crossingChance;
    genes = new bool[amountOfGenes];
    for(int i=0;i<amountOfGenes;i++) {
        if (rand() % 2 == 1) {
            genes[i] = p1.genes[i];
        } else genes[i] = p2.genes[i];
    }
}

void Individual::mutate() {
    for(int i=0; i<amountOfGenes;i++)
        if (rand() % 101 <= mutationChance) genes[i] = !genes[i];
}

bool *Individual::getGenes() {
    return genes;
}

void Individual::setGenesToOtherParents(Individual &p1, Individual &p2) {
    for(int i=0; i<amountOfGenes;i++)
        if(genes[i] == p1.genes[i]) genes[i] = p2.genes[i];
}

std::pair<Individual, Individual> Individual::cross(Individual parent2) {
    if((rand() % 101)>crossingChance*100) return std::pair<Individual,Individual>(Individual(*this),Individual(parent2));
    else{
        Individual child1 = Individual(*this,parent2);
        Individual child2 = Individual(child1);
        child2.setGenesToOtherParents(*this,parent2);
        return std::pair<Individual,Individual>(child1,child2);
    }
}

int Individual::getFitness(std::vector<Clause> clauses_param) {
    return Max3SatProblem::compute(genes,clauses_param);
}

string Individual::to_string() {
    string s;
    for(int i=0; i<amountOfGenes;i++) s+=std::to_string(genes[i]);
    return s;
}
