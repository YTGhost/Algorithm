class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].length();
        int res = 0;
        for(int i = 0; i < m; i++) {
            char last;
            bool flag = false;
            for(int j = 0; j < n; j++) {
                if(j == 0) last = strs[j][i];
                else {
                    if(strs[j][i] < last) {
                        flag = true;
                        break;
                    }
                    last = strs[j][i];
                }
            }
            if(flag) res++;
        }
        return res;
    }
};