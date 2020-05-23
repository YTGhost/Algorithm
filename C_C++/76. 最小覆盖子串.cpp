class Solution {
public:
    unordered_map<char, int> record, count;

    bool check() {
        for(auto item : record){
            if(count[item.first] < item.second){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for(auto item : t) record[item]++;
        int l = 0, r = -1;
        int ansL = -1, len = INT_MAX;
        while(r < (int)s.length())
        {
            if(record.find(s[++r]) != record.end()) count[s[r]]++;
            while(l <= r && check())
            {
                if(r-l+1 < len)
                {
                    ansL = l;
                    len = r-l+1;
                }
                if(record.find(s[l]) != record.end()) count[s[l]]--;
                l++;
            }
        }
        return ansL == -1 ? "" : s.substr(ansL, len);
    }
};