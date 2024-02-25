class Solution {
public:
    int cnt[10];
    bool digitCount(string num) {
        for(auto c : num) {
            cnt[c - '0']++;
        }
        for(int i = 0; i < num.length(); i++) {
            if(cnt[i] != num[i] - '0') {
                return false;
            }
        }
        return true;
    }
};