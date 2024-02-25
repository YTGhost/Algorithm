class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for(int i = 1, j = 0; j < target.size(); i++)
        {
            ans.push_back("Push");
            if(target[j] != i)
            {
                ans.push_back("Pop");
            }else{
                j++;
            }
        }
        return ans;
    }
};