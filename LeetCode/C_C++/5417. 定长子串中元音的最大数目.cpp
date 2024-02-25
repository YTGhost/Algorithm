class Solution {
public:
    int count(string temp){
        int count = 0;
        for(int i = 0; i < temp.length(); i++)
        {
            if(temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') count++;
        }
        return count;
    }
    
    int check(char temp){
        if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') return true;
        return false;
    }
    
    int maxVowels(string s, int k) {
        int ans = 0;
        vector<int> pre;
        int l = 0, r = k - 1;
        for(; r < s.length(); l++, r++)
        {
            int cnt;
            if(r == k-1) cnt = count(s.substr(l, k));
            else{
                cnt = pre[l-1];
                if(check(s[l-1])) cnt--;
                if(check(s[r])) cnt++;
            }
            pre.push_back(cnt);
            ans = max(ans, cnt);
        }
        return ans;
    }
};