class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto num : nums) {
            q.push(num);
        }
        vector<int> res;
        while(n) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            res.push_back(b);
            res.push_back(a);
            n -= 2;
        }
        return res;
    }
};