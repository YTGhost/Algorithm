class MovingAverage {
public:
    /** Initialize your data structure here. */
    int n;
    int sum;
    queue<int> q;
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }
    
    double next(int val) {
        if(q.size() < n) {
            sum += val;
            q.push(val);
        } else {
            int t = q.front();
            sum -= t;
            q.pop();
            q.push(val);
            sum += val;
        }
        return sum * 1.0 / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector<int> window;
    double sum;
    int idx, size;
    MovingAverage(int _size) {
        window = vector<int>(_size, 0);
        sum = 0, idx = 0, size = _size;
    }
    
    double next(int val) {
        idx++;
        sum += val;
        int pos = (idx - 1) % size;
        if(idx > size) {
            sum -= window[pos];
        }
        window[pos] = val;
        return sum / (idx > size ? size : idx);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */