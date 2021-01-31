class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1 = 0, sum2 = 0;
        for(auto num : A) sum1 += num;
        for(auto num : B) sum2 += num;
        unordered_set<int> s(A.begin(), A.end());
        int t = (sum1 - sum2) / 2;
        vector<int> res;
        for(auto num : B)
        {
            if(s.count(t + num)) {
                res = vector<int>{t + num, num};
                break;
            }
        }
        return res;
    }
};