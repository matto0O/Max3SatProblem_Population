//
// Created by Mateusz on 18.01.2022.
//

#include "Clause.h"

Clause::Clause(const vector<int>& args) {
    for(int a: args) values.insert(pair<int,bool>(abs(a),a>0));
}

string Clause::to_string() const {
    string stringBuilder;
    for(auto value : values)
        stringBuilder+=std::__cxx11::to_string(value.first)+" ";
    return stringBuilder;
}

bool Clause::isFulfilled(const bool* m) {
    for(auto value : values)
        if(value.second==m[value.first]) return true;
    return false;
}

