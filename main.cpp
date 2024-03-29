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
    vertex *f = new vertex(20);

    g->addVertex(a);
    g->addVertex(b);
    g->addVertex(c);
    g->addVertex(d);
    g->addVertex(e);


    if (g->isEmpty() == 1)
    {
        cout << "\nThe graph is empty." << endl;
    }
    else
    {
        cout << "\nThe graph is not empty." << endl;
    }

    if (g->isDirected() == 1)
    {
        cout << "\nThe graph is directed." << endl;
    }
    else
    {
        cout << "\nThe graph is not directed." << endl;
    }

    cout<<"\nThe vertices of the graph are displayed below: "<<endl;
    g->display();

    cout << "\nAdding edges:"<<endl;
    g->addEdge(b,f);
    g->addEdge(a,b);
    g->addEdge(b,c);

    cout<<"\nRemoving a edge: "<<endl;

    g->removeEdge(b,c);

    g->display();

    int numVertices;
    numVertices = g->numVertices();
    cout <<"\nThe number of vertices in the graph are: "<<numVertices<< endl;

    int numEdge;

    numEdge = g->numEdge();

    cout<<"\nThe number of edges in the graph are: "<<numEdge<<endl;

    int in_degree;

    in_degree = g->indegree(a);

    cout<<"\nThe In-Degree of the Vertex 'a' is: "<<in_degree<<endl;

    int out_degree;

    out_degree = g->outdegree(d);

    cout<<"\nNumber of Out-Degree of Vertex 'd' are: "<<out_degree<<endl;

    int num_degree;

    num_degree = g->degree(a);

    cout<<"\nNumber of Degree of Vertex 'a' are: "<<num_degree<<endl;

    bool n;

    n = g->neighbour(a,b);

    cout<<"\nIs Vertex 'b' a neighbour of Vertex 'a'?"<<endl;

    if(n == true){

        cout<<"\n\tYes!!"<<endl;

    }       else{

        cout<<"\n\tNo!!"<<endl;

    }

    int num_neighbour;

    num_neighbour = g->neighbours(a);

    cout<<"\nNumber of Neighbours of Vertex 'a' are: "<<num_neighbour<<endl;

};


