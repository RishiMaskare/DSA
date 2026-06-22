/*
========================================================
Problem: Implement Max Heap
========================================================

Intuition:
Parent node must always be greater than
its children.

--------------------------------------------------------
Approach:
1. Insert:
      Add element at end.
      Heapify upwards.

2. Extract Max:
      Replace root with last element.
      Heapify downwards.

3. Change Key:
      Heapify up or down based on value.

--------------------------------------------------------
Time Complexity:

Insert      : O(log N)
Extract Max : O(log N)
Change Key  : O(log N)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution{
    
    vector<int> heap;
    
    void heapifyUp(int i){
        while(i > 0){
            int parent = (i - 1) / 2;
            
            if(heap[parent] < heap[i]){
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else{
                break;
            }
        }
    }
    
    void heapifyDown(int i){
        int n = heap.size();
        
        while(true){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;
            
            if(left < n && heap[left] > heap[largest])
                largest = left;
                
            // Prefer LEFT child when equal
            if(right < n){
                if(heap[right] > heap[largest])
                    largest = right;
            }
            
            if(largest == i)
                break;
                
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:

    void initializeHeap(){
        heap.clear();
    }

    void insert(int key){
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void changeKey(int index, int new_val){
        int old_val = heap[index];
        heap[index] = new_val;
        
        if(new_val > old_val)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    void extractMax(){
        if(heap.empty())
            return;
            
        heap[0] = heap.back();
        heap.pop_back();
        
        if(!heap.empty())
            heapifyDown(0);
    }

    bool isEmpty(){
        return heap.empty();
    }

    int getMax(){
        return heap[0];
    }

    int heapSize(){
        return heap.size();
    }
};

// Striver SDE Sheet Challenge - Day 20
