#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int bfs(string start)
{
    unordered_map<string, int> d;
    queue<string> q;
    string end = "12345678x";
    int px[] = {1, 0, -1, 0}, py[] = {0, -1, 0, 1};
    q.push(start);
    d[start] = 0;
    while(!q.empty())
    {
        string t = q.front();
        int distance = d[t];
        q.pop();
        if(t == end) return d[t];
        int k = t.find('x');
        int a = k % 3, b = k / 3;
        for(int i = 0; i < 4; i++)
        {
            int newX = a + px[i];
            int newY = b + py[i];
            if(newX >= 0 && newX < 3 && newY >= 0 && newY < 3){
                swap(t[k], t[newY*3 + newX]);
                if(!d.count(t)){
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[k], t[newY*3 + newX]);
            }
        }
    }
    return -1;
}

int main()
{
    string start;
    for(int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start) << endl;
    return 0;
}