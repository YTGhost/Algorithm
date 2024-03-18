class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(matrix[mid][0] >= target + 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int row = l - 1;
        if(row == -1 || row == m) {
            return false;
        }
        if(matrix[row][0] == target) {
            return true;
        }
        l = 0, r = n;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(matrix[row][mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l >= 0 && l < n && matrix[row][l] == target;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = m-1;
        while(x < n && y >= 0)
        {
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] > target) y--;
            else x++;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};