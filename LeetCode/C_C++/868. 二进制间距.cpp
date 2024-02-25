class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        int last = -1;
        int cnt = 0;
        while(n) {
            int x = n & 1;
            if(last == -1 && x) {
                last = cnt;
            } else if(x) {
                res = max(res,  cnt - last);
                last = cnt;
            }
            n >>= 1;
            cnt++;
        }
        return res;
    }
};