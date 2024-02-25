class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        long long hash = (2LL << k) - 2;
        long long t = 0;
        for(int i = n - 1; ; i--) {
            t |= 1LL << nums[i];
            if((t & hash) == hash) {
                return n - i;
            }
        }
    }
};

class Solution {
public:
    bool check(vector<int>& hash, int k) {
        for(int i = 1; i <= k; i++) {
            if(hash[i] == 1) {
                return false;
            }
        }
        return true;
    }
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        vector<int> hash(51, 1);
        for(int i = n - 1; i >= 0; i--) {
            hash[nums[i]] = 0;
            res++;
            if(check(hash, k)) {
                break;
            }
        }
        return res;
    }
};