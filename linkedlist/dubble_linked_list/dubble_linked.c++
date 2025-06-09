#include <iostream>
using namespace std;



class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int value) {
            data = value;
            next = nullptr; // Initialize the next pointer to NULL
            prev = nullptr; // Initialize the previous pointer to NULL
        }
};

class DubbeleLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
    DubbeleLinkedList() {head = tail = nullptr;}
    void push_front(int val ){
        Node* newNode = new Node(val);
    if (head ==NULL){
        head =  tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode; // Set the previous pointer of the current head
        head = newNode; // Update the head to the new node

    }    
}


void push_back(int val){
    Node* newNode = new Node(val);
    if ( head == NULL){
        head = tail =  newNode;
    }else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;

    }

}
void printll(){
    Node* temp = head ;
    while (temp != NULL){
    cout << temp-> data << " <=> ";
    temp = temp->next;

    }
    cout << " NULL \n" ;   
}
void pop_front(){
    if ( head == NULL){
        cout << " list is empty, nothing to pop" << endl;
    }
    Node* temp = head ;
    head = head->next;
    if (head != NULL){
    head-> prev = NULL;
    }


    temp->next = NULL;
    delete temp; 
}
void pop_back(){
    if(head ==  NULL ){
         cout << " list is empty, nothing to pop" << endl;
    }
    Node* temp = tail;
    tail = tail->prev;
    if ( tail != NULL){
        tail-> next = NULL;
    }
    temp-> prev = NULL;
    delete temp;
}
};



int main(){
    DubbeleLinkedList dl ;
    dl.push_front(10);
    dl.printll();
    dl.push_front(10);
    dl.printll();
    dl.push_back(30);
    dl.printll();
    dl.pop_front();
    dl.printll();
    dl.pop_front();
    dl.printll();
    dl.push_front(10);
    dl.push_front(10);
    dl.printll();
    dl.push_back(40);
        dl.printll();
    dl.pop_back();
    dl.printll();
    





}