class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> dataStack;
    stack<int> minStack;
    int mid = INT_MAX;
    MinStack() {

    }
    
    void push(int x) {
        dataStack.push(x);
        if(minStack.empty() || x <= minStack.top()) minStack.push(x);
    }
    
    void pop() {
        if(dataStack.top() == minStack.top()) minStack.pop();
        dataStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int min() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */