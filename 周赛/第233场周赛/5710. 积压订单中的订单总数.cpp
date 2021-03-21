class Solution {
public:
    struct buy{
        int price, amount;
        bool operator< (const buy& t) const
        {
            return price < t.price;
        }
    };
    struct sell{
        int price, amount;
        bool operator< (const sell& t) const
        {
            return price > t.price;
        }
    };
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<buy> buyHeap;
        priority_queue<sell> sellHeap;
        int n = orders.size();
        long long res = 0;
        for(int i = 0; i < n; i++)
        {
            if(orders[i][2]) {
                while(!buyHeap.empty() && buyHeap.top().price >= orders[i][0]) {
                    if(orders[i][1] >= buyHeap.top().amount) {
                        orders[i][1] -= buyHeap.top().amount;
                        buyHeap.pop();
                    } else {
                        int amount = buyHeap.top().amount - orders[i][1];
                        int price = buyHeap.top().price;
                        buyHeap.pop();
                        buyHeap.push({price, amount});
                        orders[i][1] = 0;
                        break;
                    }
                }
                if(orders[i][1]) sellHeap.push({orders[i][0], orders[i][1]});
            } else {
                while(!sellHeap.empty() && sellHeap.top().price <= orders[i][0]) {
                    if(orders[i][1] >= sellHeap.top().amount) {
                        orders[i][1] -= sellHeap.top().amount;
                        sellHeap.pop();
                    } else {
                        int amount = sellHeap.top().amount - orders[i][1];
                        int price = sellHeap.top().price;
                        sellHeap.pop();
                        sellHeap.push({price, amount});
                        orders[i][1] = 0;
                        break;
                    }
                }
                if(orders[i][1]) buyHeap.push({orders[i][0], orders[i][1]});
            }
        }
        while(!buyHeap.empty()) {
            res += buyHeap.top().amount;
            buyHeap.pop();
        }
        res %= 1000000007;
        while(!sellHeap.empty()) {
            res += sellHeap.top().amount;
            sellHeap.pop();
        }
        res %= 1000000007;
        return res;
    }
};