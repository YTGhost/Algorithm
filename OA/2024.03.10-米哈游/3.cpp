#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res = 0;
    unordered_set<int> st;
    function<void(int, int)> dfs = [&](int x, int fa) {
        st.insert(x);
        for(int i = x; i <= n; i += x) {
            if(st.find(i) != st.end()) {
                res++;
            }
        }
        for(int i = 0; i < (int)g[x].size(); i++) {
            if(g[x][i] == fa) continue;
            dfs(g[x][i], x);
        }
        st.erase(x);
    };
    dfs(x, 0);
    cout << res << endl;
}