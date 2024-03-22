class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> sk;
        for(int i = 0; i < n; i++) {
            while(!sk.empty() && temperatures[i] > temperatures[sk.top()]) {
                res[sk.top()] = i - sk.top();
                sk.pop();
            }
            sk.push(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> sk;
        for(int i = n - 1; i >= 0; i--) {
            while(!sk.empty() && temperatures[i] >= temperatures[sk.top()]) {
                sk.pop();
            }
            if(!sk.empty()) {
                res[i] = sk.top() - i;
            }
            sk.push(i);
        }
        return res;
    }
};

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