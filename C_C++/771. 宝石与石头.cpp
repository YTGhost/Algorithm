class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<int> set;
        int res = 0;
        for(auto c : J) set.insert(c);
        for(auto c : S) if(set.count(c)) res++;
        return res;
    }
};