#ifndef MAZE_SOLVER_MAZE_H
#define MAZE_SOLVER_MAZE_H

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std; 

class Maze {
    int width;
    int height;
    vector<vector<bool>> data;
    const char SPACE = ' '; 
    const char WALL = 'X';
    vector<char> validChars = {SPACE, WALL};
    // path steps are marked 0-9, a-z, A-Z and then the sequence repeats
    const string PATH_SYMBOLS = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<string> validateInputData(vector<vector<char>>);
    pair<int,int> getCoords(int);
  public: 
    Maze(vector<vector<char>>);
    int getWidth();
    int getHeight();
    bool isFreeCell(pair<int,int>);
    vector<int> getNeighbours(int);
    vector<vector<char>> draw();
    vector<vector<char>> draw(vector<int>);
};

#endif