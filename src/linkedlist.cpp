#include <iostream>
#include "linkedlist.h"

using namespace std;

Node::Node(){}


LinkedList :: LinkedList(){}

bool LinkedList :: is_empty(){
    if(head == NULL) {
        // cout<<"The linked list is empty"<<endl;
        return true;

    }   else {
        // cout<<"The linked list is not empty"<<endl;
        return false;
    }
}

void LinkedList :: addToHead(int a){

    Node *newNode = new Node();

    newNode -> data = a;

    if(head == NULL){
        head = newNode;
    }   else {
        newNode -> next = head;
        head = newNode;
    }
}

void LinkedList :: addToTail(Node *&a){
    if (tail == NULL){
        tail = a;
        head = a;
    }   else {
        tail -> next = a;
        tail = tail -> next;

    }
}

void LinkedList :: add(int x, Node *&pred){
    Node *newNode =  new Node();

    newNode -> data = x;
    
    newNode -> next = pred->next;
    pred -> next = newNode;

    delete newNode;
}

void LinkedList :: removeFromHead(){
    Node *NodeToDelete = new Node();;

    if(head == NULL){
        cout<<"The linked list is empty."<<endl;
    }   else{
        NodeToDelete = head;
        head = NodeToDelete -> next;
        delete NodeToDelete;
    }
}

void LinkedList :: remove(int a) {
    Node *NodeToDelete = new Node();
    Node *temp = new Node();

    NodeToDelete = head;
    temp = head;

    do{
        if (temp -> data == a){
            break;
        }   else {
            temp = temp -> next;
            NodeToDelete = temp;
        }
    }   while(temp != NULL);

    delete temp;
    delete NodeToDelete;
}


Node* LinkedList :: retrieve(int x , Node *&p){

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

    delete temp;
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

    delete temp;


}

void LinkedList ::  traverse(){

    Node *temp = new Node();

    temp = head;

    if(head == NULL){
        cout<<"The linked list is empty"<<endl;
    }   else {
        do{
            cout<<"\n" << temp -> data <<endl;
            temp = temp -> next;
        } while (temp != NULL);
    }

    delete temp;


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