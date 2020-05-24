class Solution {
public:
    bool check(string tmp, string searchWord){
        if(tmp.length() < searchWord.length()) return false;
        for(int i = 0; i < searchWord.length(); i++)
        {
            if(tmp[i] != searchWord[i]) return false;
        }
        return true;
    }
    
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> temp;
        string t = "";
        for(int i = 0; i < sentence.length(); i++)
        {
            if(sentence[i] != ' ') t += sentence[i];
            else{
                temp.push_back(t);
                t = "";
            }
        }
        temp.push_back(t);
        
        for(int i = 0 ; i < temp.size(); i++)
        {
            string tmp = temp[i];
            if(check(tmp, searchWord)) return i+1;
        }
        return -1;
    }
};