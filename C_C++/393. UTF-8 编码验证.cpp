class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for(int i = 0; i < n;) {
            int t = data[i], j = 7;
            while(j >= 0 && (((t >> j) & 1) == 1)) j--;
            int cnt = 7 - j;
            if(cnt == 1 || cnt > 4) return false;
            if(i + cnt - 1 >= n) return false;
            for(int k = i + 1; k < i + cnt; k++) {
                if((((data[k] >> 7) & 1) == 1) && (((data[k] >> 6) & 1) == 0)) continue;
                return false;
            }
            if(cnt == 0) i++;
            else i += cnt;
        }
        return true;
    }
};