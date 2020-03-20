class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> a(k);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < k; i++)
        {
            a[i] = arr[i];
        }
        return a;
    }
};