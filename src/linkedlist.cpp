#include <iostream>
#include "linkedlist.h"

using namespace std;

Node::Node(){}

bool LinkedList :: is_empty(){
    if(head == NULL) {
        return true;

    }   else {
        return false;
    }
}

void LinkedList :: addToHead(int a){

    Node *newNode = new Node();	

    newNode->data = a;

    newNode->next = this->head;
    this->head = newNode;

    if (this->tail == NULL)
    {
        this->tail = this->head;
    }

}

void LinkedList :: addToTail(int a ){

    Node *newNode = new Node();

    newNode->data = a;
    newNode->next = NULL;

    if (is_empty()){

        tail = newNode;

        if (head == NULL)
        {
            head = tail;
        }
        
    
    }   else {
        tail -> next = newNode;
        tail = tail -> next;

    }
}

void LinkedList :: add(int x, Node *pred){
    Node *newNode =  new Node();

    newNode -> data = x;
    
    newNode -> next = pred->next;
    pred -> next = newNode;

    // delete newNode;
}

void LinkedList :: removeFromHead(){
    Node *NodeToDelete = new Node();;

    if(is_empty() == false){

        NodeToDelete = head;
        head = NodeToDelete -> next;

        if (head == NULL)
        {

            tail = NULL;

        }
        

    }
}

void LinkedList :: remove(int a) {

    if (is_empty() == false)
    {
        if (this->head->data == a)
        {
            
            this->removeFromHead();
        }

        else
        {
            Node *temp = this->head->next;
            Node *prev = this->head;
            while (temp != NULL)
            {
                if (temp->data == a)
                {
                    break;
                }

                else
                {
                    temp = temp->next;
                    prev = prev->next;
                }
            }

            if (temp != NULL)
            {

                prev->next = temp->next;
                temp->next = NULL;

                // delete temp;
                
                if (prev->next == NULL)
                {
                    this->tail = prev;
                }
            }
        }
    }
}


Node* LinkedList :: retrieve(int x , Node *p){

    Node *temp = new Node();
    // Node result;

    temp = p;

    if(p == NULL){
        cout<<"The Linked list is empty."<<endl;
        return NULL;
    }   else {
    do{
        if(x == temp -> data){
            // result.next = temp;
            return temp;
        }   else {
            temp = temp ->next;
                    }
    }   while(temp != NULL);

        cout<<"\nNot Found!"<<endl;
        return NULL;
    
    }

    // delete temp;
    // delete result;
}


bool LinkedList :: search(int x){

    Node *temp = new Node();

    temp = head;

    if(head == NULL){
        return false;
        cout<<"The linked list is empty"<<endl;
    }   else{
        do{
            if(x == temp -> data){
                return true;
            }   else {
                temp = temp ->next;
            }
        }   while (temp != NULL);

        return false;
    }


}

void LinkedList ::  traverse(){

    Node *temp;

    temp = head;

    // if(head == NULL){
    //     cout<<"The linked list is empty"<<endl;
    // }   else {

        while (temp != 0)
        {
            /* code */

            cout<<"\n" << temp -> data <<endl;
            temp = temp -> next;

        }
        
    // }

    // delete temp;


}

int LinkedList :: numNodes(){

    int numNodes = 0;

    Node *temp = new Node();

    temp = head;

    while(temp -> next != NULL){

        numNodes++;

        temp = temp -> next;

    }

    return numNodes;


}