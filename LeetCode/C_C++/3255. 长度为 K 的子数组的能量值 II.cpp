class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt = i == 0 || nums[i] == nums[i - 1] + 1 ? cnt + 1 : 1;
            if (cnt >= k) {
                res[i - k + 1] = nums[i];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        int l = 0, r = 1;
        while (l < n - k + 1) {
            bool flag = nums[r] - 1 == nums[r - 1];
            if (r - l + 1 == k) {
                if (flag) {
                    res[l] = nums[r];
                    l++, r++;
                } else {
                    l = r;
                    r = l + 1;
                }
            } else {
                if (flag) {
                    r++;
                } else {
                    l++;
                    r = l + 1;
                }
            }
        }
        return res;
    }
};