class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int p1 = 1;
        int p2 = 1;
        int sum = 0;
        while(p1 <= target/2){
            if(sum < target){
                sum += p2;
                p2++;
            }else if(sum > target){
                sum -= p1;
                p1++;
            }else{
                vector<int> temp;
                for(int i = p1; i < p2; i++)
                {
                    temp.push_back(i);
                }
                ans.push_back(temp);
                sum -= p1;
                p1++;
            }
        }
        return ans;
    }
};