#include "Graph.h"
#include <cstdlib>
#include <iostream>

using namespace std;

bool Graph :: isEmpty()
{
    if (head == NULL)
    {
        return true;
    }       else{
        return false;
    }

}

bool Graph :: isDirected()
{
    if (directed == true)
    {
        return true;
    }       else{
        return false;
    }

}


void Graph :: addVertex(vertex *&newVertex){


    vertex *temp;

    temp = head;

    if (temp == NULL)
    {
        /* code */
        head = newVertex;

    }       else{

        newVertex -> next = temp -> next;
        head = newVertex;

    }
    

    // head = newVertex;
    // cout<<"\naddvertex";
    // newVertex->next = temp->next;

    // delete temp;

}

void Graph :: addNeighbour(vertex *&v1, vertex *&v2){

    // vertex *temp = new vertex();
    // vertex *n = new vertex();

    // temp = head;

    // while(temp != NULL){

    //     if(temp -> data == v1 -> data){

    //         n = temp;

    //         temp -> neighbour = v2;
    //         v2 -> next = n -> neighbour;

    //     }       else{

    //         temp = temp ->next;

    //     }

    // }

    // delete temp;
    // delete n;

}

void Graph :: addEdge(vertex *&v1 , vertex *&v2){

    // cout<<"\naddEdge function called"<<endl;

    // vertex *temp ;

    // vertex *neighbourVertex = new vertex();

    // neighbourVertex = v2;

    // temp = head;

    // while(temp -> next != NULL){

    //     if(temp -> data == v1 -> data){

    //             cout<<"\naddEdge function called2"<<endl;


    //         neighbourVertex -> next = temp -> neighbour;
    //         temp -> neighbour = neighbourVertex;

    //         // break;

    //     }       else{

    //         temp = temp -> next;
    //     }

    // }

    // // cout<<"\naddEdge function called2"<<endl;


    // // delete temp;
    // delete neighbourVertex;


    vertex *temp = new vertex();
    temp = v2;

    if(directed == 1){

        v1->neighbour->addToHead(v2->data);

    }       else{

        v1->neighbour->addToHead(v2->data);
        v2->neighbour->addToHead(v1->data);

    }

}

void Graph :: removeNeighbour(vertex *&v1 , vertex *&v2){

    // vertex *temp = new vertex();

    // temp = head;

    // while(temp != NULL){

    //     if(temp -> data == v1 -> data){

    //         vertex *n = new vertex();

    //         n = temp -> neighbour;

    //         while (n != NULL )
    //         {

    //             if(n -> next -> data == v2 -> data){

    //                 n -> next = n -> next -> next;

    //                 break;

    //             }       else{

    //                 n = n -> next;

    //             }

    //         }
            

    //     }       else{

    //         temp = temp -> next;

    //     }

    // }

    // delete temp;

    vertex *temp = new vertex();

    if (isDirected())
    {
        /* code */

        v1 -> neighbour -> remove(v2->data);

    }       else{

        v1 -> neighbour -> remove(v2->data);
        v2 -> neighbour -> remove(v1->data);
        
    }
    
}


bool Graph :: removeVertex(vertex *&v){

    // vertex *temp = new vertex();
    // vertex *n = new vertex();

    // temp = head;

    // while(temp != NULL){

    //     if(temp -> next -> data == v -> data){
            
    //         temp -> next = temp -> next -> next;

    //         n = temp;

    //         while (n != NULL)
    //         {

    //             removeNeighbour(*&n , *&v);

    //             n = n->next;

    //         }
            
    //         return true;

    //     }   else{

    //         temp = temp -> next;

    //     }

    // }

    // delete temp;
    // delete n;

    // return false;

    vertex *temp = new vertex();
    vertex *n = new vertex();

    temp = head;

    if(!isEmpty()){

        return false;

    }       else{

        while(temp != NULL){

            if(temp->next->data == v->data){

                temp -> next = v -> next;
                
                n = head;

                while(n!=NULL){

                    removeNeighbour(*&n , *&v);

                    n = n->next;

                }

                return true;

            }       else{
                temp = temp -> next;
            }

        }


    }

    return false;


    
}

void Graph :: removeEdge(vertex *&v1 , vertex *&v2){

   removeNeighbour(v1,v2);

}

int Graph :: neighbours(vertex *&v){

    // int numNeighbours = 0;

    // vertex *temp = new vertex();
    // vertex *n = new vertex();

    // temp = head;

    // while(temp != NULL){

    //     if (temp -> data == v -> data)
    //     {
    //         /* code */

    //         n = temp;

    //         while(n -> next != NULL){

    //             numNeighbours++;

    //             n = n->next;

    //         }

    //         break;          

    //     }       else{

    //         temp = temp -> next;

    //     }
        

    // }

    // delete temp;
    // delete n;

    // return numNeighbours;


    int numNeighbours = 0;

    vertex *temp = new vertex();

    numNeighbours = v -> neighbour -> numNodes();

    return numNeighbours;



}


int Graph::numVertices()
{
    vertex *temp  = new vertex();
    if (isEmpty() != true)
    {
        temp = head;
        int num = 0;
        while (temp->next != NULL)
        {
            num++;
            temp = temp->next;
        }
    }

    delete temp;

    return 0;

}


int Graph::numEdge()
{
    int numEdge = 0;

    vertex *temp  = new vertex();

    if (isEmpty() != true)
    {

        temp = head;

        while (temp->next != NULL)
        {
            // counting neighbour of each vertex

            numEdge = numEdge + temp -> neighbour -> numNodes();

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

    delete temp;

    return 0;

}

int Graph::indegree(vertex *v)
{
    vertex *temp = new vertex();

    if (directed == true)
    {
        // we have to check whose neighbour does the given vertices is
        temp = head;
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

    delete temp;


}

int Graph::outdegree(vertex *v)
{

    // vertex *temp = new vertex();

    // if (directed == true)
    // {
        // temp = head;
        int num = 0;
        // while (temp->neighbour != NULL)
        // {
        //     num++;
        //     temp = temp->neighbour;
        // }

        num = v -> neighbour -> numNodes();

        return num;
    // }
    // else
    // {
    //     cout << "It is not a directed graph.So, there exists only degree" << endl;

    //     return degree(v);
    // }

    // delete temp;


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


bool Graph :: neighbour(vertex *&v1 , vertex *&v2){

    // vertex *temp = new vertex();
    // vertex *n = new vertex();

    // temp = head;

    // while(temp != NULL){

    //     if(temp -> data == v1 -> data){

    //         n = temp;

    //         while(n != NULL){

    //             if(n -> data == v2 -> data){

    //                 return true;

    //             }       else {

    //                 n = n -> next;
    //             }

    //         }

    //     }       else{

    //         temp = temp -> next;

    //     }

    // }

    // delete temp;
    // delete n;

    // return false;

    return v1 -> neighbour -> search(v2->data);



}

void Graph :: display(){

    cout<<"\nDisplay function call"<<endl;

    vertex *temp = new vertex();

    temp = head;

    while(temp->next != NULL){

        cout<<"\t"<<temp -> data<<endl;

        temp = temp->next;

    }

    delete temp;

}