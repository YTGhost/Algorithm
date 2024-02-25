#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int N = 100010;
int e[N], ne[N];

int main()
{
    int head, n;
    cin >> head >> n;
    for(int i = 0; i < n; i++) {
        int address, key, next;
        cin >> address >> key >> next;
        e[address] = key;
        ne[address] = next;
    }
    vector<pair<int, int>> link;
    vector<pair<int, int>> res;
    vector<pair<int, int>> del;
    unordered_set<int> set;
    for(int i = head; i != -1; i = ne[i]) {
        link.push_back({i, e[i]});
    }
    for(int i = 0; i < link.size(); i++) {
        if(set.count(abs(link[i].second))) {
            del.push_back(link[i]);
        } else {
            res.push_back(link[i]);
            set.insert(abs(link[i].second));
        }
    }
    for(int i = 0; i < res.size(); i++) {
        if(i == res.size()-1) {
            ne[res[i].first] = -1;
        } else {
            ne[res[i].first] = res[i+1].first;
        }
    }
    for(int i = 0; i < del.size(); i++) {
        if(i == del.size()-1) {
            ne[del[i].first] = -1;
        } else {
            ne[del[i].first] = del[i+1].first;
        }
    }
    for(int i = 0; i < res.size(); i++) {
        printf("%05d %d ", res[i].first, res[i].second);
        if(ne[res[i].first] == -1) cout << -1 << endl;
        else printf("%05d\n", ne[res[i].first]);
        
    }
    for(int i = 0; i < del.size(); i++) {
        printf("%05d %d ", del[i].first, del[i].second);
        if(ne[del[i].first] == -1) cout << -1 << endl;
        else printf("%05d\n", ne[del[i].first]);
    }
    return 0;
}