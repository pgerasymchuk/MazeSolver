#ifndef LAB3_PRIORITY_QUEUE
#define LAB3_PRIORITY_QUEUE

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