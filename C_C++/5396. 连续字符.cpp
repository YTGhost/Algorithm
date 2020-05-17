class Solution {
public:
    int maxPower(string s) {
        int maxPower = 0;
        int count = 0;
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;
        char pre = s[0];
        count++;
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == pre) count++;
            else count = 1;
            pre = s[i];
            maxPower = max(maxPower, count);
        }
        return maxPower;
    }
};