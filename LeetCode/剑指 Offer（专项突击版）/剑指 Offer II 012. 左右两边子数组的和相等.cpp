class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), total = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            total += nums[i];
        }
        for(int i = 0; i < n; i++) {
            if(2 * sum + nums[i] == total) return i;
            sum += nums[i];
        }
        return -1;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), res = -1;
        vector<int> pre1(n), pre2(n);
        for(int i = 1; i < n; i++) {
            pre1[i] += pre1[i - 1] + nums[i - 1];
        }
        for(int i = n - 2; i >= 0; i--) {
            pre2[i] += pre2[i + 1] + nums[i + 1];
        }
        for(int i = 0; i < n; i++) {
            if(pre1[i] == pre2[i]) {
                res = i;
                break;
            }
        }
        return res;
    }
};