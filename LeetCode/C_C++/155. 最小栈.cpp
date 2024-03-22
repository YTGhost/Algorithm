class MinStack {
public:
    stack<int> stk1;
    stack<int> stk2;
    MinStack() {
        stk2.push(INT_MAX);
    }
    
    void push(int val) {
        stk1.push(val);
        stk2.push(min(stk2.top(), val));
    }
    
    void pop() {
        stk1.pop();
        stk2.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};

class MinStack {
public:
    stack<int> data;
    stack<int> min;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);
        if(min.empty() || x <= min.top())    min.push(x);
    }
    
    void pop() {
        if(data.top() == min.top()) min.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */