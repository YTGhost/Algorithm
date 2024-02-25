class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        long num = 0;
        vector<bool> res;
        for(int i = 0; i < A.size(); i++)
        {
            num += A[i];
            res.push_back(num % 5 == 0);
            num <<= 1;
            num %= 5;
        }
        return res;
    }
};