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
    // g->display();
};

// cout << "\nNumber of Vertices of Graph are: " << num_vertices << endl;

// g->display();

// bool n = g->isEmpty();
// cout << "The value of n is " << (int)n;
// g->addEdge(c, d);
// // g->display();

// g->addEdge(d,e);
// g->addEdge(b,c);
// g->addEdge(a,b);
// g->addEdge(e,d);

// g->removeVertex(e);

// g->removeEdge(c,d);

// int num_neighbour;

// num_neighbour = g->neighbours(a);

// cout<<"\nNumber of Neighbours of Vertex 'a' are: "<<num_neighbour<<endl;

// int num_edge;

// num_edge = g->numEdge();

// cout << "\nNumber of Graph 'a' are: " << num_edge << endl;

// int in_degree;

// in_degree = g->indegree(e);

// cout<<"\nNumber of In-Degree of Vertex 'e' are: "<<in_degree<<endl;

// int out_degree;

// out_degree = g->outdegree(d);

// cout<<"\nNumber of Out-Degree of Vertex 'd' are: "<<out_degree<<endl;

// int num_degree;

// num_degree = g->degree(a);

// cout<<"\nNumber of Degree of Vertex 'a' are: "<<num_degree<<endl;

// bool neighbour;

// neighbour = g->neighbour(d,e);

// if (neighbour == 1)
// {
//     /* code */
//     cout<<"\nThe vertex 'e' is a neighbour of vertex 'd'."<<endl;
// }
//         else{

//             cout<<"\nThe vertex 'e' isnot a neighbour of vertex 'd'."<<endl;
// }

// delete a;
// delete b;
// delete c;
// delete d;
