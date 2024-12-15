class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        for (auto num : arr) {
            mp[num]++;
        }
        priority_queue<pair<int, int>> q;
        for (auto item : mp) {
            q.push({item.second, item.first});
        }
        int res = 0, sum = 0;
        while (sum < n / 2) {
            auto item = q.top();
            q.pop();
            res++;
            sum += item.first;
        }
        return res;
    }
};
