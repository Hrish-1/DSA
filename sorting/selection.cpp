#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {6,5,4,3,2,1};
    //1.find the minimum element
    for(int i = 0; i < v.size(); i++){
        int min = i;
        for(int j = i+1; j < v.size(); j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
    for(auto x : v){
        cout << x << " "; 
    }
}