class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    MyQueue() {

    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if(stk2.empty()) {
            while(!stk1.empty()) {
                int t = stk1.top();
                stk1.pop();
                stk2.push(t);
            }
        }
        int num = stk2.top();
        stk2.pop();
        return num;
    }
    
    int peek() {
        if(stk2.empty()) {
            while(!stk1.empty()) {
                int t = stk1.top();
                stk1.pop();
                stk2.push(t);
            }
        }
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t = peek();
        s2.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) s2.push(s1.top()), s1.pop();
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int front;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty())  front = x;
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if(!s2.empty()) return s2.top();
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */