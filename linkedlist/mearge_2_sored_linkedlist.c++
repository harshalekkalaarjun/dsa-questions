// merge 2 sorted linked lists
// leetcode 21
// https://leetcode.com/problems/merge-two-sorted-lists/
// Given the heads of two sorted linked lists, merge them into one sorted list. The list should be made by splicing together the nodes of the first two lists.
#include <iostream>
using namespace std;
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
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
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
    LIST merge_2_sorted_linked_lists(LIST& list1, LIST& list2) {
        LIST mergedList;
        Node* head1 = list1.head;
        Node* head2 = list2.head;
        
        // Determine the head of the merged list
        if (!head1) return list2;
        if (!head2) return list1;

        Node* mergedHead = nullptr;
        if (head1->data < head2->data) {
            mergedHead = head1;
            head1 = head1->next;
        } else {
            mergedHead = head2;
            head2 = head2->next;
        }
        mergedList.head = mergedHead;
        mergedList.tail = mergedHead;

        // Merge the remaining nodes
        while (head1 && head2) {
            if (head1->data < head2->data) {
                mergedList.tail->next = head1;
                head1 = head1->next;
            } else {
                mergedList.tail->next = head2;
                head2 = head2->next;
            }
            mergedList.tail = mergedList.tail->next;
        }

        // Append the remaining nodes from either list
        if (head1) {
            mergedList.tail->next = head1;
        } else {
            mergedList.tail->next = head2;
        }
        // Ensure the tail's next pointer is set to NULL
        mergedList.tail->next = nullptr;
        // Return the merged list

        return mergedList;
    }


    LIST merge_2_sorted_linked_list_recursive(LIST& l1, LIST& l2) {
        // Helper function to merge two sorted linked lists recursively
        LIST mergedList;
        mergedList.head = merge_2_sorted_linked_list_recursive(l1.head, l2.head);

        // Set tail
        Node* temp = mergedList.head;
        mergedList.tail = nullptr;
        while (temp && temp->next) {
            temp = temp->next;
        }
        mergedList.tail = temp;
        return mergedList;
    }
};
int main (){
    LIST ll ;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);

    cout << "Linked List after inserting elements at the back: ";
    printf("\n");
    ll.printll();
    printf("\n");

    LIST ll2;
    ll2.push_back(5);  
    ll2.push_back(15);
    ll2.push_back(25);
    ll2.push_back(35);
    ll2.push_back(45);

    cout << "Second Linked List after inserting elements at the back: ";
    printf("\n");
    ll2.printll();
    printf("\n");

    cout << "Merged Linked List: ";
    printf("\n");
    LIST mergedList = ll.merge_2_sorted_linked_lists(ll, ll2);
    mergedList.printll();
    printf("\n");
    cout << "Merged Linked List using recursive function: ";
    printf("\n");
    LIST mergedListRecursive = ll.merge_2_sorted_linked_list_recursive(ll.head, ll2.head);
    mergedListRecursive.printll();
    printf("\n");
    return 0;
}