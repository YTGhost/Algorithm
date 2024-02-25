class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n)
        {
            int t = n % 3;
            if(t != 0 && t != 1) return false;
            n /= 3;
        }
        return true;
    }
};