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

    void print(Node* head){
        Node* temp = head;
        while(temp){
           cout << temp->data << "->";
           temp = temp->next;
        }
        cout << "null" << endl;
    }

    // Node* Partition(int data){
    //     Node* temp = head;
    //     //Node* curr = nullptr;
    //     Node* newHead = nullptr;
    //     Node* newTail = nullptr;
    //     Node* headInitial = nullptr;
    //     Node* tailInitial = nullptr; 
    //     while(temp){
    //        Node* curr = temp->next;
    //        //cout << temp->data << endl;
    //         if(curr->data < data){
    //             if(newHead == nullptr){
    //                     newHead = curr;
    //                    headInitial = newHead;
    //                    //continue;
    //             }
    //            newHead->next = curr;
    //                newHead = curr;
    //         }else{
    //             if(newTail == nullptr){
    //                 newTail = curr;
    //                 tailInitial = newTail;
    //                 //continue;
    //             }  
    //             newTail->next = curr;
    //             newTail = curr; 
    //             cout << newTail->data << " ";
    //         }
    //         temp = curr;
    //     }
    //     headInitial->next = tailInitial;
    //     newTail->next = nullptr;
    //     cout << headInitial->data;
    //     return headInitial;
    // }
    Node * Partition( int x ) {
   Node * newhead = nullptr;
   Node * headInitial = nullptr;   /*The initial node of list head*/
   Node * newtail = nullptr;
   Node * tailInitial = nullptr;   /*The initial node of list tail*/
   Node * curr = head;
   while( curr != nullptr ) {
     Node * nextNode = curr->next;
     if ( curr->data < x ) {
            if (newhead == nullptr) {
                newhead = curr;
                headInitial = newhead;
            }
       //insert curr node to head list
       newhead->next = curr;
       newhead = curr;
     } else {
            if (newtail == nullptr) {
                newtail = curr;
                tailInitial = newtail;
            }
       // insert curr node to tail list
       newtail->next = curr;
       newtail = curr;
     }
     curr = nextNode;
   }
   newhead->next = tailInitial;  /*Now, we connect the head list to tail list.*/
   newtail->next = nullptr;
   return headInitial;
 }

};
int main(){

    LinkedList ll;

        ll.insert(5);
        ll.insert(8);
        ll.insert(7);
        ll.insert(4);
        ll.insert(8);
        ll.insert(1);
        ll.insert(3);
        ll.insert(0);
        ll.insert(7);

    ll.print(ll.head);
    Node* res = ll.Partition(7);
    ll.print(res);
    
    return 0;
}