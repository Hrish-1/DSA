#include<iostream>
#include<vector>
using namespace std;
void copyVec(vector<int>& v){
    vector<int> x = {4,5,6,7,8};
    int i = 0;
    int j = 0;
    while(i < x.size()){
        v.at(i++) = x.at(j++);
    }
}
int main(){
    vector<int> v = {1,2,3,4,5};
    copyVec(v);

    for(auto x : v){
        cout << x << " ";
    }
}