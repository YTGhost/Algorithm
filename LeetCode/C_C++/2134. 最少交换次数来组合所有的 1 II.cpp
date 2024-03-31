class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(auto num : nums) {
            if(num == 1) {
                k++;
            }
        }
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            if(nums[i] == 0) {
                cnt++;
            }
        }
        int res = cnt;
        for(int i = 0; i < n - 1; i++) {
            if(nums[(k + i) % n] == 0) {
                cnt++;
            }
            if(nums[i] == 0) {
                cnt--;
            }
            res = min(res, cnt);
        }
        return res;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) cnt++;
        }
        int sum = 0;
        for(int i = 0; i < cnt; i++) {
            if(nums[i] == 0) sum++;
        }
        int res = sum;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] == 0) sum--;
            if(nums[(i + cnt - 1) % n] == 0) sum++;
            res = min(res, sum);
        }
        return res;
    }
};