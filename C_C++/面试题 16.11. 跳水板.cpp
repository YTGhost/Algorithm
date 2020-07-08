class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ans;
        if(k == 0) return ans;
        if(shorter == longer){
            ans.push_back(k*shorter);
            return ans;
        }
        for(int i = k, j = 0; i >= 0; i--, j++) ans.push_back(i*shorter + j*longer);
        return ans;
    }
};