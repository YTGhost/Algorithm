class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0, j = 0; j < n; j++) {
            if(nums[j] != 0) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};