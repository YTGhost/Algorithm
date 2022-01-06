class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            int temp = 0;
            for(auto c : words[i]) {
                temp |= 1 << (c - 'a');
            }
            nums[i] = temp;
        }
        int res = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i + 1; j < n; j++) {
                if((nums[i] & nums[j]) == 0) {
                    res = max(res, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return res;
    }
};