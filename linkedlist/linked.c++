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
            //Node newNode(val); // dayamic oject  // Remove this line
            if ( head == NULL) {
                head = tail = newNode;return ;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }
        // void push_back(int val){
        //     Node* newNode = new Node(val);
        //     if (head == NULL){
        //         head = tail = newNode;
        //         return;
        //     }
        //     tail->next = newNode;
        //     tail = newNode;
        // }
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
    ll.pushh_front(20);
    ll.pushh_front(30);
    ll.pushh_front(40);
    ll.printll();
    cout << "NULL" << endl; // To indicate the end of the list

    return 0;

}