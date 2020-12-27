#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BST{
    Node* root;
    public:
    BST(){
        root = NULL;
    }

    void insert(int data){
        Node *node = new Node(data);
        if(root == NULL){
            root = node;
        }else{
            Node* temp = root;
            Node* prev;
           while(temp){
               if(data > temp->data){
                   prev = temp;
                   temp = temp->right;
               }else{
                   prev = temp;
                   temp = temp->left;
               }
           }
           if(data > prev->data){
               prev->right = node;
           }else{
               prev->left = node;
           }
        }
    }
    void inorder(Node* node){
        if(node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void preorder(Node* node){
        if(node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    // void levelOrder(){
    //     queue<Node*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         Node *node = q.front();
    //         cout << node->data << " ";
    //         q.pop();
    //         if(node->left != NULL)
    //             q.push(node->left);
    //         if(node->right != NULL)
    //             q.push(node->right);
    //     }

    // }
    //using two queues
    void levelOrder(){
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(root);
        while(!q1.empty() || !q2.empty()){
            while(!q1.empty()){
                Node* node = q1.front();
            cout << node -> data << " ";
            q1.pop();

            if(node->left != NULL){
                q2.push(node->left);
            }
            if(node->right != NULL){
                q2.push(node->right);
            }
            }
            cout << endl;
            while(!q2.empty()){
                Node* node = q2.front();
                cout << node -> data << " ";
                q2.pop();
                if(node->left != NULL)
                    q1.push(node->left);
                if(node->right != NULL)
                    q1.push(node->right);
            }
           cout << endl;
        }
    }
    
    //using one queue
    void levelOrder1(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
          int count = q.size();
          while(count--){
              cout << q.front()->data << " ";
              if(q.front()->left)
                q.push(q.front()->left);
              if(q.front()->right)
                q.push(q.front()->right);
              q.pop();
          }
          cout << endl;  
        }
    }
    Node* getRoot(){
        return root;
    }
};
int main(){
    
    BST b;
    b.insert(100);
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(200);
    b.insert(150);
    b.insert(300);

    //100 , 20 , 10 , 30 , 200 , 150 , 300

   // b.inorder(b.getRoot());
    b.levelOrder1();
    return 0;
}