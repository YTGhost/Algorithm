class Bank {
public:
    vector<long long>& balance;
    Bank(vector<long long>& balance) : balance(balance) {}
    
    bool transfer(int account1, int account2, long long money) {
        int n = balance.size();
        if(account1 >= 1 && account1 <= n && account2 >= 1 && account2 <= n && balance[account1 - 1] >= money) {
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        int n = balance.size();
        if(account >= 1 && account <= n) {
            balance[account - 1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        int n = balance.size();
        if(account >= 1 && account <= n && balance[account - 1] >= money) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */