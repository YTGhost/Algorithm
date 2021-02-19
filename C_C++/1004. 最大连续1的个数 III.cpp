class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r = 0, res = 0, cnt = 0, n = A.size();
        while(r < n)
        {
            if(A[r] == 0) {
                cnt++;
                while(l <= r && cnt > K) {
                    if(A[l++] == 0) cnt--;
                }
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};