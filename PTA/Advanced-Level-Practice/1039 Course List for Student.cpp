#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<string, vector<int>> m;
    
    while(k--) {
        int x, y;
        cin >> x >> y;
        while(y--) {
            string name;
            cin >> name;
            m[name].push_back(x);
        }
    }
    while(n--) {
        string name;
        cin >> name;
        sort(m[name].begin(), m[name].end());
        cout << name << " " << m[name].size();
        for(int i = 0; i < m[name].size(); i++)
            cout << " " << m[name][i];
        cout << endl;
    }
    return 0;
}