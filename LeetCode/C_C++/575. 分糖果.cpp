class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        int cnt = 0;
        for(auto candy : candyType) {
            if(!s.count(candy)) {
                s.insert(candy);
                cnt++;
            }
        }
        return candyType.size() / 2 > cnt ? cnt : candyType.size() / 2; 
    }
};