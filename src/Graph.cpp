#include "Graph.h"
#include <cstdlib>
#include <iostream>

using namespace std;

bool Graph::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }       else{
        return false;
    }

}
bool Graph::isDirected()
{
    if (directed == true)
    {
        return true;
    }
    return false;

}
// add vertex
// add edge
// remove vertex
// remove edge
// neighbour
// neighbour

void Graph :: addVertex(vertex *&newVertex){

    vertex *temp;

    temp = head;

    head->next = newVertex;
    newVertex->next = temp->next;

}

void Graph :: addNeighbour(vertex *&v1, vertex *&v2){

    vertex *temp;
    vertex *n;

    temp = head;

    while(temp != NULL){

        if(temp -> data == v1 -> data){

            n = temp;

            temp -> neighbour = v2;
            v2 -> next = n -> neighbour;

        }       else{

            temp = temp ->next;

        }

    }

}

void Graph :: addEdge(vertex *&v1 , vertex *&v2){

    vertex *temp;

    temp = head;

    while(temp != NULL){

        if(temp -> data == v1 -> data){

            v2 -> next = temp -> neighbour;
            temp -> neighbour = v2;

            break;

        }       else{

            temp = temp -> next;
        }

    }

}

void Graph :: removeNeighbour(vertex *&v1 , vertex *&v2){

    vertex *temp;

    temp = head;

    while(temp != NULL){

        if(temp -> data = v1 -> data){

            vertex *n;

            n = temp -> neighbour;

            while (n != NULL )
            {

                if(n -> next -> data == v2 -> data){

                    n -> next = n -> next -> next;

                    break;

                }       else{

                    n = n -> next;

                }

            }
            

        }       else{

            temp = temp -> next;

        }

    }


}

bool Graph :: removeVertex(vertex *&v){

    vertex *temp;
    vertex *n;

    temp = head;

    while(temp != NULL){

        if(temp -> next -> data == v -> data){
            
            temp -> next = temp -> next -> next;

            n = temp;

            while (n != NULL)
            {

                removeNeighbour(n , v);

            }
            
            return true;

        }   else{

            temp = temp -> next;

        }

    }

    return false;
    
}

void Graph :: removeEdge(vertex *&v1 , vertex *&v2){

   removeNeighbour(v1,v2);

}


int Graph::numVertices()
{
    if (isEmpty() != true)
    {
        vertex *temp = head;
        int num = 0;
        while (temp->next != NULL)
        {
            num++;
            temp = temp->next;
        }
    }
    return 0;

}
int Graph::numEdge()
{
    int numEdge = 0;

    if (isEmpty() != true)
    {

        vertex *temp = head;

        while (temp->next != NULL)
        {
            // counting neighbour of each vertex
            while (temp->neighbour != NULL)
            {
                numEdge++;
                temp = temp->neighbour;
            }
            temp = temp->next;
        } // euta vetex ko

        if (directed == true)
        {
            return numEdge;
        }
        else
        {
            // since each edge is double in undirected graph
            numEdge = numEdge % 2;
            return numEdge;
        }
    }
    return 0;

}

int Graph::indegree(vertex *v)
{
    if (directed == true)
    {
        // we have to check whose neighbour does the given vertices is
        vertex *temp = head;
        int num = 0;
        // checking all the edges
        while (temp->next != NULL)
        {
            // checking all the neighbours of a particular edge
            while (temp->neighbour != NULL)
            {
                if (temp = v)
                {
                    num++;
                }
            }

            temp = temp->next;
        }
        return num;
    }
    else
    {

        std::cout << "It is not a directed graph.So, there exists only degree" << std::endl;

        return degree(v);
    }
}

int Graph::outdegree(vertex *v)
{

    if (directed == true)
    {
        vertex *temp = head;
        int num = 0;
        while (temp->neighbour != NULL)
        {
            num++;
            temp = temp->neighbour;
        }
        return num;
    }
    else
    {
        std::cout << "It is not a directed graph.So, there exists only degree" << std::endl;

        return degree(v);
    }

}

int Graph::degree(vertex *v)
{
    if (directed == true)
    {
        return (indegree(v) + outdegree(v));
    }
    else
    {
        return neighbours(v);
    }

}

int Graph :: neighbours(vertex *&v){

    int numNeighbours = 0;

    vertex *temp;
    vertex *n;

    temp = head;

    while(temp != NULL){

        if (temp -> data == v -> data)
        {
            /* code */

            n = temp;

            while(n -> next != NULL){

                numNeighbours++;

                n = n->next;

            }

            break;          

        }       else{

            temp = temp -> next;

        }
        

    }

    return numNeighbours;

}


bool Graph :: neighbour(vertex *&v1 , vertex *&v2){

    vertex *temp;
    vertex *n;

    temp = head;

    while(temp != NULL){

        if(temp -> data == v1 -> data){

            n = temp;

            while(n != NULL){

                if(n -> data == v2 -> data){

                    return true;

                }       else {

                    n = n -> next;
                }

            }

        }       else{

            temp = temp -> next;

        }

    }

    return false;

}

void Graph :: display(){

    vertex *temp;

    temp = head -> next;

    while(temp != NULL){

        cout<<"\t"<<temp -> data<<endl;

        temp = temp->next;

    }

}