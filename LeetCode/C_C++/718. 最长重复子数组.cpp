class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for(int i = n-1; i >= 0; i--)
            for(int j = m-1; j >= 0; j--)
            {
                if(A[i] == B[j]){
                    f[i][j] = f[i+1][j+1] + 1;
                    ans = max(ans, f[i][j]);
                }else f[i][j] = 0;
            }
                    
        return ans;     
    }
};