//
// Created by Mateusz on 19.01.2022.
//

#include "Optimizer.h"
#include <random>


Optimizer::Optimizer(
        Max3SatProblem msp, int populationSize, int tournamentSize, double crossingChance, double mutationChance) {
    srand(time(nullptr));
    clauses = msp.getClauses();
    this->populationSize=populationSize;
    this->tournamentSize=tournamentSize;
    this->crossingChance=crossingChance;
    this->mutationChance=mutationChance;
    initialize(this->populationSize,msp.getSize());
}

void Optimizer::initialize(int ps, int gp) {
    for(int i=0; i<ps; i++) population.emplace_back(gp,mutationChance,crossingChance);
}

void Optimizer::runIteration() {
    std::vector<Individual> newPopulation;
    for(int i=0; i<population.size(); i+=2){
        std::pair<Individual,Individual> pair = giveBirth();
        newPopulation.emplace_back(pair.first);
        newPopulation.emplace_back(pair.second);
    }
    population = newPopulation;
}

Individual* Optimizer::tournament() {
    bool* contenders;
    contenders = new bool[populationSize];
    for(int i=0; i<populationSize; i++) contenders[i]=false;
    int x = 0;
    while(x < tournamentSize) {
        int index = rand()%populationSize;
        if(!contenders[index]){
            contenders[index]=true;
            x++;
        }
    }
    int winnerValue = 0;
    int winnerIndex = 0;
    for(int i=0; i<populationSize; i++){
        if(contenders[i]&&(population[i].getFitness(clauses)>winnerValue)){
            winnerValue = population[i].getFitness(clauses);
            winnerIndex=i;
        }
    }
    return &population[winnerIndex];
}

std::pair<Individual, Individual> Optimizer::giveBirth(){
    Individual* parent1 = tournament();
    Individual* parent2 = tournament();

    while(parent1==parent2) parent2 = tournament();

    std::pair<Individual,Individual> pair = parent1->cross(*parent2);
    pair.first.mutate();
    pair.second.mutate();
    return pair;
}

void Optimizer::printPopulation(){
    string s;
    for(int i=0; i<populationSize;i++) {
        s = population[i].to_string();
        printf("%2d - ",i);
        cout<<s<<endl;
    }
    for(int i=0; i<s.length()+5;i++)
        cout<<"=";
    cout<<endl;
}

