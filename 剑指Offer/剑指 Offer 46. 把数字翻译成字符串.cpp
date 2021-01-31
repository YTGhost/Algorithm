// DFS
class Solution {
public:
    int ans;
    void dfs(string num, int count){
        if(count == num.size()){
            ans++;
            return;
        };
        if(count > num.size()) return;
        for(int i = 1; i <= 2; i++)
        {
            if(i == 2 && num[count] == '0') continue;
            if(stoi(num.substr(count, i)) <= 25) dfs(num, count+i);
        }
    }

    int translateNum(int num) {
        dfs(to_string(num), 0);
        return ans;
    }
};

// DP
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int a = 0, b = 0, c = 1;
        for(int i = 0; i < str.length(); i++)
        {
            a = b;
            b = c;
            c = 0;
            c += b;
            if(i == 0) continue;
            if(str.substr(i-1, 2) >= "10" && str.substr(i-1, 2) <= "25") c += a;
        }
        return c;
    }
};