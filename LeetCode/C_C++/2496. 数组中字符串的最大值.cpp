class Solution {
public:
    bool isOnlyNumber(string& str) {
        for(auto c : str) {
            if(c < '0' || c > '9') {
                return false;
            }
        }
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for(auto str : strs) {
            if(isOnlyNumber(str)) {
                res = max(res, stoi(str));
            } else {
                res = max(res, (int)str.length());
            }
        }
        return res;
    }
};