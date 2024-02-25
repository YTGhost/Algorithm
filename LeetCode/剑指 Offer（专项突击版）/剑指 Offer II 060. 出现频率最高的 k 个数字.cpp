class Solution {
public:
    typedef pair<int, int> PII;
    int k;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    void add(PII item) {
        if(q.size() < k) {
            q.push(item);
        } else if(q.size() == k && q.top().first < item.first) {
            q.pop();
            q.push(item);
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        this->k = k;
        unordered_map<int, int> m;
        for(auto num : nums) {
            m[num]++;
        }
        for(auto &[num, count] : m) {
            add({count, num});
        }
        vector<int> res;
        while(q.size()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};