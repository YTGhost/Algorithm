// 二分 O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            int s = 0;
            for(int x : nums) s += x >= l && x <= mid;
            if(s > mid - l + 1) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

// 快慢指针 O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};