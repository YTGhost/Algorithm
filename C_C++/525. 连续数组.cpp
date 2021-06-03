class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int, int> map;
        int counter = 0;
        map[counter] = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            if(num == 1) {
                counter++;
            } else {
                counter--;
            }
            if(map.count(counter)) {
                int prevIndex = map[counter];
                maxLen = max(maxLen, i - prevIndex);
            } else {
                map[counter] = i;
            }
        }
        return maxLen;
    }
};