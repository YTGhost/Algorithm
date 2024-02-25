#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    unordered_map<int, vector<string>> map;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        string name;
        int cnt;
        cin >> name >> cnt;
        for(int i = 0; i < cnt; i++) {
            int id;
            cin >> id;
            map[id].push_back(name);
        }
    }
    
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, map[i].size());
        sort(map[i].begin(), map[i].end());
        for(auto s : map[i]) {
            printf("%s\n", s.c_str());
        }
    }
    return 0;
}