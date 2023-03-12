class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        for(auto gift : gifts) {
            q.push(gift);
        }
        while(k--) {
            int t = q.top();
            q.pop();
            q.push(sqrt(t));
        }
        long long res = 0;
        while(q.size()) {
            res += q.top();
            q.pop();
        }
        return res;
    }
};