class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int n = height.size();
        vector<int> res;
        for (int i = 1; i < n; i++) {
            if (height[i - 1] > threshold) {
                res.push_back(i);
            }
        }
        return res;
    }
};