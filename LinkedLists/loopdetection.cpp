#include<iostream>
using namespace std;
//3-->5-->8-->5-->10-->2-->1
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
    Node* tail;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data){
        Node* node = new Node(data);
        if(head == nullptr){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            tail = node;
        }
    }

    void print(){
        Node* temp = head;
        while(temp){
           cout << temp->data << "->";
           temp = temp->next;
        }
        cout << "null" << endl;
    }
    void removeLoop(Node* node,Node* head){
        Node* ptr1 = node;
        Node* ptr2 = head;
        while(ptr1->next != ptr2->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            //  cout << ptr1->data << endl;
            // cout << ptr2->data << endl;
        }
        cout << ptr1->data << endl;
        cout << ptr2->data << endl;
        ptr1->next = nullptr;
    }
    bool detectLoop(){
        Node* fast = head;
        Node* slow = head;

        while(fast && slow){

            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                removeLoop(slow,head);
                return true;
            }
        }
        return false;
    }
};
int main(){
    LinkedList ll;
    for(int i = 0; i < 12; i += 2){
        ll.insert(i);
    }
    ll.print();
    
    ll.tail->next = ll.head->next;
    //cout << ll.tail->next->data << endl;
    ll.detectLoop();
    ll.print();

    return 0;
}