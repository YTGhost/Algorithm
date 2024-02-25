class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum;
        while(l < r) {
            sum = numbers[l] + numbers[r];
            if(sum > target) r--;
            else if(sum < target) l++;
            else break;
        }
        return vector<int>{l, r};
    }
};