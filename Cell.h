#ifndef LAB3_CELL_H
#define LAB3_CELL_H

struct Cell {
    int vertex, distance;
    Cell(int, int);
    bool operator>(Cell);
    bool operator<(Cell);
};

#endif