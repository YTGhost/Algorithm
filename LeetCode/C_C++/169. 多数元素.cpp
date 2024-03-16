class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1, cnt = 0;
        for(auto num : nums) {
            if(num == candidate) {
                cnt++;
            } else {
                if(cnt) {
                    cnt--;
                } else {
                    candidate = num;
                    cnt = 1;
                }
            }
        }
        return candidate;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};