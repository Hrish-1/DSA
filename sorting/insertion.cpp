#include<iostream>
using namespace std;
void InsertionSort(int *a,int n){
        for(int i = 1; i < n; i++){
            int curr = a[i];
            int prev = i - 1;
            while(prev >= 0 && curr < a[prev]){
                a[prev+1] = a[prev];
                prev--;
            }
            a[prev+1] = curr;

        }
}
int main(){
    int arr[] = {9,5,1,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr,n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}