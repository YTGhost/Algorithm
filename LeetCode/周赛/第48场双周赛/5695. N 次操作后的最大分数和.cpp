// 状压dp
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a%b) : a;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(1 << n);
        for(int i = 0; i < 1 << n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
                if(!(i >> j & 1)) cnt++;
            cnt = cnt / 2 + 1;
            for(int j = 0; j < n-1; j++)
                if(i >> j & 1)
                    for(int k = j+1; k < n; k++)
                        if(i >> k & 1)
                            f[i] = max(f[i], f[i - (1 << j) - (1 << k)] + gcd(nums[j], nums[k]) * cnt);
        }
        return f[(1 << n) - 1];
    }
};