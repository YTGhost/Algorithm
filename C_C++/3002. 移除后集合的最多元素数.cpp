class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int t1 = n / 2;
        int t2 = t1;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        unordered_set<int> hash;
        for(auto num : nums1) {
            m1[num]++;
        }
        for(auto num : nums2) {
            m2[num]++;
            if(m1.count(num)) {
                hash.insert(num);
            }
        }
        for(auto [k, v] : m1) {
            int cnt = min(v - 1, t1);
            t1 -= cnt;
            m1[k] -= cnt;
            if(t1 == 0) break;
        }
        for(auto [k, v] : m2) {
            int cnt = min(v - 1, t2);
            t2 -= cnt;
            m2[k] = cnt;
            if(t2 == 0) break;
        }
        if(t1) {
            for(auto it = hash.begin(); it != hash.end();) {
                t1--;
                m1[*it]--;
                it = hash.erase(it);
                if(t1 == 0) break;
            }
        }
        if(t2) {
            for(auto it = hash.begin(); it != hash.end();) {
                t2--;
                m2[*it]--;
                it = hash.erase(it);
                if(t2 == 0) break;
            }
        }
        unordered_set<int> res;
        for(auto [k, v] : m1) {
            if(m1.count(k)) {
                res.insert(k);
            }
        }
        for(auto [k, v] : m2) {
            if(m2.count(k)) {
                res.insert(k);
            }
        }
        return res.size() - t1 - t2;
    }
};