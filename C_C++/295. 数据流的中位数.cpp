class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> down;
    priority_queue<int, vector<int>, greater<int>> up;
    MedianFinder() {

    }

    void adjust() {
        while(up.size() > down.size()) {
            down.push(up.top());
            up.pop();
        }
        while(down.size() > up.size() + 1) {
            up.push(down.top());
            down.pop();
        }
    }
    
    void addNum(int num) {
        if(up.empty() || num < up.top()) down.push(num);
        else up.push(num);
        adjust();
    }
    
    double findMedian() {
        if(up.size() == down.size()) return (up.top() + down.top()) / 2.0;
        else return down.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */