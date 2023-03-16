#ifndef PRIORITY_QUEUE_IMPL_CPP
#define PRIORITY_QUEUE_IMPL_CPP

#include "PriorityQueue.h"

template <typename T> 
void PriorityQueue<T>::bottomHeapify(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]){
            swap(heap[index], heap[parent]);
            index = parent;
        }   
        else {
            break;
        }  
    }
}

template <typename T>
void PriorityQueue<T>::upHeapify(int index){
    int size = heap.size();
    while (index < size) {
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;
        int minIndex = index;
        if (leftChild < size && heap[leftChild] < heap[minIndex]){
            minIndex = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[minIndex]){
            minIndex = rightChild;
        }
        if (minIndex != index) {
            swap(heap[index], heap[minIndex]);
            index = minIndex;
        } else {
            break;
        }
    }
}

template <typename T>
PriorityQueue<T>::PriorityQueue() {}

template <typename T>
bool PriorityQueue<T>::empty(){
    return heap.empty();
}

template <typename T>
void PriorityQueue<T>::push(T element){
    heap.push_back(element);
    bottomHeapify(heap.size()-1);
}

template <typename T>
void PriorityQueue<T>::pop(){
    if (heap.empty()){
        throw out_of_range("Impossible to extract min element: PriorityQueue is empty!");
    }
    else {
        T min = heap[0];
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        upHeapify(0);
    }
}

template <typename T>
T PriorityQueue<T>::top(){
    if (heap.empty()){
        throw out_of_range("Impossible to get min element: PriorityQueue is empty!");
    }
    else {
        return heap[0];
    }
}

#endif 