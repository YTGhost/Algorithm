#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    unordered_set<char> s;
    unordered_set<char> res;
    for(auto c : str2) {
        if(c >= 'a' && c <= 'z') s.insert(toupper(c));
        else s.insert(c);
    }
    for(auto c : str1) {
        char t = c;
        if(c >= 'a' && c <= 'z') t = toupper(t);
        if(!s.count(t) && !res.count(t)) {
            cout << t;
            res.insert(t);
        }
    }
    cout << endl;
    return 0;
}