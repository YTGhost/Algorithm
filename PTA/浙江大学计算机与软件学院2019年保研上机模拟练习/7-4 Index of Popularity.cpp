#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
using namespace std;

const int N = 100010, M = 200010;
int n, m;
int h[N], e[M], ne[M], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
struct Node {
    int id, ip;
    
    bool operator< (const Node& t) const {
        if(ip != t.ip) return ip > t.ip;
        else return id < t.id;
    }
};

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    while(true) {
        int k;
        cin >> k;
        if(k) {
            vector<int> people(k);
            unordered_set<int> s;
            vector<Node> res;
            for(int i = 0; i < k; i++) {
                cin >> people[i];
                s.insert(people[i]);
                res.push_back({people[i], 0});
            }
            for(int i = 0; i < k; i++) {
                for(int j = h[people[i]]; ~j; j = ne[j]) {
                    int val = e[j];
                    if(s.count(val)) res[i].ip++;
                }
            }
            sort(res.begin(), res.end());
            printf("%d %d %d\n", res[0].id, res[1].id, res[2].id);
        } else {
            break;
        }
    }
    return 0;
}