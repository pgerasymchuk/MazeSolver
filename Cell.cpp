#include "Cell.h"

Cell::Cell(int v, int d) : vertex(v), distance(d) {}
bool Cell::operator>(Cell other) {return distance > other.distance;}
bool Cell::operator<(Cell other) {return distance < other.distance;}