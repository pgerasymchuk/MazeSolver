#ifndef MAZE_SOLVER_PRIORITY_QUEUE
#define MAZE_SOLVER_PRIORITY_QUEUE

#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class PriorityQueue {
    vector<T> heap;
    void bottomHeapify(int index);
    void upHeapify(int index);
  public:
    PriorityQueue();
    bool empty();
    void push(T element);
    void pop();
    T top();
};

#include "PriorityQueue.cpp"
#endif