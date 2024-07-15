class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> email2Idxs;
        int n = accounts.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                email2Idxs[accounts[i][j]].push_back(i);
            }
        }
        vector<int> visited(n);
        unordered_set<string> st;
        vector<vector<string>> res;
        function<void(int)> dfs = [&](int idx) {
            visited[idx] = true;
            for (int i = 1; i < accounts[idx].size(); i++) {
                string email = accounts[idx][i];
                if (st.contains(email)) {
                    continue;
                }
                st.insert(email);
                for (int j = 0; j < email2Idxs[email].size(); j++) {
                    if (visited[email2Idxs[email][j]]) {
                        continue;
                    }
                    dfs(email2Idxs[email][j]);
                }
            }
        };
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            st.clear();
            dfs(i);
            vector<string> temp{accounts[i][0]};
            temp.insert(temp.end(), st.begin(), st.end());
            sort(temp.begin() + 1, temp.end());
            res.push_back(temp);
        }
        return res;
    }
};

class Solution {
public:
    int p[1001];
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for(int i = 0; i < n; i++) p[i] = i;
        unordered_map<string, int> m;
        for(int i = 0; i < n; i++)
            for(int j = 1; j < accounts[i].size(); j++)
            {
                if(m.count(accounts[i][j])) {
                    int root = m[accounts[i][j]];
                    p[find(root)] = find(i);
                }else {
                    m[accounts[i][j]] = i;
                }
            }
        unordered_map<int, unordered_set<string>> mm;
        for(int i = 0; i < n; i++)
        {
            int root = find(i);
            for(int j = 1; j < accounts[i].size(); j++)
                mm[root].insert(accounts[i][j]);
        }
        vector<vector<string>> res;
        for(auto node : mm)
        {
            vector<string> temp;
            int root = node.first;
            string name = accounts[root][0];
            temp.emplace_back(name);
            for(auto email : node.second)
                temp.emplace_back(email);
            sort(temp.begin(), temp.end());
            res.emplace_back(temp);
        }
        return res;
    }
};