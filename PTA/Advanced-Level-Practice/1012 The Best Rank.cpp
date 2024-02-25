#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;

const int N = 2010;
unordered_map<string, vector<int>> grades;
vector<int> r[4];

int get_rank(vector<int> &a, int target) {
    int l = 0, r = a.size() - 1;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(a[mid] <= target) l = mid;
        else r = mid - 1;
    }
    return a.size() - l;
}

int main()
{
    int n, m;
    string name = "ACME";
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string id;
        int c, m, e, a;
        cin >> id >> c >> m >> e;
        a = round((c + m + e) / 3.0);
        vector<int> t(4);
        t[0] = a, t[1] = c, t[2] = m, t[3] = e;
        grades[id] = t;
        r[0].push_back(a);
        r[1].push_back(c);
        r[2].push_back(m);
        r[3].push_back(e);
    }
    for(int i = 0; i < 4; i++) sort(r[i].begin(), r[i].end());
    while(m--)
    {
        string id;
        cin >> id;
        if(!grades.count(id)) {
            cout << "N/A" << endl;
        } else {
            int rank = n + 1;
            char c;
            for(int i = 0; i < 4; i++)
            {
                int t = get_rank(r[i], grades[id][i]);
                if(t < rank) {
                    rank = t;
                    c = name[i];
                }
            }
            cout << rank << " " << c << endl;
        }
    }
    return 0;
}