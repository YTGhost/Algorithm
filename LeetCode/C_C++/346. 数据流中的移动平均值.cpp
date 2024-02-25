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