class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i <= j) {
            if (i != j) {
                res += stoi(to_string(nums[i]) + to_string(nums[j]));
            } else {
                res += nums[i];
            }
            i++;
            j--;
        }
        return res; 
    }
};