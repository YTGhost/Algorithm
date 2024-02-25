class Solution {
public:
    string sortString(string s) {
        vector<char> a (s.begin(), s.end());
        string ans;
        map<char, int> m;
        for(vector<char>::iterator it = a.begin(); it != a.end(); it++)
        {
            if(m.end() != m.find(*it)){
                m[*it]++;
            }else{
                m.insert(pair<char, int>(*it, 1));
            }
        }
        while(!m.empty()){
            for(map<char, int>::iterator it = m.begin(); it != m.end();){
                ans.append(1, it->first);
                (it->second)--;
                if(it->second == 0){
                    m.erase(it++);
                }else{
                    it++;
                }
            }
            for(map<char, int>::reverse_iterator it = m.rbegin(); it != m.rend();){
                ans.append(1, it->first);
                (it->second)--;
                if(it->second == 0){
                    m.erase(std::next(it).base());
                }else{
                    it++;
                }
            }
        }
        return ans;
    }
};