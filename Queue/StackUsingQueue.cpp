#include<iostream>
using namespace std;
class Queue{
    int front;
    int rear;
    int* arr;
    int size;

    public:
    Queue(int size){
        this->size = size;
        rear = -1;
        front = -1;
        arr = new int[size];
    }
    void enqueue(int data){
        
        if(!isFull()){
            arr[++rear] = data;
        }
        
    }
    int dequeue(){
        if(!isEmpty()){
            front++;
            return arr[front];
        }
    }
    bool isEmpty(){
        return front == rear;
    }
    bool isFull(){
        return rear == size - 1;
    }
    int Front(){
        return arr[++front];
    }
    void display(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void reset(){
        front = rear = -1;
    }
};

class Stack{

    Queue *q1;
    Queue *q2;
    public:
    Stack(int size){
        q1 = new Queue(size);
        q2 = new Queue(size);
    }

    void Push(int data){
        while(!q1->isEmpty()){
            int temp = q1->dequeue();
            q2->enqueue(temp);                   
        }
        q1->reset();
        q1->enqueue(data);
        while(!q2->isEmpty()){
            q1->enqueue(q2->dequeue());
        }
        q2->reset();
    }

    int pop(){
        return q1->dequeue();
    }

    int peek(){
        return q1->Front();
    }

    void show(){
        q1->display();
    }

};

int main(){
   Stack s(5);

   s.Push(1);
    s.Push(2);
   s.Push(3);
    s.Push(4);
   s.Push(7);
   //s.Push(8);
    s.pop();
    s.pop();
//    s.pop();
    //s.show();
    cout << s.peek();
    //cout << s.pop();


}