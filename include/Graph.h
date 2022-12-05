#pragma once

#include <iostream>

class vertex
{

public:

    int data;
    vertex *neighbour;
    vertex *next;

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
    int numVertices();
    int numEdge();
    int indegree(vertex *v);
    int outdegree(vertex *v);
    int degree(vertex *v);
    int neighbours(vertex *&v);
    bool neighbour(vertex *&v1, vertex *&v2);
    void display();

};