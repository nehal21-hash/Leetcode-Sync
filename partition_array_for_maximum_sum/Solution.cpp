class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //dp[i] = max(dp[i-j]) 1<=j<=k;
        int n = (int)arr.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;++i){
            int val = arr[i-1];
            dp[i] = val;
            if(i>0){
                dp[i]= dp[i-1]+val;
            }
            for(int j=i-1;j>i-k;--j){
                if(j<=0)continue;
                val = max(val,arr[j-1]);
                dp[i] = max(dp[i],(i-j+1)*val);
                if(j>0){
                    dp[i] = max(dp[i],dp[j-1]+(i-j+1)*val);
                }
                if(i == 4){
                    cout<<i<<" "<<j<<" "<<dp[i]<<endl;
                }
            }
        }
        for(int i=1;i<=n;++i){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        return dp[n];
    }
};