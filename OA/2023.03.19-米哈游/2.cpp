#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--) {
        string s, t;
        cin >> s >> t;
        int n = s.length(), m = t.length();
        int cntM = 0, cntH = 0, cntY = 0;
        string newS, newT;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'm') cntM++;
            else if(s[i] == 'h') cntH++;
            else if(s[i] == 'y') cntY++;
            else newS.push_back(s[i]);
        }
        if(cntM != cntH || cntH != cntY || cntM != cntY) {
            cout << "No" << endl;
            continue;
        }
        for(int i = 0; i < m; i++) {
            if(t[i] == 'm') cntM--;
            else if(t[i] == 'h') cntH--;
            else if(t[i] == 'y') cntY--;
            else newT.push_back(t[i]);
        }
        if(cntM != cntH || cntH != cntY || cntM != cntY) {
            cout << "No" << endl;
            continue;
        }
        if(newS == newT) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}