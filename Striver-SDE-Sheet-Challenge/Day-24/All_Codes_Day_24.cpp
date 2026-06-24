// Implement stack using array

class myStack {
  public:
    int sz = 0;
    vector<int> stack;
    myStack(int n) {
        // Define Data Structures
        sz = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        return stack.size() == 0;
    }

    bool isFull() {
        // check if the stack is full
        return stack.size() == sz;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(!isFull()) {
            stack.push_back(x);
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(!isEmpty()) {
            stack.pop_back();
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(!isEmpty()) {
            return stack[stack.size() - 1];
        }
        return -1;
    }
};

// Queue Using Array
class myQueue {
  public:
    vector<int> q;
    int sz = 0;
    myQueue(int n) {
        // Define Data Structures
        sz = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return q.size() == 0;
    }

    bool isFull() {
        // check if the queue is full
        return q.size() == sz;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(!isFull()) {
            q.push_back(x);
        }
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(!isEmpty()) {
            q.erase(q.begin());
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        if(!isEmpty()) {
            return q.front();
        }
        return -1;
    }

    int getRear() {
        // Return the last element of queue
        if(!isEmpty()) {
            return q.back();
        }
        return -1;
    }
};

// Stack using Queue

class myStack {
    queue<int> q;

  public:

    void push(int x) {
        // Inserts an element x at the top of the stack
        q.push(x);
        
        int n = q.size();
        for(int i=0;i<n-1;i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        // Removes an element from the top of the stack
        if(!q.empty()) q.pop();
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(!q.empty()) return q.front();
        return -1;
    }

    int size() {
        // Returns the current size of the stack
        return q.size();
    }
};


// Queue using Stack

class myQueue {
    
  stack<int> st;
  public:
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        // Implement enqueue operation
        vector<int> temp;
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        st.push(x);
        for(int i=temp.size()-1;i>=0;i--) {
            st.push(temp[i]);
        }
    }

    void dequeue() {
        // Implement dequeue operation
        if(!st.empty()) st.pop();
    }

    int front() {
        // Implement front operation
        if(!st.empty()) return st.top();
        return -1;
    }

    int size() {
        // Implement size operation
        return st.size();
    }
};
