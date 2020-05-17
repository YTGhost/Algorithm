class Solution {
public:
    static bool cmp(const string &t1, const string &t2){
        return t1.length() < t2.length();
    }
    
    string arrangeWords(string text) {
        vector<string> ans;
        string temp = "";
        for(int i = 0; i < text.length(); i++)
        {
            if(text[i] == ' '){
                ans.push_back(temp);
                temp = "";
            }else{
                temp += text[i];
            }
        }
        ans.push_back(temp);
        stable_sort(ans.begin(), ans.end(), cmp);
        string t = "";
        for(int i = 0; i < ans.size(); i++)
        {
            if(i == 0){
                t.append(ans[i]);
            }else{
                string temp = ans[i];
                if(temp[0] <= 90) temp[0] = temp[0] + 32;
                t.append(temp);
            }
            if(i != ans.size()-1) t.append(" ");
        }
        if(t[0] >= 97) t[0] = t[0] - 32;
        return t;
    }
};