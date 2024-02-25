class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while(num) {
            num = ((num & 1) == 1) ? num - 1 : num / 2;
            res++;
        }
        return res;
    }
};