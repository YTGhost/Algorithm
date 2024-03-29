class Solution {
public:
    int hash[105];
    int sumOfUnique(vector<int>& nums) {
        int res = 0;
        for(auto num : nums) {
            hash[num]++;
        }
        for(int i = 1; i <= 100; i++) {
            if(hash[i] == 1) {
                res += i;
            }
        }
        return res;
    }
};

class Solution {
public:
    int hash[101];
    int sumOfUnique(vector<int>& nums) {
        for(auto num : nums) {
            hash[num]++;
        }
        int res = 0;
        for(int i = 1; i <= 100; i++) {
            if(hash[i] == 1) res += i;
        }
        return res;
    }
};