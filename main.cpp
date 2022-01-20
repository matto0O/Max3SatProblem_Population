#include <iostream>
#include "Max3SatProblem.h"
#include "Optimizer.h"

#define DEFAULT_TOURNAMENT_SIZE 2
#define DEFAULT_POPULATION_SIZE 20
#define DEFAULT_MUTATION_CHANCE 0.15
#define DEFAULT_CROSSING_CHANCE 0.35

using namespace std;

int main() {
    Max3SatProblem msp50 =
            Max3SatProblem(R"(C:\Users\Mateusz\CLionProjects\TEPprojekt\max3sat\50\m3s_50_0.txt)");
    Max3SatProblem msp100 =
            Max3SatProblem(R"(C:\Users\Mateusz\CLionProjects\TEPprojekt\max3sat\100\m3s_100_0.txt)");
    Max3SatProblem msp150 =
            Max3SatProblem(R"(C:\Users\Mateusz\CLionProjects\TEPprojekt\max3sat\150\m3s_150_0.txt)");;
    Max3SatProblem msp200 =
            Max3SatProblem(R"(C:\Users\Mateusz\CLionProjects\TEPprojekt\max3sat\200\m3s_200_0.txt)");;
    Max3SatProblem msp250 =
            Max3SatProblem(R"(C:\Users\Mateusz\CLionProjects\TEPprojekt\max3sat\250\m3s_250_0.txt)");
    Max3SatProblem msp300 =
            Max3SatProblem(R"(C:\Users\Mateusz\CLionProjects\TEPprojekt\max3sat\300\m3s_300_0.txt)");
    Max3SatProblem msp350 =
            Max3SatProblem(R"(C:\Users\Mateusz\CLionProjects\TEPprojekt\max3sat\350\m3s_350_0.txt)");
    auto* opt = new Optimizer(msp100,
                              DEFAULT_POPULATION_SIZE,
                              DEFAULT_TOURNAMENT_SIZE,
                              DEFAULT_MUTATION_CHANCE,
                              DEFAULT_CROSSING_CHANCE);

    cout<<"Generation 0"<<endl;
    opt->printPopulation();
    opt->runIteration();
    cout<<"Generation 1"<<endl;
    opt->printPopulation();
    opt->runIteration();
    cout<<"Generation 2"<<endl;
    opt->printPopulation();

    return 0;
}
