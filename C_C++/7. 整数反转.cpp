class Solution {
public:
    int reverse(int x) {
        int max = 0x7fffffff, min = 0x80000000;
        long sum = 0;
        for(;x;sum = sum*10 + x%10,x/=10);
        return sum>max || sum<min ? 0 : sum;
    }
};