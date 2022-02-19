class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> newHeights(n + 2);
        for(int i = 0; i < n; i++) {
            newHeights[i + 1] = heights[i];
        }
        stack<int> stk;
        int res = 0;
        for(int i = 0; i < newHeights.size(); i++) {
            while(!stk.empty() && newHeights[i] < newHeights[stk.top()]) {
                int h = newHeights[stk.top()];
                stk.pop();
                res = max(res, (i - stk.top() - 1) * h);
            }
            stk.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<string>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        vector<int> heights(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
};