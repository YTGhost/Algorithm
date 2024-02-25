#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    unordered_map<char, int> map;
    for(auto c : str1) map[c]++;
    for(auto c : str2) map[c]--;
    
    int a = 0, b = 0;
    for(auto item : map)
    {
        if(item.second > 0) a += item.second;
        else b -= item.second;
    }
    if(b) cout << "No " << b << endl;
    else cout << "Yes " << a << endl;
    return 0;
}