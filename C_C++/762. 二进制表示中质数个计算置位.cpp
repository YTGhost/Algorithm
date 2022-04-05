class Solution {
public:
    bool hash[35];
    vector<int> nums = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int countPrimeSetBits(int left, int right) {
        for(int x : nums) {
            hash[x] = true;
        }
        int res = 0;
        for(int i = left; i <= right; i++) {
            int x = i, cnt = 0;
            while(x) {
                x -= (x & -x);
                cnt++;
            }
            if(hash[cnt]) res++;
        }
        return res;
    }
};