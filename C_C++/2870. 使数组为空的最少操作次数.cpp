class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        for(auto &[_, v] : m) {
            if(v == 1) {
                return -1;
            }
            res += (v + 2) / 3;
        }
        return res;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        for(auto &[k, v] : m) {
            if(v == 1) {
                return -1;
            }
            int t = v % 3;
            if(t == 0) {
                res += v / 3;
            } else if(t == 1) {
                int cnt = v / 3 - 1;
                res += cnt + 2;
            } else if(t == 2) {
                res += v / 3 + 1;
            }
        }
        return res;
    }
};