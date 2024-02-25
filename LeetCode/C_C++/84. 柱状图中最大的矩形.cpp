class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n), r(n);
        stack<int> stk;
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            l[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = n-1; i >= 0; i--)
        {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            r[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++)
            res = max(res, (r[i] - l[i] - 1) * heights[i]);
        return res;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for(int i = 0; i < n; i++)
        {
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]){
                mono_stack.pop();
            }
            left[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for(int i = n-1; i >= 0; i--)
        {
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]){
                mono_stack.pop();
            }
            right[i] = mono_stack.empty() ? n : mono_stack.top();
            mono_stack.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};