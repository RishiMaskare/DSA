#include<iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int>& arr, int n){
    for(int i=0;i<n-1;i++){
        int si = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[si]){
                si = j;
            }
        }
        swap(arr[i], arr[si]);
    }
}
void printArray(vector<int> arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr = {41, 89, 3, 36, 47, 69, 64};
    int n = arr.size();
    selection_sort(arr, n);
    printArray(arr, n);
    return 0;
}