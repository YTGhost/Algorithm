class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        for(auto num : nums) s.insert(num); // 哈希表去重
        for(auto num : nums)
        {
            if(!s.count(num-1)){    // 当为一段序列的第一个元素时
                int cur = num;
                int length = 1;
                while(s.count(++cur)) length++; // 有后续元素时，更新长度
                ans = max(ans, length);
            }
        }
        return ans;
    }
};