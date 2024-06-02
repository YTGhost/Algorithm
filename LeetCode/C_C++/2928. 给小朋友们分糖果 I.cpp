class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        for(int x = 0; x <= limit; x++) {
            for(int y = 0; y <= limit; y++) {
                if(x + y > n) {
                    break;
                }
                if(n - x - y <= limit) {
                    res++;
                }
            }
        }
        return res;
    }
};