#include <bits/stdc++.h>
using namespace std;

bool can_reach_bank(int n, int m, int k, const string& river) {
    vector<bool> visited(n + 2, false);
    queue<pair<int, int>> q;
    visited[0] = true;
    q.push({0, 0});
    while (!q.empty()) {
        auto [current, swim_used] = q.front();
        q.pop();
        if (current == 0 || river[current - 1] == 'L') {
            for (int jump = 1; jump <= m; ++jump) {
                int next_pos = current + jump;
                if (next_pos > n + 1) break;
                if (next_pos == n + 1) return true;
                if (visited[next_pos] || river[next_pos - 1] == 'C') continue;
                visited[next_pos] = true;
                if (river[next_pos - 1] == 'W' && swim_used <= k) {
                    q.push({next_pos, swim_used});
                } else if (river[next_pos - 1] == 'L') {
                    q.push({next_pos, swim_used});
                }
            }
        }

        if (river[current - 1] == 'W' && current != 0) {
            int next_pos = current + 1;
            if (next_pos == n + 1 && swim_used + 1 <= k) return true;
            if (next_pos <= n + 1 && !visited[next_pos] && swim_used + 1 <= k) {
                visited[next_pos] = true;
                q.push({next_pos, swim_used + 1});
            }
        }
    }

    return false;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string str;
    cin >> str;
    bool res = can_reach_bank(n, m, k, str);
    cout << (res ? "YES" : "NO") << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}