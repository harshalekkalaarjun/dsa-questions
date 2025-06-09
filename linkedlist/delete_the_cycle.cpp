


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL; // Initialize the next pointer to NULL
    }
};

class LIST {
private:
    Node* head;
    Node* tail;
public: 
    LIST() {
        head = tail = NULL;
    }

    void pushh_front(int val) { // Function to insert a new node at the front of the linked list
        Node* newNode = new Node(val); // Initialize a new node
        if (head == NULL) {
            head = tail = newNode; // If the list is empty, set both head and tail to the new node
            return;
        } else {
            newNode->next = head; // Set the next pointer of the new node to the current head
            head = newNode; // Update the head to point to the new node 
        }
    }
        void printll(){ // Function to print the linked list
            Node* temp = head; // Temporary pointer to traverse the list
            while (temp != NULL ) {
                cout << temp->data << " -> "; // Print the data of the current node
                temp = temp->next; // Move to the next node
            }
            cout << "NULL" << endl;

    }
    bool hasCycle() { // Function to check if the linked list has a cycle
        if (head == NULL) return false; // If the list is empty, return false
        Node* slow = head; // Slow pointer starts at the head
        Node* fast = head; // Fast pointer starts at the head
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next; // Move the fast pointer two steps ahead
            if (slow == fast) { // If the slow and fast pointers meet, there is a cycle
                return true;
            }
        }
        return false; // If no cycle is detected, return false
    }
    void deleteCycle() {
        if (head == NULL) return; // If the list is empty, do nothing
        Node* slow = head;
        Node* fast = head;

        // Detect cycle using Floyd's Tortoise and Hare algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Cycle detected
                break;
            }
        }

        // If no cycle was found
        if (fast == NULL || fast->next == NULL) {
            return;
        }

        // Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Find the last node in the cycle and break it
        Node* cycleStart = slow;
        while (fast->next != cycleStart) {
            fast = fast->next;
        }
        fast->next = NULL; // Break the cycle
        return; // Cycle deleted
        
        
    }
    // void print_cycle_list(){


    // }
    void create_cycle(int pos){
        if ( head == NULL || pos < 0) return; // If the list is empty or position is invalid
        Node* temp = head;
        int count = 0;
        while (temp->next != NULL && count< pos){
            temp = temp->next;
            count++;

        }
        if (count == pos) {
            tail->next = temp; // Create a cycle by linking the tail to the node at position 'pos'
        }
    }
};


int main() {
    LIST ll; // Create a linked list object

    // Insert elements at the front
    ll.pushh_front(10);
    ll.pushh_front(20);
    ll.pushh_front(30);
    ll.pushh_front(40);
    ll.pushh_front(50);
    // Print the linked list after inserting at the front
    cout << "Linked List after inserting elements at the front: ";
    printf("\n");
    // Print the linked list
    ll.printll();
    printf("\n");   
    ll.create_cycle(2); // Create a cycle for testing
    // Print the linked list after creating a cycle
    cout << "Linked List after creating a cycle: ";
    // ll.printll();
    // printf("\n");
    // Check for cycle

    if (ll.hasCycle()) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }
    // Delete the cycle if it exists
    ll.deleteCycle();
    cout << "Linked List after deleting the cycle: ";
    ll.printll();
    printf("\n");
    // Check again for cycle after deletion
    if (ll.hasCycle()) {
        cout << "Cycle still exists in the linked list after deletion." << endl;
    } else {
        cout << "No cycle detected in the linked list after deletion." << endl;
    }
    // Return success
    return 0; // Return success
}