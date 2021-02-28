class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(n == 1) return true;
        int sign = 0;
        for(int i = 1; i < n; i++)
        {
            if(sign == 0) {
                if(A[i] > A[i-1]) sign = 1;
                else if(A[i] < A[i-1]) sign = -1;
            } else if(sign == 1) {
                if(A[i] < A[i-1]) return false;
            } else {
                if(A[i] > A[i-1]) return false;
            }
        }
        return true;
    }
};