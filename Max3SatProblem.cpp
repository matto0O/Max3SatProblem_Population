//
// Created by Mateusz on 18.01.2022.
//

#include "Max3SatProblem.h"
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

Max3SatProblem::Max3SatProblem(const string &fileName) {
    size = load(fileName);
}

int Max3SatProblem::load(const string& fileName) {
    ifstream file;
    file.open(fileName);
    string s;
    int maxNumber = 0;
    while(getline(file,s)){
        string stringBuilder;
        vector<int> args;
        for(char c: s){
            if(c!=32&&c!=40&&c!=41) stringBuilder+=c;
            else{
                if (!stringBuilder.empty()) {
                    int x = stoi(stringBuilder);
                    if(abs(x)>maxNumber) maxNumber = abs(x);
                    args.push_back(x);
                }
                stringBuilder="";
            }
        }
        clauses.emplace_back(args);
    }
    file.close();
    return maxNumber;
}

int Max3SatProblem::compute(bool* thisSolution, const vector<Clause>& clauses_param) {
    int result = 0;
    for(Clause c : clauses_param)
        if(c.isFulfilled(thisSolution)) result++;
    return result;
}

int Max3SatProblem::getSize() {
    return size;
}

vector<Clause> Max3SatProblem::getClauses() {
    return clauses;
}
