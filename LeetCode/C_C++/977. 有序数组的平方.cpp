class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int size = A.size();
        for(int i = 0; i < size; i++)
            A[i] *= A[i];
        sort(A.begin(), A.end());
        return A;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int size = A.size();
        for(int i = 0; i < size; i++)
        {
            if(A[i] < 0) A[i] = -A[i];
            else break;
        }
        sort(A.begin(), A.end());
        for(int i = 0; i < size; i++)
        {
            A[i] = A[i] * A[i];
        }
        return A;
    }
};