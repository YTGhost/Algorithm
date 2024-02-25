class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for(int num : arr) {
            cnt[num]++;
        }
        if(cnt[0] % 2) {
            return false;
        }
        vector<int> nums;
        nums.reserve(cnt.size());
        for(auto &[x, _] : cnt) {
            nums.push_back(x);
        }
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        for(int num : nums) {
            if(cnt[2 * num] < cnt[num]) {
                return false;
            }
            cnt[2 * num] -= cnt[num];
        }
        return true;
    }
};