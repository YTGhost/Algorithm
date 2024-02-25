#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 105, M = 15;
int reactants[N];
int products[M];
int n, m, k;
int res[M];
bool hasResult;
unordered_map<int, vector<vector<int>>> formula;

vector<int> getReacts(string str)
{
    vector<int> res;
    string temp;
    for(int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp += str[i];
        } else {
            if(temp != "") {
                res.push_back(stoi(temp)); 
                temp = "";
            }
        }
    }
    if(temp != "") res.push_back(stoi(temp));
    return res;
}

void dfs(int u)
{
    if(u == m) return;
    if(hasResult) return;
    int prod = products[u];
    for(int i = 0; i < formula[prod].size(); i++) {
        bool flag = true;
        for(int j = 0; j < formula[prod][i].size(); j++) {
            if(reactants[formula[prod][i][j]]) {
                reactants[formula[prod][i][j]] = 0;
            } else {
                for(int k = j-1; k >= 0; k--) {
                    reactants[formula[prod][i][k]] = 1;
                }
                flag = false;
                break;
            }
        }
        if(flag) {
            res[u] = i;
            if(u == m-1 && !hasResult) {
                hasResult = true;
            }
            dfs(u + 1);
            if(hasResult) return;
            for(int k = 0; k < formula[prod][i].size(); k++) {
                reactants[formula[prod][i][k]] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        int id;
        cin >> id;
        reactants[id] = 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int id;
        cin >> id;
        products[i] = id;
    }
    cin >> k;
    getchar();
    for(int i = 0; i < k; i++) {
        string str;
        getline(cin, str);
        int product = stoi(str.substr(str.length() - 2));
        str = str.substr(0, str.find('-') - 1);
        vector<int> reacts = getReacts(str);
        formula[product].push_back(reacts);
    }
    for(int i = 0; i < N; i++) {
        if(reactants[i]) {
            vector<int> t{i};
            formula[i].push_back(t);
        }
    }
    for(int i = 0; i < m; i++) {
        sort(formula[products[i]].begin(), formula[products[i]].end());
    }
    dfs(0);
    for(int i = 0; i < m; i++) {
        printf("%02d", formula[products[i]][res[i]][0]);
        for(int j = 1; j < formula[products[i]][res[i]].size(); j++) {
            printf(" + %02d", formula[products[i]][res[i]][j]);
        }
        printf(" -> %02d", products[i]);
        if(i != m-1) cout << endl;
    }
    return 0;
}