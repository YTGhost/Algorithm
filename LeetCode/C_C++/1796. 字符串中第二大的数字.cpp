class Solution {
public:
    int first = -1, second = -1;
    int secondHighest(string s) {
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int num = s[i] - '0';
                if (num > first) {
                    second = first;
                    first = num;
                } else if (num != first && num > second) {
                    second = num;
                }
            }
        }
        return second;
    }
};