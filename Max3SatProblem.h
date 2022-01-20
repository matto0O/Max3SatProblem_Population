//
// Created by Mateusz on 18.01.2022.
//

#ifndef TEPPROJEKT_MAX3SATPROBLEM_H
#define TEPPROJEKT_MAX3SATPROBLEM_H

#include <vector>
#include <map>
#include <string>
#include "Clause.h"

using namespace std;

class Max3SatProblem {
public:
    Max3SatProblem(const string& fileName);

    static int compute(bool* newSolution, const vector<Clause>& clauses_param);
    int getSize();
    vector<Clause> getClauses();

private:
    int size;
    vector<Clause> clauses;
    int load(const string& fileName);
};


#endif //TEPPROJEKT_MAX3SATPROBLEM_H
