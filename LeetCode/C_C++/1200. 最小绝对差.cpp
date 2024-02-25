class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int minVal = INT_MAX;
        int n = arr.size();
        for(int i = 1; i < n; i++) {
            int a = arr[i - 1], b = arr[i];
            int diff = b - a;
            if(diff < minVal) {
                minVal = b - a;
                res.clear();
                res.push_back({a, b});
            } else if(diff == minVal) {
                res.push_back({a, b});
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int t = 0x3f3f3f3f;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++) {
            int temp = arr[i] - arr[i-1];
            if(temp < t) {
                t = temp;
                res.clear();
                res.push_back({arr[i-1], arr[i]});
            } else if(temp == t) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};