class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> V(amount + 1);
        const int INF = 0x3f3f3f3f;
        for (int i = 1; i <= amount; i ++) 
            V[i] = INF;
        
        for (int i = 0; i < coins.size(); i ++) {
            for (int j = coins[i]; j <= amount; j ++)
                V[j] = min(V[j], V[j - coins[i]] + 1);
        }
        if (V[amount] >= INF) return -1;
        else return V[amount]; 
    }
};
