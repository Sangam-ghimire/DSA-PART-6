#pragma once
class vertex
{
private:
    int data;

public:
    vertex *neighbour;
    vertex *next;
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
    void addVertex();
    void addEdge();
    bool removeVertex();
    bool removeEdge();
    int numVertices();
    int numEdge();
    int indegree(vertex *v);
    int outdegree(vertex *v);
    int degree(vertex *v);
    int neighbours(vetex *v);
    bool neighbour(vertex v1, vertex v2);
};