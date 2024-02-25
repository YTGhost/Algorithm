#include <iostream> 
#include <vector> 
using namespace std; 
int n, k; 
const int N = 100010; 
vector<vector<int>> l;  
bool check(int x) {     
    int sum = 0;     
    for(int i = 0; i < n; i++)     
    {         
        sum += (l[i][0] / x) * (l[i][1] / x);         
        if(sum >= k) return true;     
    }     
    return false; 
}  
int main() 
{     
    cin >> n >> k;     
    for(int i = 0; i < n; i++)     
    {         
        int h, w;         
        cin >> h >> w;         
        l.emplace_back(vector<int>{h, w});     
    }     
    int l = 0, r = 1e5;     
    while(l < r)     
    {         
        int mid = l + r + 1 >> 1;         
        if(check(mid)) l = mid;         
        else r = mid - 1;     
    }     
    cout << l << endl;
    return 0; 
}