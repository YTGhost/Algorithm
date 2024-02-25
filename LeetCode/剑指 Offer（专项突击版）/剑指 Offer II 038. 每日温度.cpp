class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int idx = stk.top();
                stk.pop();
                res[idx] = i - idx; 
            }
            stk.push(i);
        }
        return res;
    }
};