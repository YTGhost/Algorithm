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