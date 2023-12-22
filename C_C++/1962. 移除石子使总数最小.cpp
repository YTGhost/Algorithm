class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        int sum = 0;
        for(auto pile : piles) {
            q.push(pile);
            sum += pile;
        }
        while(k--) {
            int t = floor(q.top() / 2);
            sum -= t;
            int pile = q.top() - t;
            q.pop();
            q.push(pile);
        }
        return sum;
    }
};