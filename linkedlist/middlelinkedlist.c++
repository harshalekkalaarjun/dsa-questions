// middele of linked list
// Function to find the middle of a linked list
// It uses the two-pointer technique where one pointer moves twice as fast as the other.
// The middle node is returned when the fast pointer reaches the end of the list.

// leetcode problem 876
// Definition for singly-linked list.
#include <iostream>
using namespace std;

clsss Node {
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
        if (head =NULL){
            head= tail = newNode; // If the list is empty, set both head and tail to the new node
            return;
        }else{
            newNdoe-> next = head; // Set the next pointer of the new node to the current head
            head = newNode; // Update the head to point to the new node 

        }
    }
        void printll(){ // Function to print the linked list
            node* temp = head; // Temporary pointer to traverse the list
            while (temp != NULL){
                cout << temp->data << " -> "; // Print the data of the current node
                temp = temp->next; // Move to the next node
            }

    }
}
int main (){
    LIST ll ; 
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.push_front(50);
}