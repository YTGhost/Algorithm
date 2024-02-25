#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l, m;
typedef pair<int, int> PII;
vector<PII> segs;

void merge(vector<PII>& segs)
{
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int start = -1, end = -1;
    
    for(auto seg : segs)
    {
        if(end < seg.first)
        {
            if(start != -1) res.push_back({start, end});
            start = seg.first, end = seg.second;
        } else {
            end = max(end, seg.second);
        }
    }
    if(start != -1) res.push_back({start, end});
    segs = res;
}

int main()
{
    cin >> l >> m;
    for(int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        segs.push_back({start, end});
    }
    
    merge(segs);
    
    int sum = l+1;
    for(auto seg : segs) sum -= seg.second - seg.first + 1;
    cout << sum << endl;
    return 0;
}
