class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hash;
        vector<string> res;
        int minSum = INT_MAX;
        for(int i = 0; i < list1.size(); i++) {
            hash[list1[i]] = i; 
        }
        for(int i = 0; i < list2.size(); i++) {
            if(hash.count(list2[i])) {
                int sum = hash[list2[i]] + i;
                if(sum < minSum) {
                    minSum = sum;
                    res.clear();
                    res.push_back(list2[i]);
                } else if(sum == minSum) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};