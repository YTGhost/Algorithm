class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);

        int i = 0;
        for(int item : A)
        {
            if(item % 2 == 0) {
                res[i] = item;
                i += 2;
            }
        }
        
        i = 1;
        for(int item : A)
        {
            if(item % 2 == 1) {
                res[i] = item;
                i += 2;
            }
        }
        return res;
    }
};