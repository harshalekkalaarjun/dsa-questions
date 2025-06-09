#include<iostream>
#include "linkedlist.h"
using namespace std;

int main() {
    LIST ll; // Create a linked list object

    // Insert elements at the front
    ll.pushh_front(10);
    ll.pushh_front(20);
    ll.pushh_front(30);
    ll.pushh_front(40);
    ll.pushh_front(50);
    // Print the linked list after inserting at the front
    printf("\n");

    // Print the linked list
    cout << "Linked List after inserting elements at the front: ";
    ll.printll();
    printf("\n");
    // Insert elements at the back
    ll.push_back(60);
    ll.push_back(70);
    printf("\n");
    // Print the linked list after inserting at the back
    cout << "Linked List after inserting elements at the back: ";
    ll.printll();
    printf("\n");
    if (ll.hasCycle()) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }
    ll.reversceList();
    cout << "Linked List after reversing: ";    
    ll.printll();
    printf("\n");
    return 0; // Return success
}