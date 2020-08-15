class Solution {
public:
    int res;
    int t[50010];

    void merge_sort(vector<int>& a, int l, int r) {
        if(l >= r) return;
        int mid = (l + r) >> 1;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, r);

        int k = 0, i = l, j = mid+1;
        while(i <= mid && j <= r)
        {
            if(a[i] <= a[j]) t[k++] = a[i++];
            else{
                t[k++] = a[j++];
                res += mid - i + 1;
            }
        }
        while(i <= mid) t[k++] = a[i++];
        while(j <= r) t[k++] = a[j++];
        for(int i = l, j = 0; i <= r; i++, j++) a[i] = t[j];
    }

    int reversePairs(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return res;
    }
};

class Solution {
public:
    int t[50010];
    int ans;
    void merge_sort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int mid = l + r >> 1;

        merge_sort(nums, l, mid);
        merge_sort(nums, mid+1, r);

        int k = 0, i = l, j = mid+1;
        while(i <= mid && j <= r)
        {
            if(nums[i] <= nums[j]) t[k++] = nums[i++];
            else {
                t[k++] = nums[j++];
                ans += mid - i + 1;
            }
        }
        while(i <= mid) t[k++] = nums[i++];
        while(j <= r) t[k++] = nums[j++];
        for(int i = l, j = 0; i <= r; i++, j++) nums[i] = t[j];

    }
    int reversePairs(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return ans;
    }
};