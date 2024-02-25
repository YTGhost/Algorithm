class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int size = A.size();
        int ans = 0, left = A[0];
        for(int i = 1; i < size; i++)
        {
            ans = max(ans, left + A[i] - i);
            left = max(left, A[i] + i);
        }
        return ans;
    }
};