#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    continue;
                }
                if(g[i][j] == '.' && g[nx][ny] == '#') {
                    g[i][j] = ',';
                    break;
                }
            }
        }
    }
    int res = 1;
    vector<vector<int>> visit(h, vector<int>(w, 0));
    set<pair<int, int>> st;
    function<void(int, int)> dfs = [&](int x, int y) {
        st.insert({x, y});
        if(g[x][y] == ',') return;
        visit[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
                continue;
            }
            if(visit[nx][ny]) continue;
            dfs(nx, ny);
        }
    };
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(g[i][j] == '.' && !visit[i][j]) {
                dfs(i, j);
                res = max(res, (int)st.size());
                st.clear();
            }
        }
    }
    cout << res << endl;
    return 0;
}