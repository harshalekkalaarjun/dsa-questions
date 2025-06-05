#include "linkedlist.h"

// Implement Node constructor
Node::Node(int value) {
    data = value;
    next = NULL;
}

// Implement LIST methods (copy from your current code)
LIST::LIST() { head = tail = NULL; }
// ...implement other LIST methods here...
void LIST::pushh_front(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void LIST :: push_back(int val){
    Node *newNode = new Node(val);
    if ( head == NULL){
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
void LIST:: printll(){
    Node *temp = head ;
    while ( temp != NULL){
        cout << temp-> data << "-> ";
        temp = temp->next ;

    }
}

bool LIST::hasCycle() {
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
