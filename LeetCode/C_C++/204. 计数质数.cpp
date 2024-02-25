class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        for(int i = 2; i < n; i++) if(isPrime(i)) ans++;
        return ans;
    }

    bool isPrime(int n) {
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }
};