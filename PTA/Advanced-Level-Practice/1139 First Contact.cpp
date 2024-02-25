#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 305;
int n, m;
unordered_map<string, int> mp;
string num[N];
int g[N][N];
int id;
vector<int> boys, girls;

int main()
{
    cin >> n >> m;
    char as[N], bs[N];
    while(m--) {
        string a, b;
        scanf("%s%s", as, bs);
        a = as, b = bs;
        string x = a, y = b;
        if(x.length() == 5) x = x.substr(1);
        if(y.length() == 5) y = y.substr(1);
        if(mp.count(x) == 0) mp[x] = ++id, num[id] = x;
        if(mp.count(y) == 0) mp[y] = ++id, num[id] = y;
        
        int px = mp[x], py = mp[y];
        g[px][py] = g[py][px] = 1;
        
        if(a[0] != '-') boys.push_back(px);
        else girls.push_back(px);
        if(b[0] != '-') boys.push_back(py);
        else girls.push_back(py);
    }
    
    sort(boys.begin(), boys.end());
    boys.erase(unique(boys.begin(), boys.end()), boys.end());
    sort(girls.begin(), girls.end());
    girls.erase(unique(girls.begin(), girls.end()), girls.end());
    
    int k;
    cin >> k;
    while(k--) {
        vector<pair<string, string>> res;
        string x, y;
        scanf("%s%s", as, bs);
        x = as, y = bs;
        
        vector<int> p = boys, q = boys;
        if(x[0] == '-') p = girls, x = x.substr(1);
        if(y[0] == '-') q = girls, y = y.substr(1);
        
        int a = mp[x], b = mp[y];
        
        for(int c : p) {
            for(int d : q) {
                if(c != a && c != b && d != a && d != b && g[a][c] && g[c][d] && g[d][b]) {
                    res.push_back({ num[c], num[d] });
                }
            }
        }
        
        sort(res.begin(), res.end());
        printf("%d\n", res.size());
        for(auto p : res) {
            printf("%s %s\n", p.first.c_str(), p.second.c_str());
        }
    }
    return 0;
}