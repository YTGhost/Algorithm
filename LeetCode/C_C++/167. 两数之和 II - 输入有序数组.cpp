class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum == target) {
                res = vector<int>{l + 1, r + 1};
                break;
            } else if(sum > target) {
                r--;
            } else {
                l++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l < r)
        {
            int sum = numbers[l] + numbers[r];
            if(sum < target) l++;
            else if(sum > target) r--;
            else return {l+1, r+1};
        }
        return {l+1, r+1};
    }
};