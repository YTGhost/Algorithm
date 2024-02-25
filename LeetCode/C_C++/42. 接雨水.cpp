class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        stack<int> sk;
        for(int i = 0; i < n; i++) {
            while(!sk.empty() && height[i] >= height[sk.top()]) {
                int t = sk.top();
                sk.pop();
                if(sk.empty()) break;
                int w = i - sk.top() - 1;
                int h = min(height[i], height[sk.top()]) - height[t];
                res += w * h;
            }
            sk.push(i);
        }
        return res;
    }
};

class Solution {
public:
    stack<int> s;
    int ans;
    int trap(vector<int>& height) {
        for(int i = 0; i < height.size(); i++)
        {
            while(!s.empty() && height[s.top()] < height[i])
            {
                int cur = s.top();
                s.pop();
                while(!s.empty() && height[s.top()] == height[cur])
                {
                    s.pop();
                }
                if(!s.empty())
                {
                    int top = s.top();
                    ans += (min(height[top], height[i]) - height[cur]) * (i-top-1);
                }
            }
            s.push(i);
        }
        return ans;
    }
};