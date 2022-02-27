class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if(q.size() < k) {
            q.push(val);
        } else if(q.size() == k && q.top() < val) {
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */