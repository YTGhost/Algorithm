class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n)
        {
            if(n & 1) res++;
            n >>= 1;
        }
        return res;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n)
        {
            count += n&1;
            n >>= 1;
        }
        return count;
    }
};