class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> f = {0, INT_MIN, INT_MIN};
        for(auto num : nums) {
            vector<int> g = f;
            for(int j = 0; j < 3; j++) {
                g[(j + num) % 3] = max(g[(j + num) % 3], f[j] + num);
            }
            f = move(g);
        }
        return f[0];
    }
};