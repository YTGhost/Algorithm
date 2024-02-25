class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return process(S) == process(T);
    }

    string process(string t)
    {
        string res;
        for(auto c : t)
        {
            if(c != '#') {
                res.push_back(c);
            } else if(!res.empty()) {
                res.pop_back();
            }
        }
        return res;
    }
};