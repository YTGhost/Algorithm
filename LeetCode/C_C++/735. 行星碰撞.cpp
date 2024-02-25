class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(auto item : asteroids) {
            while(!stk.empty() && stk.top() > 0 && item < 0) {
                if(stk.top() == -item) {
                    stk.pop();
                    item = 0;
                } else if(stk.top() < -item) {
                    stk.pop();
                    continue;
                } else {
                    item = 0;
                }
                break;
            }
            if(item != 0) stk.push(item);
        }
        int n = stk.size();
        vector<int> res(n);
        for(int i = n - 1; i >= 0; i--) {
            res[i] = stk.top();
            stk.pop();
        }
        return res;
    }
};