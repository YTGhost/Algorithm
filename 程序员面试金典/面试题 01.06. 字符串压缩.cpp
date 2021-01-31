class Solution {
public:
    string compressString(string S) {
        if(S.length() == 0)   return S;
        string t;
        char c = S[0];
        int count = 1;
        for(int i = 1; i < S.length(); i++)
        {
            if(S[i] != c){
                t += c + to_string(count);
                count = 1;
                c = S[i];
            }else{
                count++;
            }
        }
        if(count != 0)  t += c + to_string(count);
        return t.length() >= S.length() ? S : t;
    }
};