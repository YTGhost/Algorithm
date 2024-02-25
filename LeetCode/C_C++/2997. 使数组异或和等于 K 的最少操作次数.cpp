class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = nums[0];
        for(int i = 1; i < n; i++) {
            sum ^= nums[i];
        }
        int cnt = 0;
        while(k && sum) {
            if((k & 1) != (sum & 1)) {
                cnt++;
            }
            k >>= 1;
            sum >>= 1;
        }
        while(k) {
            if(k & 1) cnt++;
            k >>= 1;
        }
        while(sum) {
            if(sum & 1) cnt++;
            sum >>= 1;
        }
        return cnt;
    }
};