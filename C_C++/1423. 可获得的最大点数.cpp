class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, res = INT_MAX, n = cardPoints.size();
        for(int i = 0; i < n-k; i++) 
            sum += cardPoints[i];
        res = min(res, sum);
        for(int i = n-k; i < n; i++)
        {
            sum = sum + cardPoints[i] - cardPoints[i-n+k];
            res = min(res, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - res;
    }
};