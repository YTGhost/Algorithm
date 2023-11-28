class FrontMiddleBackQueue {
public:
    deque<int> left;
    deque<int> right;
    FrontMiddleBackQueue() {

    }

    void balance() {
        if(left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        } else if(left.size() + 1 < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }
    
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if(left.size() == right.size()) {
            right.push_front(val);
        } else {
            left.push_back(val);
        }
    }
    
    void pushBack(int val) {
        right.push_back(val);
        balance();
    }
    
    int popFront() {
        if(right.empty()) {
            return -1;
        }
        int val;
        if(left.empty()) {
            val = right.front();
            right.pop_front();
        } else {
            val = left.front();
            left.pop_front();
        }
        balance();
        return val;
    }
    
    int popMiddle() {
        if(right.empty()) {
            return -1;
        }
        int val;
        if(left.size() == right.size()) {
            val = left.back();
            left.pop_back();
        } else {
            val = right.front();
            right.pop_front();
        }
        return val;
    }
    
    int popBack() {
        if(right.empty()) {
            return -1;
        }
        int val = right.back();
        right.pop_back();
        balance();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */