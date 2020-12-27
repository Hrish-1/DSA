#include<iostream>
using namespace std;
class Queue{
    int front;
    int rear;
    int *arr;
    int capacity;
    public:
    Queue(int size){
        arr = new int[size];
        front = rear = -1;
        this->capacity = size;
    }

    void enqueue(int data){
        if(!isFull()){
            rear = (rear+1) % capacity;
            arr[rear] = data;
        }
        //cout << "rear" << rear << endl;
    }
    void dequeue(){
        if(!isEmpty()){
            front = (front+1) % capacity;
        }else{
            front = rear = -1;
        }
       // cout << "front" << front << endl;
    }
    void display(){
        for(int i = 0; i < capacity; i++){
            cout << arr[i] << " ";
        }
    }
    int Front(){
        if(front == rear){
            cout <<"Queue empty"<<endl;
            return -1;
        } 
        return arr[++front];
    }
    bool isEmpty(){
        return front == rear;
    } 
    bool isFull(){
        return rear == capacity - 1;
    }
};
int main(){
    Queue q(5);

    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.Front();
    //q.display();

    return 0;
}