// AcWing打卡
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(!matrix.size()) return ans;
        int sign = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> check(m, vector<int>(n, 1));
        int nums = m*n;
        int count = 0;
        int i = 0, j = 0;
        
        while(count < nums)
        {
            ans.push_back(matrix[i][j]);
            check[i][j] = -1;
            if(++count == nums) break;
            if(sign == 1) j++;
            else if(sign == 2) i++;
            else if(sign == 3) j--;
            else i--;
            
            if(j == n){
                j--;
                i++;
                sign = 2;
            }else if(i == m){
                i--;
                j--;
                sign = 3;
            }else if(j == -1){
                j++;
                i--;
                sign = 4;
            }else if(i == -1){
                i++;
                j++;
                sign = 1;
            }

            if(check[i][j] == -1){
                if(sign == 1){
                    j--;
                    i++;
                    sign = 2;
                }else if(sign == 2){
                    i--;
                    j--;
                    sign = 3;
                }else if(sign == 3){
                    j++;
                    i--;
                    sign = 4;
                }else{
                    i++;
                    j++;
                    sign = 1;
                }
            }
        }
        return ans;
    }
};