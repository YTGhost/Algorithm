class Solution {
public:

    /* 归并排序 */
    vector<int> temp;
    void merge_sort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = (l + r) >> 1;
    
        merge_sort(nums, l, mid);
        merge_sort(nums, mid+1, r);

        int k = 0, i = l, j = mid+1;
        while(i <= mid && j <=r)
        {
            if(nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= r) temp[k++] = nums[j++];

        for(int i = l, j = 0; i <= r; i++, j++) nums[i] = temp[j];
    }

    /* 快速排序 */
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

    vector<int> sortArray(vector<int>& nums) {
        temp.resize((int)nums.size(), 0);
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};