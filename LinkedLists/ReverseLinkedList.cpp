#include<iostream>
using namespace std;
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

    LinkedList(){
        head = nullptr;
    }
    void insert(int data){
        Node* node = new Node(data);
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
    void Reverse(){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
   
};
int main(){

    LinkedList l;
    for(int i = 0; i < 9 ; i += 2){
        l.insert(i);
    }

    l.print();
    l.Reverse();
    l.print();
    
}
