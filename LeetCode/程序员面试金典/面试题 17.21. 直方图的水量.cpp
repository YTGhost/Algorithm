class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
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