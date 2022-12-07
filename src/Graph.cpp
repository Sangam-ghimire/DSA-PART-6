#include "Graph.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void Graph ::addVertex(vertex *newVertex)
{

    if (isEmpty())
    {
        std::cout << "Inside isEmpty";
        head = newVertex;
    }
    else
    {
        // std::cout << "Inside notisEmpty";

        vertex *temp = new vertex();
        temp = head;

        while (temp->nextVertex != NULL && temp->data != newVertex->data)
        {
            // std::cout << "Inside whileeisEmpty";

            temp = temp->nextVertex;
        }
        if (temp->nextVertex == NULL)
        {
            temp->nextVertex = newVertex;
            newVertex->prevVertex = temp;
        }
        else
        {
            std::cout << "Vertex already exists" << std::endl;
        }
    }
}

void Graph ::display()
{

    vertex *temp = new vertex();

    temp = head;

    while (temp != NULL)
    {
        vertex *temp1 = temp;
        std::cout << temp->data << "|->| ";
        while (temp1->rightneighbour != NULL)
        {
            std::cout << temp1->rightneighbour->data << "|->|";
            temp1 = temp1->rightneighbour;
        }

        std::cout << std::endl;
        temp = temp->nextVertex;
    }
}

bool Graph ::isDirected()
{
    if (directed == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Graph ::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Graph ::addEdge(vertex *vertex1, vertex *vertex2)
{

    vertex *temp = new vertex();
    temp = head;

    while (temp != NULL && temp->data != vertex1->data)
    {
        temp = temp->nextVertex;
    }

    if (temp == NULL)
    {
        std::cout << "Vertex doesn't exists." << std::endl;
    }

    else
    {
        while (temp->rightneighbour != nullptr && temp->rightneighbour->data != vertex2->data)
        {
            temp = temp->rightneighbour;
        }
        if (temp->rightneighbour == NULL)
        {
            temp->rightneighbour = vertex2;
            vertex2->leftneighbour = temp;
        }

        else
        {
            std::cout << "Duplicate Edge found.Erorr 404" << std::endl;
        } // This will also not be used as not cli input taken
    }
}

void Graph ::removeEdge(vertex *vertex1, vertex *vertex2)
{
    vertex *temp = new vertex();
    temp = head;
    while (temp != NULL && temp->data != vertex1->data)
    {
        temp = temp->nextVertex;
    }
    if (temp == NULL)
    {
        std::cout << "Vertex" << vertex1->data << "doesn't exists." << std::endl;
    }
    else
    {
        temp = temp->rightneighbour;
        while (temp != NULL && temp->data != vertex2->data)
        {
            temp = temp->rightneighbour;
        }
        if (temp == NULL)
        {
            std::cout << "Edge doesn't exists" << std::endl;
        }
        else
        {
            if (temp->rightneighbour == NULL)
            {
                delete temp;
            }
            else
            {
                temp->leftneighbour->rightneighbour = temp->rightneighbour;
                temp->leftneighbour->rightneighbour = temp->leftneighbour;
                std::cout << "Sucessfully deleted" << temp->data;
                delete temp;
            }
        }
    }
}

int Graph ::neighbours(vertex *v)
{

    int neighbourCount = 0;
    vertex *temp = new vertex();
    temp = head;
    while (temp != NULL && temp->data != v->data)
    {
        temp = temp->nextVertex;
    }
    if (temp == NULL)
    {
        std::cout << "Vertex doesn't exist." << std::endl;
    }
    else
    {
        while (temp->rightneighbour != NULL)
        {
            neighbourCount++;
            temp = temp->rightneighbour;
        }
    }
    return neighbourCount;
}

int Graph::numVertices()
{
    int countVertices = 0;
    vertex *temp = new vertex();
    temp = head;
    while (temp != NULL)
    {
        countVertices++;
        temp = temp->nextVertex;
    }
    return countVertices;
}

int Graph::numEdge()
{

    int numEdges;
    vertex *tempVertex = new vertex();
    tempVertex = head;
    while (tempVertex != nullptr)
    {
        vertex *tempNeighbour = new vertex();
        tempNeighbour = tempVertex->rightneighbour;
        while (tempNeighbour != nullptr)
        {
            numEdges++;
            tempNeighbour = tempNeighbour->rightneighbour;
        }
        tempVertex = tempVertex->nextVertex;
    }
    return numEdges;
}

int Graph::indegree(vertex *v)
{
    int degree = 0;
    vertex *temp1 = head;
    while (temp1->nextVertex != NULL)
    {
        vertex *temp2 = temp1;

        while (temp2->rightneighbour != NULL)
        {
            temp2 = temp2->rightneighbour;
            if (temp2->data == v->data)
            {
                degree++;
            }
        }
        temp1 = temp1->nextVertex;
    }
    return degree;
}

int Graph::outdegree(vertex *v)
{
    int outdegree = 0;
    if (!isEmpty())
    {
        vertex *temp1 = head;
        if (isDirected())
        {
            while (temp1->data != v->data)
            {
                temp1 = temp1->nextVertex;
            }
            vertex *temp2 = temp1;

            while (temp2->rightneighbour != NULL)
            {
                outdegree++;
                temp2 = temp2->rightneighbour;
            }
        }
        else
        {
            return degree(v);
        }
    }
    return outdegree;
}

int Graph::degree(vertex *v)
{
    if (this->isDirected())
    {
        return (indegree(v) + outdegree(v));
    }
    else
    {
        return outdegree(v);
    }
}

bool Graph ::neighbour(vertex *vertex1, vertex *vertex2)
{

    vertex *temp = new vertex();
    temp = head;

    while (temp != NULL && temp->data != vertex1->data)
    {
        temp = temp->nextVertex;
    }

    if (temp == NULL)
    {
        std::cout << "Vertex doesn't exist." << std::endl;
        return false;
    }
    else
    {
        while (temp->rightneighbour != NULL && temp->rightneighbour->data != vertex2->data)
        {
            temp = temp->rightneighbour;
        }
        if (temp->rightneighbour == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

bool Graph::removeVertex(vertex *v)
{
    vertex *temp = new vertex();
    temp = head;
    while (temp != NULL && temp->data != v->data)
    {
        temp = temp->nextVertex;
    }
    if (temp == NULL)
    {
        std::cout << "Vertex doesn't exist" << std::endl;
    }
    else
    {
        if (temp->nextVertex == NULL)
        {
            temp->nextVertex->prevVertex = NULL;
        }
        else
        {
            temp->nextVertex->prevVertex = temp->prevVertex;
            temp->prevVertex->nextVertex = temp->nextVertex;
            delete temp;
        }
        vertex *remove = new vertex();
        remove = head;
        while (remove != nullptr)
        {
            if (neighbour(remove, v))
            {
                removeEdge(remove, v);
            }
            remove = remove->nextVertex;
            delete temp;
        }
    }

    return false;
};
