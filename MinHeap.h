//Carson Darling
//CSE310
//Assignment7


#ifndef MINHEAP_H
#define MINHEAP_H

#include <string>
using namespace std;

// struct Project
struct Project {
    string projName;
    Project();
    Project(string newProj);
    int weight;
    int index;
    Project* next;
    Project(string projectName, int newWeight);
};

// create a MinHeap
struct MinHeap {
    int maxSize;
    int currentSize;
    struct Project * projectList;


    //TO BE COMPLETED

    MinHeap();
    void minHeapInsert(string newProjectName);
    void minHeapify(int i);
    void create(int n);
    void heapSort();
    void printMinHeap();
    void buildMinHeap();
    Project* extractMin();
    void decreaseKey(int i, int weight);
    void minHeapInsert(string newProjectName, int weight);

};

#endif
