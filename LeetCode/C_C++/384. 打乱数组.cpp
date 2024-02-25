class Solution {
public:
    vector<int> nums;
    int len;
    Solution(vector<int>& _nums) {
        nums = _nums;
        len = nums.size();
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> res(nums);
        for(int i = 0; i < len; i++) {
            swap(res[i], res[i + rand() % (len - i)]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */