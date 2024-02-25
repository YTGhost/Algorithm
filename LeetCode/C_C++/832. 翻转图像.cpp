class Solution {
public:
    void reverse(vector<int>& t) {
        int l = 0, r = t.size()-1;
        while(l < r)
        {
            t[l] = 1 - t[l];
            t[r] = 1 - t[r];
            swap(t[l++], t[r--]);
        }
        if(l == r) t[l] = 1 - t[l];
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n =  A.size();
        for(int i = 0; i < n; i++)
            reverse(A[i]);
        return A;
    }
};