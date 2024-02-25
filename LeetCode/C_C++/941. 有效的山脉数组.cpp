class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0;
        int size = A.size();
        while(i+1 < size && A[i] < A[i+1]) i++;
        if(i == 0 || i == size-1) return false;
        while(i+1 < size && A[i] > A[i+1]) i++;
        return i == size-1;
    }
};