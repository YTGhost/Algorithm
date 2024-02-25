class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> hash;
        hash.insert({'a', 1});
        hash.insert({'e', 1});
        hash.insert({'i', 1});
        hash.insert({'o', 1});
        hash.insert({'u', 1});
        hash.insert({'A', 1});
        hash.insert({'E', 1});
        hash.insert({'I', 1});
        hash.insert({'O', 1});
        hash.insert({'U', 1});
        int l = 0, r = s.length()-1;
        int mid = l + r >> 1;
        while(l < r) {
            while(!hash[s[l]] && l < r) l++;
            while(!hash[s[r]] && l < r) r--;
            if(l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};