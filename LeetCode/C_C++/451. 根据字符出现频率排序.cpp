class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;
        string res = "";
        for(auto c : s) m[c]++;
        for(auto item : m) {
            pq.push({item.second, item.first});
        }
        while(!pq.empty()) {
            int a = pq.top().first;
            int b = pq.top().second;
            for(int i = 0; i < a; i++) {
                res += b;
            }
            pq.pop();
        }
        return res;
    }
};