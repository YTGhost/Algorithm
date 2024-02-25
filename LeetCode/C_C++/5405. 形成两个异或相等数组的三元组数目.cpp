class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int a = 0, b = 0;
        for(int i = 0; i < arr.size() - 1; i++)
        {
            for(int j = i + 1; j < arr.size(); j++)
            {
                for(int k = j; k < arr.size(); k++)
                {
                    if(k == j)
                    {
                        a = 0, b = 0;
                        for(int t = i; t < j; t++)
                        {
                            a ^= arr[t];
                        }
                        for(int t = j; t <= k; t++)
                        {
                            b ^= arr[t];
                        }
                    }else{
                        b ^= arr[k];
                    }
                    if(a == b) ans++;
                }
            }
        }
        return ans;
    }
};