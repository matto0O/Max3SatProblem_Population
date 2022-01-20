//
// Created by Mateusz on 18.01.2022.
//

#ifndef TEPPROJEKT_CLAUSE_H
#define TEPPROJEKT_CLAUSE_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class Clause {
public:
    Clause(const vector<int>& args);
    string to_string() const;
    bool isFulfilled(const bool* m);

private:
    map<int,bool> values;
};


#endif //TEPPROJEKT_CLAUSE_H
