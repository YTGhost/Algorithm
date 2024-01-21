class Solution {
public:
    int maximumSwap(int num) {
        if(num == 0) return 0;
        string str = "";
        while(num) {
            int t = num % 10;
            str = to_string(t) + str;
            num /= 10;
        }
        int n = str.size();
        vector<int> t(n, -1);
        int maxNum = str[n - 1] - '0', idx = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if(str[i] - '0' < maxNum) {
                t[i] = idx;
            }
            if(str[i] - '0' > maxNum) {
                maxNum = str[i] - '0';
                idx = i;
            }
        }
        for(int i = 0; i < n; i++) {
            if(t[i] != -1) {
                swap(str[i], str[t[i]]);
                break;
            }
        }
        return stoi(str);
    }
};