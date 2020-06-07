class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int index = (arr.size() - 1) / 2;
        int mid = arr[index];
        sort(arr.begin(), arr.end(), [&](auto const& a,auto const& b)
        {
            if(abs(a-mid) > abs(b-mid) || (abs(a-mid) == abs(b-mid) && a > b)) return true;
            return false;
        });
        for(int i = 0; i < k; i++) ans.push_back(arr[i]);
        return ans;
    }
};