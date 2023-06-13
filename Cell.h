#ifndef MAZE_SOLVER_CELL_H
#define MAZE_SOLVER_CELL_H

struct Cell {
    int vertex;
    long long distance; //priority of the cell in the queue
    Cell(int, long long);
    bool operator>(Cell);
    bool operator<(Cell);
};

#endif