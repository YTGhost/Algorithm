class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxHeight = horizontalCuts[0];
        for(int i = 1; i < horizontalCuts.size(); i++) {
            maxHeight = max(maxHeight, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        int maxWidth = verticalCuts[0];
        for(int i = 1; i < verticalCuts.size(); i++) {
            maxWidth = max(maxWidth, verticalCuts[i] - verticalCuts[i - 1]);
        }
        cout << maxHeight << " " << maxWidth << endl;
        return (long long)maxHeight * maxWidth % MOD;
    }
};