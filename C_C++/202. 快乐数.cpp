class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do{
            fast = powSum(fast);
            fast = powSum(fast);
            slow = powSum(slow);
        }while(fast != slow);
        if(fast == 1) return true;
        else return false;
    }

    int powSum(int n){
        int sum = 0;
        while(n != 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};