class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        vector<int> ans(size);
        stack<int> s;
        for(int i = 0; i < size; i++)
        {
            while(!s.empty() && T[i] > T[s.top()])
            {
                int t = s.top();
                s.pop();
                ans[t] = i - t;
            }
            s.push(i);
        }
        return ans;
    }
};