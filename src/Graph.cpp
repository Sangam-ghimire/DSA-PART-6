#include "Graph.h"
#include <cstdlib>

bool Graph::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
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
        return true;
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
