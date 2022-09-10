class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        sort(coins.begin(),coins.end());
        int dp[10005]={0};
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
        return dp[amount]==0x3f3f3f3f?-1:dp[amount];
    }
};
