class Solution {
public:
    void reverse(int l, int r, vector<int>& arr, vector<int>& idxs) {
        while(l < r) {
            idxs[arr[l]] = r, idxs[arr[r]] = l;
            swap(arr[l++], arr[r--]);
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> idxs(n + 5);
        vector<int> res;
        for(int i = 0; i < n; i++) {
            idxs[arr[i]] = i;
        }
        for(int i = n; i >= 1; i--) {
            int idx = idxs[i];
            if(idx == i - 1) continue;
            if(idx != 0) {
                res.push_back(idx + 1);
                reverse(0, idx, arr, idxs);
            }
            res.push_back(i);
            reverse(0, i - 1, arr, idxs);
        }
        return res;
    }
};