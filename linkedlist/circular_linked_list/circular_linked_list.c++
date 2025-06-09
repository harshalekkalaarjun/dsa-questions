#include <iostream>
using namespace std;

// Node class for circular linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;      // Assign value to node
        next = NULL;     // Initialize next pointer
    }
};

// Circular linked list class
class CircularList {
private:
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = NULL; // Initialize empty list
    }

    // Insert a node at the head of the list
    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode; // First node in the list
        }
        newNode->next = head;      // Point new node to current head
        head = newNode;            // Update head to new node
        tail->next = head;         // Maintain circularity
    }

    // Print the circular linked list
    void printcl (){
        if (head == NULL) return;  // Empty list
        cout << head->data << "->";
        Node* temp = head->next;
        while (temp != head) {     // Traverse until back to head
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl; // Print head again to show circularity
    }

    // Insert a node at the tail of the list
    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode; // First node in the list
            tail->next = head;     // Maintain circularity
        } else {
            newNode->next = head;  // New node points to head
            tail->next = newNode;  // Old tail points to new node
            tail = newNode;        // Update tail
        }
    }

    // Delete the head node
    void deleteAtHead(){
        if (head == NULL){
            return;                // Empty list
        }
        else if (head == tail){
            head = tail = NULL;    // Only one node
        }
        else {
            Node* temp = head;
            head = head->next;     // Move head forward
            tail->next = head;     // Maintain circularity
            temp->next = NULL;     // Detach node
            delete temp;           // Free memory
        }
    }

    // Delete the tail node
    void deleteAtTail(){
        if (head == NULL){
            return;                // Empty list
        }
        else if (head == tail){
            delete head;           // Only one node
            head = tail = NULL;
        }
        else {
            Node* temp = tail;     // Node to delete
            Node* perv = head;
            while(perv->next != tail){
                perv = perv->next; // Find node before tail
            }
            tail = perv;           // Update tail
            tail->next = head;     // Maintain circularity
            temp->next = NULL;     // Detach node
            delete temp;           // Free memory
        }
    }
};

int main() {
    CircularList cl;
    cl.printcl();                  // Print empty list

    cl.insertAtHead(10);           // Insert at head
    cl.insertAtHead(10);
    cl.insertAtHead(20);
    cl.insertAtHead(30);
    cl.insertAtHead(40);
    cl.insertAtHead(50);
    cl.printcl();                  // Print list

    cl.insertAtTail(60);           // Insert at tail
    cl.printcl();                  // Print list

    cl.deleteAtHead();             // Delete head
    cl.printcl();                  // Print list

    cl.deleteAtTail();             // Delete tail
    cl.printcl();                  // Print list

    return 0;
}