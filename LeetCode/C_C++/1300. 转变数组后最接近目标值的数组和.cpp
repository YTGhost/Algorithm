class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        vector<int> pre(size+1, 0);
        for(int i = 1; i <= size; i++)
        {
            pre[i] = pre[i-1] + arr[i-1];
        }
        int maxVal = arr[size-1];
        int ans = 0, diff = target;
        for(int i = 1; i <= maxVal; i++)
        {
            auto iter = lower_bound(arr.begin(), arr.end(), i);
            int sum = pre[iter - arr.begin()] + (arr.end()-iter) * i;
            if(abs(sum-target) < diff)
            {
                ans = i;
                diff = abs(sum-target);
            }
        }
        return ans;
    }
};