class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if(!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        vector<int> right(n, n);
        while(!stk.empty()) stk.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if(!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; i++) {
            res += (long long)arr[i] * (i - left[i]) * (right[i] - i);
            res %= MOD;
        }

        return res;
    }
};