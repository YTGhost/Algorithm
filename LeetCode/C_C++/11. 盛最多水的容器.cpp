class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        for(int i = 0, j = n - 1; i < n;)
        {
            if(i == j) break;
            ans = max(min(height[i], height[j]) * (j - i), ans);
            if(height[i] <= height[j]) i++;
            else j--;
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while(l < r)
        {
            ans = max(min(height[l], height[r]) * (r - l), ans);
            if(height[l] <= height[r]) l++;
            else r--;
        }
        return ans;
    }
};