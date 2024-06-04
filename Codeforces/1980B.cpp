#include <bits/stdc++.h>
using namespace std;

// 不需要二分
// void solve()
// {
//     int n, f, k;
//     cin >> n >> f >> k;
//     vector<int> nums(n + 1);
//     unordered_map<int, int> hash;
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//         hash[nums[i]]++;
//     }
//     int fav = nums[f - 1];
//     sort(nums.rbegin(), nums.rend());
//     int l = 0, r = n;
//     while(l < r) {
//         int mid = l + (r - l) / 2;
//         if (nums[mid] > fav) {
//             l = mid + 1;
//         } else {
//             r = mid;
//         }
//     }
//     if (l + hash[fav] - 1 <= k - 1) {
//         cout << "YES" << endl;
//     } else if (l <= k - 1 && (k - 1) < l + hash[fav] - 1) {
//         cout << "MAYBE" << endl;
//     } else {
//         cout << "NO" << endl;
//     }
//     return;
// }

void solve()
{
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int fav = nums[f - 1];
    int gt = 0, eq = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > fav) {
            gt++;
        } else if (nums[i] == fav) {
            eq++;
        }
    }
    if (gt >= k) {
        cout << "NO" << endl;
    } else if (gt + eq <= k) {
        cout << "YES" << endl;
    } else {
        cout << "MAYBE" << endl;
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}