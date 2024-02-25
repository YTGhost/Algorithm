class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int notDel = arr[0], isDel = 0, n = arr.size(), res = arr[0];
        for(int i = 1; i < n; i++) {
            isDel = max(isDel + arr[i], notDel);
            notDel = max(notDel, 0) + arr[i];
            res = max(res, max(isDel, notDel));
        }
        return res;
    }
};