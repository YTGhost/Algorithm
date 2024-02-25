class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int res = 0;
        vector<int> left(n, 0);
        for(int i = 1; i < n; i++)
            A[i] > A[i-1] ? left[i] = left[i-1] + 1 : left[i] = 0;
        vector<int> right(n, 0);
        for(int i = n-2; i >= 0; i--)
            A[i] > A[i+1] ? right[i] = right[i+1] + 1 : right[i] = 0;
        for(int i = 1; i <= n-2; i++)
            if(left[i] > 0 && right[i] > 0)
                res = max(res, left[i] + right[i] + 1);
        return res;
    }
};