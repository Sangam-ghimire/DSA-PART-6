#pragma once

#include "linkedlist.h"

class vertex
{
    
private:
    int data;

public:
    vertex *neighbour;
    vertex *next;

    LinkedList l;

};

class Graph
{

private:

    bool directed;

public:

    Graph(bool dir) { directed = dir; }
    ~Graph() {}

    vertex *head;

    bool isEmpty();
    bool isDirected();
    void addVertex(vertex *&newVertex);
    void addEdge(vertex *&vertex1, vertex *&vertex2);
    bool removeVertex();
    bool removeEdge();
    int numVertices();
    int numEdge();
    int indegree(vertex *v);
    int outdegree(vertex *v);
    int degree(vertex *v);
    int neighbours(vertex *v);
    bool neighbour(vertex v1, vertex v2);

};