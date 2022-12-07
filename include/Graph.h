#pragma once
#include <iostream>
#include "linkedlist.h"
using namespace std;

class vertex
{
private:
    int x;

public:
    vertex() {}
    vertex(int x)
    {
        data = x;
    }
    ~vertex() {}

    int data;
    Vertex *next;
    Vertex *prev;
    Vertex *rightneighbour;
    Vertex *leftneighbour;
};

class Graph
{

private:
    bool directed;

public:
    vertex *head;

    Graph()
    {

        head = NULL;
    }

    Graph(int dir)
    {

        head = NULL;
        directed = dir;

        // cout<<"\nParameter Constructor"<<endl;
    }

    ~Graph() {}

    bool isEmpty();
    bool isDirected();
    void addVertex(vertex *newVertex);
    void addNeighbour(vertex *vertex1, vertex *vertex2);
    void addEdge(vertex *vertex1, vertex *vertex2);
    void removeNeighbour(vertex *vertex1, vertex *vertex2);
    bool removeVertex(vertex *v);
    void removeEdge(vertex *vertex1, vertex *vertex2);
    int neighbours(vertex *v);
    int numVertices();
    int numEdge();
    int indegree(vertex *v);
    int outdegree(vertex *v);
    int degree(vertex *v);
    bool neighbour(vertex *vertex1, vertex *vertex2);
    void display();
};