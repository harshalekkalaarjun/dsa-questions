// linkdelist is a linked list implementation in C++.
#include <iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* next ;

        Node(int value ){
            data = value;
            next = NULL;

        }
};

class LIST{
    private:
        Node *head;
        Node *tail;
    public:
        LIST(){head = tail = NULL;}
        void  pushh_front(int val){
            Node* newNode = new Node(val);
            Node newNode(val); // dayamic oject
            if ( head == NULL) {
                head = tail = newNode;return ;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }
        void push_back(int val){
            Node* newNdoe = new Node(val);
        }
        void printll(){
            Node *temp = head;
            while (temp != NULL){
                cout << temp->data<< " -> ";
                temp = temp->next;
            }
        }

 


};


int main(){
    LIST ll;
    ll.pushh_front(10);

    return 0;

}