#ifndef MAZE_SOLVER_MAZE_SOLVER_H
#define MAZE_SOLVER_MAZE_SOLVER_H

#define INF 1000000
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include "Cell.h"
#include "PriorityQueue.h"
#include "Maze.h"
using namespace std;

enum class Algorithm { Dijkstra, AStar };

class MazeSolver {
    vector<string> errors;
    Maze maze;
    int expandedCells = 0;
    int heuristic(int, int);
    vector<int> findPath(pair<int,int>,pair<int,int>,Algorithm);
    bool isValidCoords(pair<int,int>);
  public:
    MazeSolver(Maze);
    vector<int> solve(pair<int,int>,pair<int,int>,Algorithm = Algorithm::Dijkstra);
    int getExpandedCells();
};

#endif