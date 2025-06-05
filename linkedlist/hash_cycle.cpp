// Compiler: g++
// Compilation command: g++ -std=c++14 hash_cycle.cpp -o hash_cycle
// This code implements a linked list in C++ and checks for cycles in the linked list.
// hash_cycle.cpp
// leetcode problem: https://leetcode.com/problems/linked-list-cycle/
// This code implements a singly linked list in C++ with various operations such as insertion, deletion, and searching.
#include <iostream>
using namespace std;

class Node {
    public :
    int data ;
     Node* next ;
     Node ( int value ){
        data = value;
        next = NULL; // Initialize the next pointer to NULL
     }
};

class LIST{
    private : 
    Node* head;
    Node* tail;
    public :
    LIST(){
        head = tail =NULL;
    }
        void push_front(int val){ // Function to insert a new node at the front of the linked list
        Node* newNode = new Node(val); // Initialize a dummy node
        if (head == NULL){
            head= tail = newNode; // If the list is empty, set both head and tail to the new node
            return;
        }else{
            newNode-> next = head; // Set the next pointer of the new node to the current head
            head = newNode; // Update the head to point to the new node 

        }
    }
        void printll(){ // Function to print the linked list
            Node* temp = head; // Temporary pointer to traverse the list
            while (temp != NULL){
                cout << temp->data << " -> "; // Print the data of the current node
                temp = temp->next; // Move to the next node
            }
            cout << "NULL" << endl;

    }
    
    bool hash_cycle(){
        Node* slow = head; // Slow pointer starts at the head
        Node* fast = head; // Fast pointer starts at the head
        while( fast != NULL && fast-> next != NULL){
            slow = slow->next;
            fast = fast->next->next; // Move the fast pointer two steps ahead
            if (slow == fast) { // If the slow and fast pointers meet, there is a cycle
                return true;
            }
        }
        return false; // If no cycle is detected, return false
    }

};
int main (){
    LIST ll ; 
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.push_front(50);
    ll.printll(); // Print the linked list
    if (ll.hash_cycle()) {
        cout << "Cycle detected in the linked list." << endl; // If a cycle is detected, print a message
    } else {
        cout << "No cycle detected in the linked list." << endl; // If no cycle is detected, print a message
    }
    return 0; // Return 0 to indicate successful execution
}