class Solution {
public:
    string removeTrailingZeros(string num) {
        int idx = num.length() - 1;
        while(num[idx] == '0') {
            idx--;
        }
        return num.substr(0, idx + 1);
    }
};