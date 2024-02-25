class Solution {
public:
    int magicTower(vector<int>& nums) {
        long total = accumulate(nums.begin(), nums.end(), 1L);
        if(total <= 0) return -1;
        priority_queue<int, vector<int>, greater<int>> q;
        long sum = 1, cnt = 0;
        for(auto num : nums) {
            sum += num;
            if(num < 0) {
                q.push(num);
                while(sum <= 0 && q.size()) {
                    sum -= q.top();
                    q.pop();
                    cnt++;
                }
            }
        }
        return cnt;
    }
};