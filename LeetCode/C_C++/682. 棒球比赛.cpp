class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        vector<int> nums(n);
        int i = 0;
        for(auto op : ops) {
            if(op == "+") {
                nums[i] = nums[i - 1] + nums[i - 2];
            } else if(op == "D") {
                nums[i] = nums[i - 1] * 2;
            } else if(op == "C") {
                nums[i - 1] = 0;
                i -= 2;
            } else {
                nums[i] = stoi(op);
            }
            i++;
        }
        int res = 0;
        for(auto num : nums) {
            res += num;
        }
        return res;
    }
};