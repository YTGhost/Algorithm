#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, int> mp;
    vector<int> a(n);
    vector<int> b(n);
    vector<bool> visitA(n + 1);
    vector<bool> visitB(n + 1);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        mp[nums[i]]++;
        if(mp[nums[i]] > 2) flag = true;
    }
    if(flag) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        int x = nums[i];
        if(!visitA[x]) {
            visitA[x] = true;
            a[i] = x;
        } else if(!visitB[x]) {
            visitB[x] = true;
            b[i] = x;
        }
    }
    int j = 1;
    for(int i = 0; i < n; i++) {
        if(a[i]) continue;
        while(visitA[j]) {
            j++;
        }
        a[i] = j;
        visitA[j] = true;
    }
    j = 1;
    for(int i = 0; i < n; i++) {
        if(b[i]) continue;
        while(visitB[j]) {
            j++;
        }
        b[i] = j;
        visitB[j] = true;
    }
    for(int i = 0; i < n; i++) {
        if(i == n - 1) cout << a[i] << endl;
        else cout << a[i] << " ";
    }
    for(int i = 0; i < n; i++) {
        if(i == n - 1) cout << b[i];
        else cout << b[i] << " ";
    }
    return 0;
}
