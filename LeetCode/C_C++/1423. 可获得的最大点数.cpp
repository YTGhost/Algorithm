class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int len = n - k;
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int sum = 0;
        for(int i = 0; i < len; i++) {
            sum += cardPoints[i];
        }
        int res = sum;
        int l = 1, r = n - k;
        while(r < n) {
            sum = sum - cardPoints[l - 1] + cardPoints[r];
            res = min(res, sum);
            l++;
            r++;
        }
        return totalSum - res;
    }
};

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