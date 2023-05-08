#ifndef LAB3_MAZE_SOLVER_H
#define LAB3_MAZE_SOLVER_H

#define INF 1000000
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include "Cell.h"
#include "PriorityQueue.h"
#include "Maze.h"
using namespace std;

class MazeSolver {
    vector<string> errors;
    Maze maze;
    vector<int> findPath(pair<int,int>,pair<int,int>);
    bool isValidCoords(pair<int,int>);
  public:
    MazeSolver(Maze);
    vector<int> solve(pair<int,int>,pair<int,int>);
};

#endif