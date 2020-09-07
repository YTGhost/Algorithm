class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        unordered_map<int, int> m;
        for(auto num : nums) m[num]++;
        for(auto item : m)
        {
            if(q.size() == k) {
                if(item.second < q.top().second) continue;
                q.pop();
            }
            q.emplace(item.first, item.second);
        }
        vector<int> res(k);
        while(!q.empty())
        {
            res[--k] = q.top().first;
            q.pop();
        }
        return res;
    }
};