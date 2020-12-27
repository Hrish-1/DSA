#include<iostream>
using namespace std;

static int count = 0;

class Node{
    public :
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};
class LinkedList{
    
    public : 
    Node* head;
    Node* test;

    LinkedList(){
        head = nullptr;
    }
    void insert(int data){
        count++;
        Node* node = new Node(data);
        if(count == 4) test = node;
        node->next = head;
        head = node;
    }

    void remove(){
        Node* temp;
        while(head){
            temp = head;
            head = temp->next;
            delete(temp); 
        }
    }
    void print(){
        Node* temp = head;
        while(temp){
            cout << temp-> data << " - >";
            temp = temp->next;
        }
        cout << endl;
    }
    // void deleteMiddleNode(int data){
    //     Node* temp = head;
    //     Node* prev;
    //     while(temp){
    //         if(temp->data == data){
    //             prev->next = temp->next;
    //             free(temp);
    //             break;
    //         }
    //         prev = temp;
    //         temp = temp->next; 
    //     }
    // }
        void deleteMiddleNode(Node* v){
            if(v == nullptr || v->next == nullptr) return;
            Node* nextNode = v->next;
            v->data = nextNode->data;
            v->next = nextNode->next;
            delete nextNode;
        }
};
int main(){
    LinkedList ll;
   
    for(int i = 4; i < 14; i += 2){
       
        ll.insert(i);
    }
    ll.print();
    ll.deleteMiddleNode(ll.test);
    ll.print();
    ll.remove();
    ll.print();
}