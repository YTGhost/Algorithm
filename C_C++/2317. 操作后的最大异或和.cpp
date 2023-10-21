class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        for(auto num : nums) {
            res |= num;
        }
        return res;
    }
};

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        vector<int> hash(32, 0);
        for(auto num : nums) {
            for(int i = 0; i < 32; i++) {
                hash[i] += ((num >> i) & 1);
            }
        }
        for(int i = 0; i < 32; i++) {
            if(hash[i]) {
                res |= 1 << i;
            }
        }
        return res;
    }
};