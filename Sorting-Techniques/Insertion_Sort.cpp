#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int>& arr, int n){
    for(int i=1;i<n;i++){
        int curr=arr[i], prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}
void printArray(vector<int> arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr = {101, 4, 45, 3, 1, 74};
    int n = arr.size();
    insertion_sort(arr, n);
    printArray(arr, n);
    return 0;
}