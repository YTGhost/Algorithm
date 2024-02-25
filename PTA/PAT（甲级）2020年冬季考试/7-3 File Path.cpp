#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 1010;
int n;
string tree[N];
unordered_map<int, int> p;
int cnt = 1;

int getDepth(string t)
{
    int cnt = 0;
    int idx = 0;
    while(t[idx++] == ' ') {
        cnt++;
    }
    return cnt;
}

string format(int x)
{
    char t[4];
    string res;
    sprintf(t, "%04d", x);
    res = t;
    return res;
}

void dfs(int depth, int parent)
{
    string temp;
    int id = -1;
    int newP;
    while(cnt < n) {
        temp = tree[cnt];
        int d = getDepth(temp);
        id = stoi(temp);
        if(d == depth) {
            p[id] = parent;
            newP = id;
        } else if(d > depth) {
            dfs(depth + 1, newP);
            cnt--;
        } else if(d < depth) {
            break;
        }
        cnt++;
    }
}

int main()
{
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) getline(cin, tree[i]);
    p[0] = -1;
    dfs(1, 0);
    int k;
    cin >> k;
    while(k--) {
        int id;
        cin >> id;
        if(!p.count(id)) {
            printf("Error: %s is not found.", format(id).c_str());
        } else {
            string res = format(id);
            while(p[id] != -1) {
                res = format(p[id]) + "->" + res;
                id = p[id];
            }
            cout << res;
        }
        if(k) cout << endl;
    }
    return 0;
}