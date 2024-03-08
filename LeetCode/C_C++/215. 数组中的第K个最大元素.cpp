class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = nums.size();
        for(auto num : nums) {
            if(q.size() == k) {
                if(q.top() < num) {
                    q.pop();
                    q.push(num);
                }
            } else {
                q.push(num);
            }
        }
        return q.top();
    }
};

class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int x = nums[(l+r)/2], i = l-1, j = r+1;
        while(i < j)
        {
            do i++; while(nums[i] < x);
            do j--; while(nums[j] > x);
            if(i < j) swap(nums[i], nums[j]); 
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j+1, r);
    }

    int findKthLargest(vector<int>& nums, int k) {
        quick_sort(nums, 0, nums.size()-1);
        return nums[nums.size()-k];
    }
};