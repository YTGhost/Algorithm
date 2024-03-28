class Solution {
public:
    int encrypt(int num) {
        int cnt = 0, maxVal = 0, res = 0;
        while(num) {
            int x = num % 10;
            num /= 10;
            maxVal = max(maxVal, x);
            cnt++;
        }
        for(int i = 0; i < cnt; i++) {
            res += maxVal;
            res *= 10;
        }
        res /= 10;
        return res;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto num : nums) {
            sum += encrypt(num);
        }
        return sum;
    }
};