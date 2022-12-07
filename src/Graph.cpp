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

    cout << "\nDisplay function call" << endl;

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

// void Graph :: addNeighbour(vertex *vertex1, vertex *vertex2){

//     if (isDirected())
//     {
//         /* code */

//         vertex1->neighbour->addToHead(vertex2->data);

//     }       else{

//         vertex1->neighbour->addToHead(vertex2->data);
//         vertex2->neighbour->addToHead(vertex1->data);

//     }

// }

// void Graph ::removeNeighbour(vertex *vertex1, vertex *vertex2)
// {

//     vertex *temp = new vertex();

//     if (isDirected())
//     {
//         /* code */

//         vertex1 -> neighbour -> remove(vertex2->data);

//     }       else{

//         vertex1 -> neighbour -> remove(vertex2->data);
//         vertex2 -> neighbour -> remove(vertex1->data);

//     }

// }

// bool Graph :: removeVertex(vertex *v){

//     vertex *temp = new vertex();
//     vertex *n = new vertex();

//     temp = head;

//     if(!isEmpty()){

//         return false;

//     }       else{

//         while(temp != NULL){

//             if(temp->next->data == v->data){

//                 temp -> next = v -> next;

//                 n = head;

//                 while(n!=NULL){

//                     removeNeighbour(*&n , *&v);

//                     n = n->next;

//                 }

//                 return true;

//             }       else{
//                 temp = temp -> next;
//             }

//         }

//     }

//     return false;

// }

// void Graph ::removeEdge(vertex *vertex1, vertex *vertex2)
// {

//     removeNeighbour(vertex1, vertex2);
// }

// int Graph :: neighbours(vertex *v){

//     int numNeighbours = 0;

//     vertex *temp = new vertex();

//     numNeighbours = v -> neighbour -> numNodes();

//     return numNeighbours;

// }

// int Graph::numVertices()
// {
//     vertex *temp = new vertex();

//     temp = this->head;

//     int num = 0;

//     if (isEmpty() != true)
//     {
//         while (temp != NULL)
//         {
//             num++;
//             temp = temp->next;
//         }

//         return num;
//     }

//     return 0;
// }

// int Graph::numEdge()
// {

//    { // int numEdge = 0;

//     // vertex *temp  = new vertex();

//     // if (isEmpty() != true)
//     // {

//     //     temp = head;

//     //     while (temp->next != NULL)
//     //     {
//     //         // counting neighbour of each vertex

//     //         numEdge = numEdge + temp -> neighbour -> numNodes();

//     //         temp = temp->next;

//     //     } // euta vetex ko

//     //     if (directed == true)
//     //     {
//     //         return numEdge;
//     //     }
//     //     else
//     //     {
//     //         // since each edge is double in undirected graph
//     //         numEdge = numEdge % 2;
//     //         return numEdge;
//     //     }

//     }

//     cout<<"\nnumedge function called"<<endl;

//     int numEdge = 0;

// 	vertex *temp = new vertex();
// 	temp = this->head;

// 	while(temp != NULL)
// 	{
// 		numEdge += temp->neighbour->numNodes();
// 		temp = temp->next;
// 	}
// 	if(!this->isDirected())
// 	{
// 		return numEdge/2;
// 	}
// 	else
// 	{
// 		return numEdge;
// 	}

// 	delete temp;

//     return 0;
// }

// int Graph::indegree(vertex *v)
// {
//     vertex *temp = new vertex();

//     if (directed == true)
//     {
//         // we have to check whose neighbour does the given vertices is
//         temp = head;
//         int num = 0;
//         // checking all the edges
//         while (temp->next != NULL)
//         {
//             // checking all the neighbours of a particular edge
//             while (temp->neighbour != NULL)
//             {
//                 if (temp = v)
//                 {
//                     num++;
//                 }

//             }

//             temp = temp->next;
//         }
//         return num;
//     }
//     else
//     {

//         std::cout << "It is not a directed graph.So, there exists only degree" << std::endl;

//         return degree(v);
//     }

// }

// int Graph::outdegree(vertex *v)
// {

//     // vertex *temp = new vertex();

//     // if (directed == true)
//     // {
//         // temp = head;
//         int num = 0;
//         // while (temp->neighbour != NULL)
//         // {
//         //     num++;
//         //     temp = temp->neighbour;
//         // }

//         num = v -> neighbour -> numNodes();

//         return num;
//     // }
//     // else
//     // {
//     //     cout << "It is not a directed graph.So, there exists only degree" << endl;

//     //     return degree(v);
//     // }

//     //

// }

// int Graph::degree(vertex *v)
// {
//     if (directed == true)
//     {
//         return (indegree(v) + outdegree(v));
//     }
//     else
//     {
//         return (indegree(v) + outdegree(v));
//     }
// }

// bool Graph :: neighbour(vertex *vertex1 , vertex *vertex2){

//     return vertex1 -> neighbour -> search(vertex2->data);

// }
