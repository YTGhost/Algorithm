#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    unordered_set<char> s;
    for(auto c : s2)
        s.insert(c);
    string res = "";
    for(auto c : s1)
        if(!s.count(c)) res += c;
    cout << res << endl;
    return 0;
}