#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 1010;
string a[N];

int main()
{
    int m, n, s;
    cin >> m >> n >> s;
    unordered_set<string> set;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = s; i <= m; i += n) {
        while(i <= m && set.count(a[i])) i++;
        if(i <= m) {
            set.insert(a[i]);
            cnt++;
            cout << a[i] << endl;
        }
    }
    if(!cnt) cout << "Keep going..." << endl;
    return 0;
}