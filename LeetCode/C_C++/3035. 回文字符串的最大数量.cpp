class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = words.size();
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto word : words) {
            q.push(word.size());
        }
        int hash[26];
        memset(hash, 0, sizeof(hash));
        for(auto word : words) {
            for(auto c : word) {
                hash[c - 'a']++;
            }
        }
        int even = 0, odd = 0;
        for(int i = 0; i < 26; i++) {
            if(hash[i] % 2 == 0) {
                even += hash[i];
            } else {
                even += hash[i] / 2 * 2;
                odd++;
            }
        }
        while(!q.empty()) {
            int cnt = q.top();
            q.pop();
            if(cnt % 2 == 0) {
                if(even < cnt) break;
                even -= cnt;
                res++;
            } else {
                int t = cnt / 2 * 2;
                if(odd <= 0) {
                    if(even >= 2) {
                        even -= 2;
                        odd += 2;
                    } else {
                        break;
                    }
                }
                if(even < t) break;
                even -= t;
                odd--;
                res++;
            }
        }
        return res;
    }
};