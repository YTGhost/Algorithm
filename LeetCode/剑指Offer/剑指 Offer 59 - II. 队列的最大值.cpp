class MaxQueue {
public:
    queue<int> q;
    deque<int> help;
    MaxQueue() {

    }
    
    int max_value() {
        if(help.empty()){
            return -1;
        }else{
            return help.front();
        }
    }
    
    void push_back(int value) {
        q.push(value);
        while(!help.empty() && value > help.back()){
            help.pop_back();
        }
        help.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())   return -1;
        int front = q.front();
        if(front == help.front()){
            help.pop_front();
        }
        q.pop();
        return front;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */