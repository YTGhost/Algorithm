class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                swap(nums[i], nums[p1]);
                p1++;
            } else if(nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if(p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                p0++;
                p1++;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), ptr = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
    }
};



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return;
        int p = 0, q = n-1;
        for(int i = 0; i <= q; i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = nums[p];
                nums[p] = 0;
                p++;
            }
            if(nums[i] == 2)
            {
                nums[i] = nums[q];
                nums[q] = 2;
                i--;
                q--; 
            }
        }
    }
};