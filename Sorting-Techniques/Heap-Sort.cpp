#include<iostream>
using namespace std;

class heap {
public:
    int size;
    int arr[100];

    heap() {
        size = 0;
        arr[0] = -1;
    }


    void print() {
        for(int i=1;i<=size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    while(size > 1) {
        // step1: swap
        swap(arr[size], arr[1]);
        size--;

        // step2: 1st element to correct pos
        heapify(arr, size, 1);
    }
}


int main() {
    
    int n =  5;
    int arr[n] = {-1, 54, 53, 55, 52, 50};
    // following loop builds a max heap
    for(int i=n/2;i>0;i--) {
        heapify(arr, n, i);
    }

    heapSort(arr, n);


    cout << "Printing the array now" << endl;
    for(int i=1;i<=n;i++) {
        cout << arr[i] << " ";
    } 
    return 0;
}