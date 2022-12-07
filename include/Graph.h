#pragma once
#include <iostream>
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
        nextVertex = NULL;
        prevVertex = NULL;
        rightneighbour = NULL;
        leftneighbour = NULL;
    }
    ~vertex() {}

    int data;
    vertex *nextVertex;
    vertex *prevVertex;
    vertex *rightneighbour;
    vertex *leftneighbour;
};

class Graph
{
private:
    bool directed;

public:
    vertex *head = NULL;

    Graph() {}

    Graph(int dir)
    {
        directed = dir;
        // cout<<"\nParameter Constructor"<<endl;
    }

    ~Graph() {}

    void display();
    void addVertex(vertex *newVertex);
    bool isEmpty();
    bool isDirected();
    void addEdge(vertex *vertex1, vertex *vertex2);
    void removeEdge(vertex *vertex1, vertex *vertex2);
    // void removeNeighbour(vertex *vertex1, vertex *vertex2);
    // bool removeVertex(vertex *v);
    // int neighbours(vertex *v);
    int numVertices();
    // int numEdge();
    // int indegree(vertex *v);
    // int outdegree(vertex *v);
    // int degree(vertex *v);
    // bool neighbour(vertex *vertex1, vertex *vertex2);
};