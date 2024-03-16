class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), l, r;
        for(l = n - 2; l >= 0; l--) {
            if(nums[l] < nums[l + 1]) {
                break;
            }
        }
        if(l == -1) {
            sort(nums.begin(), nums.end());
        } else {
            for(r = n - 1; r >= 0; r--) {
                if(nums[r] > nums[l]) {
                    swap(nums[l], nums[r]);
                    sort(nums.begin() + l + 1, nums.end());
                    break;
                }
            }
        }
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};