#include<iostream>
using namespace std;
void Merge(int* left,int* right,int* a,int leftCount,int rightCount){
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < leftCount && j < rightCount){
        if(left[i] < right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }
    while(i < leftCount) a[k++] = left[i++];
    while(j < rightCount) a[k++] = right[j++];

    int n = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void MergeSort(int *a,int n){
    if(n < 2) return;
    int mid = n/2;
    int *left = new int[mid];
    for(int i = 0; i < mid; i++){
        left[i] = a[i];
    }
    int * right = new int[n-mid];
    for(int i = mid; i < n; i++){
        right[i-mid] = a[i];
    }
    MergeSort(left,mid);
    MergeSort(right,n-mid);
    Merge(left,right,a,mid,n-mid);

    free(left);
    free(right);
}
int main(){

    int arr[] = {5,3,2,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}