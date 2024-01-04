class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, n = nums.size();
        for(int r = l + 1; r < n; r++) {
            while(r < n && nums[r] == nums[l]) {
                r++;
            }
            if(r < n) {
                nums[++l] = nums[r];
            }
        }
        return l + 1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int index = 1;
        int pre = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != pre) {
                nums[index++] = nums[i];
                pre = nums[i];
            }
        }
        return index;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int cur = 0, pre = 0; cur < nums.size(); i++)
        {
            while(cur < nums.size() && nums[cur] == nums[pre]) cur++;
            nums[i] = nums[pre];
            pre = cur;
        }
        return i;
    }
};