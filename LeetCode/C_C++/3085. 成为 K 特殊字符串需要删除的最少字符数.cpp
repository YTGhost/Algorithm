class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        vector<int> hash(26);
        for(auto c : word) {
            hash[c - 'a']++;
        }
        int res = n;
        for(int i = 0; i < 26; i++) {
            int target = hash[i];
            int sum = 0;
            for(int i = 0; i < 26; i++) {
                if(hash[i] >= target) {
                    sum += min(hash[i], target + k);
                }
            }
            res = min(res, n - sum);
        }
        return res;
    }
};