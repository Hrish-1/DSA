/*
 1. partition the given array into two halves
 2. recursively sort two halves
 3. Merge t
*/
/* 1456   2389*/
/* */
#include<iostream>
#include<vector>
using namespace std;
void Merge(vector<int>& v1,vector<int>& v2,vector<int>& v){
    int i = 0;
    int k = 0;
    int j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]) v.at(k++) = v1.at(i++);
        else v.at(k++) = v2.at(j++);
    }
        while(i < v1.size()){
            v.at(k++) = v1.at(i++);
        }
        while(j < v2.size()){
            v.at(k++) = v2.at(j++);
        }    
}
void MergeSort(vector<int>& v){
       if(v.size() == 1) return;
       int mid = v.size()/2;
       vector<int> left;
       for(int i = 0; i < mid; i++){
           left.push_back(v.at(i));
       }
        vector<int> right;
        for(int i = mid; i < v.size(); i++){
            right.push_back(v.at(i));
        }
        MergeSort(left);
        MergeSort(right);
        Merge(left,right,v);
}
int main(){
    vector<int> vec = {8,7,6,5,4,3,2,1};
    MergeSort(vec);
    for(auto x : vec){
        cout << x << " ";
    }
}