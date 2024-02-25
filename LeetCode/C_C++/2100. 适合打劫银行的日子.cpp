class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left(n);
        vector<int> right(n);
        for(int i = 1; i < n; i++) {
            if(security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            if(security[n - i - 1] <= security[n - i]) {
                right[n - i - 1] = right[n - i] + 1;
            }
        }
        vector<int> res;
        for(int i = time; i < n; i++) {
            if(left[i] >= time && right[i] >= time) {
                res.push_back(i);
            }
        }
        return res;
    }
};