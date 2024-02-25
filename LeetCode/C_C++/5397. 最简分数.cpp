class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        if(n == 1) return ans;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(j == 1){
                    string temp = "1";
                    temp += '/' + to_string(i);
                    ans.push_back(temp);
                }else if(gcd(i, j) != 1) continue;
                else{
                    string temp = "";
                    temp += to_string(j) + '/' + to_string(i);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};