class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int k = 0;
        for(int i : nums) k ^= i;

        int res = 1;
        while((res & k) == 0) res <<= 1;

        int a = 0, b = 0;
        for(int i : nums)
        {
            if(i & res) a ^= i;
            else b ^= i;
        }
        return vector<int>{a, b};
    }
};