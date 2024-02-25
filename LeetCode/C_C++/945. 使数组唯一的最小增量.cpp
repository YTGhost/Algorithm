class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.empty())   return 0;
        sort(A.begin(), A.end());
        int sum = 0;
        for(int i = 1; i < A.size(); i++)
        {
            int count = 0;
            if(A[i] <= A[i-1]){
                count += A[i-1] - A[i] + 1;
                A[i] += count;
                sum += count;
            }
        }
        return sum;
    }
};