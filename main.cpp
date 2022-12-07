#include  <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    int x;
    cout<<"\tChoose which type of graph do you want:"<<endl;
    cout<<"\nEnter '0' for undirected graph";
    cout<<"\nEnter '1' for directed graph"<<endl;

    cin>>x;

    Graph g(x);


    vertex *v1 = new vertex();
    vertex *v2 = new vertex();
    // vertex *v3 = new vertex();
    // vertex *v4 =  new vertex();
    // vertex *v5 = new vertex();
    // vertex *v6 = new vertex();
    // vertex *v7 = new vertex();
    // vertex *v8 = new vertex();
    // vertex *v9 = new vertex();
    // vertex *v10 = new vertex();



    v1 -> data = 3;
    v2 -> data = 5;
    // v3 -> data = 6;
    // v4 -> data = 2;
    // v5 -> data = 8;
    // v6 -> data = 12;
    // v7 -> data = 34;
    // v8 -> data = 45;
    // v9 -> data = 53;
    // v10 -> data = 23;

    // cout<<"\t main1"<<endl;

    
    if(g.isEmpty() == 1){

        cout<<"\nThe graph is empty."<<endl;

    }       else{

        cout<<"\nThe graph is not empty."<<endl;
    }

    if (g.isDirected() == 1)
    {
        /* code */
        cout<<"\nThe graph is directed."<<endl;

    }       else{

        cout<<"\nThe graph is not directed."<<endl;

    }
    
    g.addVertex(*&v1);
    g.addVertex(*&v2);
    // g.addVertex(*&v3);
    // g.addVertex(*&v4);
    // g.addVertex(*&v5);
    // g.addVertex(*&v6);
    // g.addVertex(*&v7);
    // g.addVertex(*&v8);
    // g.addVertex(*&v9);
    // g.addVertex(*&v10);
    

    g.addEdge(*&v1,*&v2);
    // g.addEdge(*&v3,*&v5);
    // g.addEdge(*&v7,*&v9);
    // g.addEdge(*&v6,*&v4);
    // g.addEdge(*&v5,*&v1);
    // g.addEdge(*&v3,*&v10);
    // g.addEdge(*&v6,*&v9);

    // g.removeVertex(*&v3);
    // g.removeVertex(*&v5);
    // g.removeVertex(*&v9);

    cout<<"\nmain3"<<endl;

    g.display();

    // delete v1;
    // delete v2;



}