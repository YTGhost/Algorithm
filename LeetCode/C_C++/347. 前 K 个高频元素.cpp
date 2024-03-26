class Solution {
public:
    typedef pair<int, int> PII;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto cmp = [](const PII &a, const PII &b) {
            return a.second > b.second;
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> q;
        unordered_map<int, int> mp;
        for(auto num : nums) {
            mp[num]++;
        }
        for(auto item : mp) {
            if(q.size() == k) {
                if(item.second <= q.top().second) continue;
                q.pop();
            }
            q.push({item.first, item.second});
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};

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