class NumArray {
public:
    vector<int> nums;
    vector<int> tree;
    int n;
    int lowbit(int x) {
        return x & -x;
    }
    int query(int x) {
        int res = 0;
        for(int i = x; i > 0; i -= lowbit(i)) {
            res += tree[i];
        }
        return res;
    }
    void add(int x, int u) {
        for(int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        tree = vector<int>(n + 1);
        for(int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int l, int r) {
        return query(r + 1) - query(l);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */