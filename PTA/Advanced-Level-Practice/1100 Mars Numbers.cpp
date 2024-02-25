#include <iostream>
#include <sstream>
using namespace std;

string names[] = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
};

int get(string word) 
{
    for(int i = 0; i < 25; i++) {
        if(names[i] == word) {
            if(i < 13) return i;
            return (i - 12) * 13;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    while(n--) {
        string line;
        getline(cin, line);
        stringstream ssin(line);
        if(line[0] <= '9') {
            int t;
            ssin >> t;
            if(t < 13) cout << names[t] << endl;
            else {
                cout << names[12 + t / 13];
                if(t % 13 == 0) cout << endl;
                else cout << " " << names[t % 13] << endl;
            }
        } else {
            int res = 0;
            string word;
            while(ssin >> word) res += get(word);
            cout << res << endl;
        }
    }
    return 0;
}