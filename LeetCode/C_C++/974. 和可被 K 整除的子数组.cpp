class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int pre = 0, count = 0;
        for(int i = 0; i < n; i++)
        {
            pre += A[i];
            int modulus = (pre % K + K) % K;
            if(m.count(modulus)) count += m[modulus];
            m[modulus]++;
        }
        return count;
    }
};