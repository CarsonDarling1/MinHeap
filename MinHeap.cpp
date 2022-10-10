//Carson Darling
//CSE310
//Assignment7



#include <string>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "MinHeap.h">

using namespace std;

Project::Project()          //Constructor for Project
{
    projName = "";
    int weight = 0;
}
Project::Project(string projectName)        //Constructor if a name if given
{
    projName = projectName;
}

Project::Project(string projectName, int newWeight)
{
    projName = projectName;
    weight = newWeight;
}

MinHeap::MinHeap()
{
    currentSize = 0;
    maxSize = 0;
    struct Project* projectList = NULL;
}

void MinHeap::create(int n)
{
    projectList = new Project[n];
    currentSize = 0;
    maxSize = n;
}

void MinHeap::minHeapInsert(string newProjectName)      //Loops through array and inserts into first open spot
{
    currentSize = currentSize + 1;
    int i = 1;
    while(projectList[i].projName != "")
        i += 1;
    if(i <= maxSize)
    {
        projectList[i].projName = newProjectName;
        projectList[i].weight = 1111111111;
        projectList[i].index = i;
    }
    else
        cout << "Project Max Size Reached. ";

}

void MinHeap::minHeapInsert(string newProjectName, int weight)      //Loops through array and inserts into first open spot
{
    currentSize = currentSize + 1;
    int i = 1;
    while(projectList[i].projName != "")
        i += 1;
    if(i <= maxSize)
    {
        projectList[i].projName = newProjectName;
        projectList[i].weight = weight;
    }
    else
        cout << "Project Max Size Reached. ";

}

void MinHeap::minHeapify(int index) //Source: Introduction to Algorithms, Third Edition pg 154 && Heap notes pdf pg 6
{
    int left = index * 2;
    int right = index * 2 + 1;
    int smallest;
    if(left <= currentSize && projectList[index].weight > projectList[left].weight)
        smallest = left;
    else
        smallest = index;
    if(right <= currentSize && projectList[index].weight > projectList[right].weight)
        smallest = right;
    if(smallest != index)
    {
        string temp = projectList[index].projName;
        int tempNum = projectList[index].weight;
        projectList[index].projName = projectList[smallest].projName;
        projectList[index].weight = projectList[smallest].weight;
        projectList[smallest].projName = temp;
        projectList[smallest].weight = tempNum;
        minHeapify(smallest);
    }
}

void MinHeap::buildMinHeap()    //Source: Introduction to Algorithms Third Edition pg 157 && Heaps pdf pg 11
{
    for(int i = currentSize/2; i >= 1; i--){
        minHeapify(i);
    }
}

void MinHeap::heapSort()        ////Source: Introduction to Algorithms Third Edition pg 160 && Heaps pdf pg 14
{
    buildMinHeap();
    for(int i = currentSize; i > 1; i--)
    {
        string temp = projectList[1].projName;
        int tempNum = projectList[1].weight;
        projectList[1].projName = projectList[i].projName;
        projectList[1].weight = projectList[i].weight;
        projectList[i].projName = temp;
        projectList[i].weight = tempNum;
        minHeapify(1);
    }
}

void MinHeap::printMinHeap()                //simple print function for the heap(given), given in the heap assignment Assignment 4
  {
    if (projectList == NULL)
    {
        cout << "The heap is empty" << endl;
    }
    else
    {
        cout << "Max Size: " << maxSize << endl;
        cout << "Current Size: " << currentSize << endl;
        int nextline = 1;
        if (projectList != NULL && currentSize > 0)
        {
            for (int i = 1; i <= currentSize; i = i*2)
            {
                int k = i;
                while (k < i+nextline && k <= currentSize)
                {
                      cout << std::left << setw(8) << projectList[k].projName << projectList[k].index << " ";
                      k++;
                }
                cout << endl;
                k = i;
                while (k < i+nextline && k <= currentSize)
                {
                      cout << std::left << setw(8) << projectList[k].weight << " ";
                      k++;
                }
              cout << endl;
              nextline *= 2;
            }
        }
        cout << endl;
    }
}

Project* MinHeap::extractMin()
{
    string name = projectList[1].projName;
    int theWeight = projectList[1].weight;
    int index = projectList[1].index;
    Project* storedProj = new Project(name, theWeight);
    projectList[1].projName = projectList[currentSize].projName;
    projectList[1].weight = projectList[currentSize].weight;
    projectList[1].index = projectList[currentSize].index;
    currentSize-=1;
    return storedProj;
}

void MinHeap::decreaseKey(int index, int newWeight)
{
    if(newWeight > projectList[index].weight)
    {
        cout << "Key is larger than current key. " << endl;
        cout << "New Weight " << newWeight << " project current " << projectList[index].weight;
        return;
    }
    projectList[index].weight = newWeight;
    Project *theProjectAt1;
    Project *theProjectAtLast;
    while(index > 1 && projectList[index/2].weight < projectList[index].weight)
    {
        theProjectAt1 = &projectList[index];
        theProjectAtLast = &projectList[index/2];
        projectList[index] = *theProjectAtLast;
        projectList[index/2] = *theProjectAt1;
        index = index/2;
    }
    /*projectList[index].weight = newWeight;

    heapSort();*/
}

