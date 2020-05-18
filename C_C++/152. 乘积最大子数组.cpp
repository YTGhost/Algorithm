class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int tempMax = 1;
        int tempMin = 1;
        int Max = INT_MIN;
        for(auto it : nums)
        {
            if(it < 0){
                int temp = tempMax;
                tempMax = tempMin;
                tempMin = temp;
            }
            tempMax = max(tempMax*it, it);
            tempMin = min(tempMin*it, it);
            Max = max(tempMax, Max);
        }
        return Max;
    }
};