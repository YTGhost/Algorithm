class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<int> q;
        for(auto num : nums) {
            q.push(num);
        }
        for(int i = 0; i < k; i++) {
            int score = q.top();
            q.pop();
            res += score;
            q.push(ceil(score / 3.0));
        }
        return res;
    }
};