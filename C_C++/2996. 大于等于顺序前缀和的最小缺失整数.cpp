class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int resSum = nums[0];
        int sum = nums[0];
        int maxCnt = 1;
        int cnt = 1;
        s.insert(nums[0]);
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] + 1) {
                cnt++;
                sum += nums[i];
                if(cnt > maxCnt) {
                    maxCnt = cnt;
                    resSum = sum;
                }
            } else {
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        while(s.count(resSum)) {
            resSum++;
        }
        return resSum;
    }
};