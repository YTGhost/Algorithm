class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        int n = encoded.size();
        res.push_back(first);
        for(int i = 0; i < n; i++) {
            int t = encoded[i] ^ res[i];
            res.push_back(t); 
        }
        return res;
    }
};