#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, k;
unordered_map<string, vector<pair<string, int>>> nodes;
unordered_map<string, bool> st;
unordered_map<string, int> total;

int dfs(string name, vector<string> &people)
{
    st[name] = true;
    people.push_back(name);
    auto edges = nodes[name];
    int sum = 0;
    for(auto edge : edges) {
        sum += edge.second;
        if(!st[edge.first]) {
            sum += dfs(edge.first, people);
        }
    }
    return sum;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string a, b;
        int t;
        cin >> a >> b >> t;
        nodes[a].push_back({b, t});
        nodes[b].push_back({a, t});
        total[a] += t;
        total[b] += t;
    }
    
    vector<pair<string, int>> res;
    
    for(auto node : total) {
        string name = node.first;
        vector<string> people;
        int sum = dfs(name, people) / 2;
        if(people.size() > 2 && sum > k) {
            string boss = people[0];
            for(auto person : people) {
                if(total[person] > total[boss]) boss = person;
            }
            res.push_back({boss, (int)people.size()});
        }
    }
    
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for(auto item : res) {
        cout << item.first << " " << item.second << endl;
    }
    return 0;
}