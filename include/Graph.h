#pragma once

#include <iostream>

#include "linkedlist.h"

using namespace std;

class vertex
{

public:

    int data;
    vertex *next;
    LinkedList *neighbour;

    // LinkedList l;    

    vertex(){
        
    }

};

class Graph
{

private:

    bool directed;

public:

    vertex *head;

    Graph(){

        head = NULL;

    }

    Graph(int dir) { 

        head = NULL;
        directed = dir;

        // cout<<"\nParameter Constructor"<<endl;

    }

    ~Graph() {}


    bool isEmpty();
    bool isDirected();
    void addVertex(vertex *&newVertex);
    void addNeighbour(vertex *&v1, vertex *&v2);
    void addEdge(vertex *&v1, vertex *&v2);
    void removeNeighbour(vertex *&v1 , vertex *&v2);
    bool removeVertex(vertex *&v);
    void removeEdge(vertex *&v1 , vertex *&v2);
    int neighbours(vertex *&v);
    int numVertices();
    int numEdge();
    int indegree(vertex *v);
    int outdegree(vertex *v);
    int degree(vertex *v);
    bool neighbour(vertex *&v1, vertex *&v2);
    void display();

};