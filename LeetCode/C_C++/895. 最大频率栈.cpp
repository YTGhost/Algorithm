class FreqStack {
public:
    unordered_map<int, vector<int>> map;
    unordered_map<int, int> cnts;
    int maxCount;
    FreqStack() {

    }
    
    void push(int val) {
        cnts[val]++;
        map[cnts[val]].push_back(val);
        maxCount = max(maxCount, cnts[val]);
    }
    
    int pop() {
        int n = map[maxCount].size();
        int res = map[maxCount][n - 1];
        map[maxCount].pop_back();
        cnts[res]--;
        if(map[maxCount].size() == 0) maxCount--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */