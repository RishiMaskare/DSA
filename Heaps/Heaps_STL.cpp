#include<iostream>
#include<queue>
using namespace std;

int main() {
    // by default priority_queue is maxHeap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(4);
    pq.push(1);
    pq.push(9);
    pq.push(7);
    pq.push(4);
    cout << "Max Element (Top) : " << pq.top() << endl; // 9
    pq.pop();
    cout << "Max Element (Top) : " << pq.top() << endl; // 7
    if(pq.empty()) {
        cout << "MaxHeap is empty!" << endl;
    } else {
        cout << "MaxHeap is not empty!" << endl;
    }
    cout << "Printing all elements of MaxHeap : ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    

    // for minHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(9);
    minHeap.push(4);
    minHeap.push(7);
    minHeap.push(2);
    minHeap.push(6);
    cout << "Min Element (Top) : " << minHeap.top() << endl; 
    minHeap.pop();
    cout << "Min Element (Top) : " << minHeap.top() << endl; 
    if(minHeap.empty()) {
        cout << "MinHeap is empty!" << endl;
    } else {
        cout << "MinHeap is not empty!" << endl;
    }
    cout << "Printing all elements of MinHeap : ";
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}