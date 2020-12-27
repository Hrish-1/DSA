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
    int kthlastNode(int k){
        //int i = 0;
        Node* temp = head;
        while(k--){
            temp = temp->next;
        }
        
        Node* temp1 = head;
        while(temp){
            temp = temp->next;
            //cout << temp -> data << endl;    
            temp1 = temp1->next;
        }
        return temp1->data;
    }
};
int main(){
    LinkedList ll;
    for(int i = 4; i < 14; i+=2){
        ll.insert(i);
    }
    ll.print();
    cout <<"kth last Node "<< ll.kthlastNode(2);
    ll.remove();
    ll.print();
    return 0;
}
