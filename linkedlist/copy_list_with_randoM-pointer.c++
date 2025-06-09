// copy list with random pointer
// This code defines a function to copy a linked list with random pointers.
//leetcode problem: https://leetcode.com/problems/copy-list-with-random-pointer/
//         if (!head1 && !head2) return mergedList; // If both lists are empty, return an empty list

#include <unordered_map> 
// leetcpode number: 138
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* random; // Pointer to a random node

    Node(int value) {
        data = value;
        next = nullptr; // Initialize the next pointer to NULL
        random = nullptr; // Initialize the random pointer to NULL
    }
};
class LIST {
private:
    Node* head;
    Node* tail;
public: 
    LIST() {
        head = tail = nullptr;
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printll() { // Function to print the linked list 
        Node* temp = head; // Temporary pointer to traverse the list
        while (temp != nullptr) {
            cout << temp->data << " -> "; // Print the data of the current node
            temp = temp->next; // Move to the next node
        }
        cout << "NULL" << endl;
    }
    Node *getHead() { // Function to get the head of the linked list
        if (head == nullptr) {
            cout << "List is empty" << endl; // If the list is empty, print a message
            return nullptr; // Return nullptr if the list is empty
        }
        return head; // Return the head of the linked list
    }
    Node *copy_list_with_random_pointer(Node* head){

        if ( head == nullptr ) {cout << "head is null" << endl;

    }
    //copy the list into a new list with random pointers
    Node *current = head;
    printf("head node %p\n", head);
    while (current) {
        Node* copy=  new Node(current->data);
        cout<<  "copy value" << copy->data << endl;

        copy->next = current->next; // Set the next pointer of the copied node
        cout << "copy node" << copy->next << endl;
        current->next = copy; // Insert the copied node after the current node
        current = copy->next; // Move to the next node in the original list

         // Return the head of the copied list
    }


    }
    Node* copyRandomList(){
        if (head == NULL ){
            return NULL; // If the head is NULL, return NULL
            
        }
        unordered_map<Node* , Node*> m;
        Node* Newhead = new Node(head->data);
        Node* oldtemp = head->next;
        Node* newtemp = Newhead;
        while (oldtemp)
        {
            Node* copyNdoe = new Node (oldtemp-> data);
            m[oldtemp]=copyNdoe; // Store the mapping of old node to copied node
            newtemp->next = copyNdoe; // Set the next pointer of the copied node
            oldtemp = oldtemp->next;
            newtemp = newtemp->next; // Move to the next node in the copied list
            m[head] = Newhead; // Store the mapping of head node to copied head node

        }
        oldtemp = head; newtemp = Newhead;
        while(oldtemp){
            newtemp->random = m[oldtemp->random]; // Set the random pointer of the copied node
            oldtemp = oldtemp->next; // Move to the next node in the original list
            newtemp = newtemp->next; // Move to the next node in the copied list

        }
        return Newhead; // Return the head of the copied list
        
    }
    LIST create_remdom_pointer_list() {
        LIST newList;
        Node* current = head;
        while (current) {
            Node* copy = new Node(current->data);
            newList.push_back(copy->data);
            current = current->next;
        }
        return newList;
    }


};



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if (!head) return nullptr;

//         // Step 1: Create a copy of each node and insert it next to the original node
//         Node* current = head;
//         while (current) {
//             Node* copyNode = new Node(current->val);
//             copyNode->next = current->next;
//             current->next = copyNode;
//             current = copyNode->next;
//         }

//         // Step 2: Set the random pointers for the copied nodes
//         current = head;
//         while (current) {
//             if (current->random) {
//                 current->next->random = current->random->next;
//             }
//             current = current->next->next;
//         }

//         // Step 3: Separate the copied list from the original list
//         Node* newHead = head->next;
//         Node* newCurrent = newHead;
//         current = head;

//         while (current) {
//             current->next = newCurrent->next; // Restore the original list
//             if (newCurrent->next) {
//                 newCurrent->next = newCurrent->next->next; // Move to the next copied node
//             }
//             current = current->next;
//             newCurrent = newCurrent->next;
//         }

//         return newHead; // Return the head of the copied list
        
//     }
// };
int main (){
    LIST l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    printf("Original Linked List:\n");
    l1.printll();
    // Node* head = l1.getHead();
    // // cout << "head node " << l1.getHead() << endl;
    // Node* copiedList = l1.copy_list_with_random_pointer(l1.getHead());

    // Assuming random pointers are set manually for testing
    Node* newhead = l1.copyRandomList();
    cout << "Copied Linked List with Random Pointers:\n" << newhead << endl;


    
}