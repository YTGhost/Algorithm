class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != val) nums[index++] = nums[i];
        return index;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p1 = 0;
        int size = nums.size();
        for(int p2 = 0; p2 < size; p2++)
        {
            if(nums[p2] != val){
                nums[p1] = nums[p2];
                p1++;
            }
        }
        return p1;
    }
};