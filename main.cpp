#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    int x;
    std::cout << "\tChoose which type of graph do you want:" << endl;
    std::cout << "\nEnter '0' for undirected graph";
    std::cout << "\nEnter '1' for directed graph" << endl;

    cin >> x;

    Graph *g = new Graph(x); // creates graph based on user cli input

    vertex *a = new vertex(1);
    vertex *b = new vertex(2);
    vertex *c = new vertex(3);
    vertex *d = new vertex(4);
    vertex *e = new vertex(10);

    g->addVertex(a);
    g->addVertex(b);
    g->addVertex(c);
    g->addVertex(d);
    g->addVertex(e);

    if (g->isEmpty() == 1)
    {
        std::cout << "\nThe graph is empty." << endl;
    }
    else
    {
        std::cout << "\nThe graph is not empty." << endl;
    }

    if (g->isDirected() == 1)
    {
        std::cout << "\nThe graph is directed." << endl;
    }
    else
    {
        std::cout << "\nThe graph is not directed." << endl;
    }
    g->display();

    std::cout << "adding edge";
    vertex *f = new vertex(101);
    g->addEdge(b, f);
    g->display();

    int numVertices;
    numVertices = g->numVertices();
    cout << "Number Of Vertices in Graph" << numVertices << endl;
};
