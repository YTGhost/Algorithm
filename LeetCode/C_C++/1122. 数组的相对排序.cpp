class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> fre(1001, 0);
        vector<int> res;
        for(auto num : arr1) fre[num]++;
        for(auto num : arr2)
        {
            while(fre[num]){
                res.emplace_back(num);
                fre[num]--;
            }
        }
        for(int i = 0; i < 1001; i++)
        {
            while(fre[i]){
                res.emplace_back(i);
                fre[i]--;
            }
        }
        return res;
    }
};