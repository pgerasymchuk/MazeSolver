#ifndef MAZE_SOLVER_PARSER_H
#define MAZE_SOLVER_PARSER_H

#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Parser {
  public:
    vector<vector<char>> parse(vector<string>);
    vector<string> serialize(vector<vector<char>>);
};


#endif