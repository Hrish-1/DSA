/*
    F
    1 2 3 4 5
    R  
*/
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
            //cout << "enqued successfully" <<" "<< rear << endl;
            //rear++;
            if(front == -1){
                ++front;
            }
            arr[++rear] = data;
            //cout << rear << endl;
            //cout << arr[rear] << endl;
        }
        
    }
    int dequeue(){
        // cout << arr[front] << endl;
        // cout << arr[rear] << endl;
        if(!isEmpty()){
            //front++;
            return arr[front++];
        }
    }
    bool isEmpty(){
        return (front == -1 && rear == -1)||(front == rear + 1);
    }
    bool isFull(){
        return rear == size - 1;
    }
    int Front(){
        return arr[front];
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
            //cout << temp << endl;
           // cout << "hey" << endl;
            q2->enqueue(temp);
        }
        q1->reset();
        q1->enqueue(data);
        while(!q2->isEmpty()){
           // cout << "you" << endl;
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