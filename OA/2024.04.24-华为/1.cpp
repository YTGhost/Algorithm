#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0, target;
	while(cin >> target) {
		n++;
	}
	bool flag = false;
	int l = 1, r = n;
	string res = "S";
	while(l < r) {
		int mid = l + (r - l) / 2;
		if(mid == target) {
			res += "Y";
			flag = true;
			break;
		} else if(mid > target) {
			r = mid;
			res += "L";
		} else {
			l = mid + 1;
			res += "R";
		}
	}
	if(!flag) res += "N";
	cout << res << endl;
	return 0;
}