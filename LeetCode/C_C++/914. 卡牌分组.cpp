class Solution {
public:
    int n[10000];
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a%b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        for(auto num : deck)
        {
            n[num]++;
        }
        int x = -1;
        for(int i = 0; i < 10000; i++)
        {
            if(n[i] > 0){
                x = x == -1 ? n[i] : gcd(x, n[i]);
                if(x == 1) return false;
            }
        }
        return x >= 2;
    }
};