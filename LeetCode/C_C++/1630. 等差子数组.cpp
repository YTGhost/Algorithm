class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> res(m);
        for(int i = 0; i < m; i++) {
            int left = l[i], right = r[i];
            int minV = *min_element(nums.begin() + left, nums.begin() + right + 1);
            int maxV = *max_element(nums.begin() + left, nums.begin() + right + 1);
            if(minV == maxV) {
                res[i] = true;
                continue;
            }
            if((maxV - minV) % (right - left) != 0) {
                res[i] = false;
                continue;
            }
            int d = (maxV - minV) / (right - left);
            bool flag = true;
            vector<bool> hash(right - left + 1, false);
            for(int j = left; j <= right; j++) {
                if ((nums[j] - minV) % d != 0) {
                    flag = false;
                    break;
                }
                int t = (nums[j] - minV) / d;
                if(hash[t]) {
                    flag = false;
                    break;
                }
                hash[t] = true;
            }
            res[i] = flag;
        }
        return res;
    }
};