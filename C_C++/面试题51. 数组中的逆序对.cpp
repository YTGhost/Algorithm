class Solution {
public:
    long count;
    int temp[50010];
    void merge_score(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int mid = (l + r) >> 1;
        
        merge_score(nums, l, mid);
        merge_score(nums, mid+1, r);

        int k = 0, i = l, j = mid+1;
        while(i <= mid && j <= r)
        {
            if(nums[i] <= nums[j]) temp[k++] = nums[i++];
            else{
                count += mid - i + 1;
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= r) temp[k++] = nums[j++];
        for(int i = l, j = 0; i <= r; i++, j++) nums[i] = temp[j];
    }

    int reversePairs(vector<int>& nums) {
        merge_score(nums, 0, nums.size()-1);
        return count;
    }
};