class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[candyType[i]]++;
        }
        return min(n / 2, (int)hash.size());
    }
};

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