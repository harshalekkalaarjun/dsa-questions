// middele of linked list
// Function to find the middle of a linked list
// It uses the two-pointer technique where one pointer moves twice as fast as the other.
// The middle node is returned when the fast pointer reaches the end of the list.

// leetcode problem 876
// Definition for singly-linked list.
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
    middleNode(){
        Node* slow = head; // Slow pointer starts at the head
        Node* fast = head; // Fast pointer starts at the head
    while( fast != NULL && fast-> next != NULL){
        slow = slow->next;
        fast = fast->next->next; // Move the fast pointer two steps ahead}
    }
    cout << "Middle node is: " << slow->data << endl; // Print the data of the middle node
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
    ll.middleNode(); // Find and print the middle node of the linked list
    return 0; // Return 0 to indicate successful execution
}