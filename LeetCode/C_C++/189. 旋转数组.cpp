class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        function<void(int, int)> reverse = [&](int l, int r) {
            while(l < r) {
                swap(nums[l++], nums[r--]);
            }
        };
        reverse(0, n - 1);
        reverse(0, k % n - 1);
        reverse(k % n, n - 1);
    }
};

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while(start < end) swap(nums[start++], nums[end--]);
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};