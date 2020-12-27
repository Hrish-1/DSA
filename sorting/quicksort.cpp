/*
                P
        6 5 4 3 2
*/
#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int partition(int *a,int start,int end){

    int pivot = a[end];
    int pIndex = start;
    for(int i = start; i < end; i++){
        if(a[i] < pivot){
            swap(a[i],a[pIndex]);
            pIndex++;
        }
    }
    swap(a[end],a[pIndex]);
    return pIndex;

}
void quickSort(int* a,int start,int end){
    if(start >= end){
        return;
    }
    int pIndex = partition(a,start,end);
    quickSort(a,start,pIndex-1);
    quickSort(a,pIndex+1,end);
}

int main(){
    int arr[] = {8,7,6,5,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

