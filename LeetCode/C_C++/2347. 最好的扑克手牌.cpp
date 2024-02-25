class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<char> s;
        for(auto suit : suits) {
            s.insert(suit);
        }
        if(s.size() == 1) return "Flush";
        unordered_map<int, int> m;
        for(auto rank : ranks) {
            m[rank]++;
        }
        if(m.size() == 5) return "High Card";
        for(auto [_, val]: m) {
            if(val > 2) return "Three of a Kind";
        }
        return "Pair";
    }
};