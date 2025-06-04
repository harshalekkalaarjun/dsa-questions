// linkdelist is a linked list implementation in C++.
#include <iostream>
using namespace std;

 // Node class definition
class Node {
    public:
        int data; // Data to be stored in the node
        // Pointer to the next node in the list
        Node* next ;

        Node(int value ){ // Constructor to initialize the node with a value
            // Initialize the data and next pointer
            // this->data = value; // This line is not needed, as data is already initialized
            // Using the member initializer list to initialize data
            // this->next = NULL; // This line is not needed, as next is already initialized
            // Initialize the data and next pointer
            data = value;   // Set the data of the node
            next = NULL;    // Set the next pointer to NULL, indicating the end of the list

        }
};
// Node class definition ends here  
// The LIST class is a linked list implementation
class LIST{     // LIST class definition
    private: // Private members of the LIST class
        Node *head; // Pointer to the head of the linked list
        Node *tail;  // Pointer to the tail of the linked list
    // Public members of the LIST class
    public:
        LIST(){head = tail = NULL;} // Constructor to initialize the linked list with head and tail as NULL
        // Destructor to clean up the linked list
        void  pushh_front(int val){ // Function to insert a new node at the front of the linked list
            // Create a new node with the given value

            Node* newNode = new Node(val);
            //Node newNode(val); // dayamic oject  // Remove this line
            if ( head == NULL) { // If the list is empty, set both head and tail to the new node
                // If the list is empty, set both head and tail to the new node
                head = tail = newNode;
                return ;  
            } else {
                newNode->next = head; // Set the next pointer of the new node to the current head
                head = newNode; // Update the head to point to the new node
                // If the list is not empty, insert the new node at the front
            }
        }
        void push_back(int val){ // Function to insert a new node at the back of the linked list
            // Create a new node with the given value
            Node* newNode = new Node(val);
            if (head == NULL){ // If the list is empty, set both head and tail to the new node
                // If the list is empty, set both head and tail to the new node
                head = tail= NULL;
            }else { // If the list is not empty, insert the new node at the back
                // Set the next pointer of the current tail to the new node
                tail ->next = newNode;
                tail = newNode;
            }
        }
        void printll(){ // Function to print the linked list
            Node *temp = head; // Temporary pointer to traverse the list
            while (temp != NULL){ // While there are nodes to traverse
                // Print the data of the current node
                cout << temp->data<< " -> "; // Print the data of the current node
                // Move to the next node
                temp = temp->next;  // Update temp to point to the next node

                // To indicate the end of the list
            }
            cout << "NULL" << endl; // Print NULL to indicate the end of the list
        }
        void pop_front(){ // Function to remove the node at the front of the linked list
            // Check if the list is empty
            if (head == NULL){
                cout << "List is empty, nothing to pop." << endl;
                return;
            }
            Node *temp = head; // Temporary pointer to the current head
            head = head->next; // Update head to point to the next node
            temp->next = NULL; // Clear the next pointer of the popped node
            delete temp; // Free the memory of the popped node
            
        }
        void pop_back(){ // Function to remove the node at the back of the linked list
            if (head == NULL) { // Check if the list is empty
                cout << "List is empty, nothing to pop." << endl;// If the list is empty, print a message and return
                return;
            }
            Node* temp = head; // Temporary pointer to traverse the list
            while (temp->next != tail) // Traverse the list until the second last node
            {
                temp = temp-> next; // Move to the next node
            }
            temp->next = NULL ; // clear the next ponter of the secomd last node 
            delete tail; // Free the memory of the last node
            tail = temp; // Update the tail to the second last node
            if (tail == NULL) { // If the list becomes empty
                head = NULL; // Set head to NULL as well
            }
            return;
        }
        void insert_inmiddel (int val , int pos){
            if ( pos< 0 ){
                cout << "Invalid position" << endl; // If the position is invalid, print a message
                return;
            }
            if (pos == 0){
                pushh_front(val); // If the position is 0, insert at the back
                return;
            }
            if (head == NULL) {
                cout << "List is empty, nothing to insert." << endl; // If the list is empty, print a message
                return;
            }

            Node* temp = head; // Temporary pointer to traverse the list
            for ( int i = 0; i < pos -1 ; i ++ ){
                if(temp == NULL) { // If the position is out of bounds, print a message
                    cout << "Position out of bounds" << endl;
                    return;
                }
                temp = temp->next; // Move to the next node
            }
            Node *newNode = new Node(val); // Create a new node with the given value
            newNode->next = temp->next; // Set the next pointer of the new node to the next node of temp
            temp->next = newNode; // Set the next pointer of temp to the new node 
        }
        void searchbyvalue(int val){ // Function to search for a value in the linked list
            if (head == NULL) { // Check if the list is empty
                cout << "List is empty, nothing to search." << endl; // If the list is empty, print a message
                return;
            }
            Node* temp = head; // Temporary pointer to traverse the list
            int index = 0; // Initialize an index to keep track of the position
            while ( temp != NULL){ // While there are nodes to traverse
                index++; // Increment the index for each node
                if ( temp->data == val){ // If the current node's data matches the value to search
                    cout << " value foound at index " << index << endl;  // If the value is found, print the index
                    return; // Return from the function}
            }
        }
        void searchbyindex(int index){  // function is to search for a valuse based on the index 
            if (head == NULL) { // Check if the list is empty
                cout << "List is empty, nothing to search." << endl; // If the list is empty, print a message
                return;
            }
              Node* temp = head;
            int currentIndex = 0; // Initialize a variable to keep track of the current index
            while (temp  != NULL)
            {
                if (currentIndex == index) { // If the current index matches the given index
                    cout << "Value at index " << index << " is: " << temp->data << endl; // Print the value at the given index
                    return; // Return from the function
                }
                temp = temp->next; // Move to the next node
                currentIndex++; // Increment the current index
            }   
            
        };


};

// Main function to demonstrate the linked list operations
int main(){
    LIST ll;
    ll.pushh_front(10);
    ll.pushh_front(20);
    ll.pushh_front(30);
    ll.pushh_front(40);
    ll.printll();
    printf("\n");
    ll.push_back(50);
    ll.printll();
    printf("\n");
    ll.pop_front();
    ll.printll();
    ll.pop_back();
    ll.printll();
    ll.insert_inmiddel(60, 2);
    ll.printll();
    ll.insert_inmiddel(70, 0);
    ll.printll();


    return 0;

}