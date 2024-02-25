class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, val = -1;
        for(auto num : nums)
        {
            if(!cnt){
                cnt = 1;
                val = num;
            }else{
                if(num == val) cnt++;
                else cnt--;
            }
        }
        return val;
    }
};