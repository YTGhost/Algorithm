class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> res;
        string ans;
        for(int i = 0; i < paths.size(); i++)
        {
            int sign = 0;
            for(int j = 0; j < paths.size(); j++)
            {
                if(paths[i][1] == paths[j][0])
                {
                    sign = 1;
                    break;
                }
            }
            if(sign == 0){
                ans = paths[i][1];
                break;
            }
        }
        return ans;
    }
};