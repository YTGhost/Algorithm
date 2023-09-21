class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    MedianFinder() {
    }
    
    void addNum(int num) {
        int s1 = maxq.size(), s2 = minq.size();
        if(s1 == s2) {
            if(s2 == 0 || num <= minq.top()) {
                maxq.push(num);
            } else {
                maxq.push(minq.top());
                minq.pop();
                minq.push(num);
            }
        } else {
            if(maxq.top() <= num) {
                minq.push(num);
            } else {
                minq.push(maxq.top());
                maxq.pop();
                maxq.push(num);
            }
        }
    }
    
    double findMedian() {
        int s1 = maxq.size(), s2 = minq.size();
        return s1 == s2 ? (maxq.top() + minq.top()) / 2.0 : maxq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */