#include <iostream>
using namespace std;

string res;
int cnt = 0x3f3f3f3f;

int main()
{
    string s, p;
    cin >> s >> p;
    char start = p[0];
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != start) continue;
        int idx1 = i + 1, idx2 = 1, count = 1;
        while(idx1 < s.length() && idx2 < p.length()) {
            if(s[idx1] == p[idx2]) idx2++;
            idx1++;
            count++;
        }
        if(idx2 >= p.length()) {
            if(count < cnt) {
                cnt = count;
                res = s.substr(i, count);
            }
        }
    }
    cout << res << endl;
    return 0;
}