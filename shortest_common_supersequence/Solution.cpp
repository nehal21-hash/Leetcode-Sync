        }
        int i= n,j=m;
        int val = dp[n][m];
        string ans;
        while(i !=0 || j !=0){
            if(i>0 && dp[i-1][j]+1 == val){
                ans.push_back(str1[i-1]);
                val = dp[i-1][j];
                i--;
                continue;
            }
            if(j>0 && dp[i][j-1]+1 == val){
                ans.push_back(str2[j-1]);
            }
                }
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1);
                if(str1[i-1] == str2[j-1]){
                dp[i][j] = min(dp[i][j-1]+1,dp[i-1][j]+1);
            for(int j=1;j<=m;++j){
        for(int i=1;i<=n;++i){
        }
            dp[i][0] = i;
                val = dp[i][j-1];
                j--;
        for(int i=0;i<=n;++i){
        }
            dp[0][i] = i;
        for(int i=0;i<=m;++i){
        dp[0][0] = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e7));
        int n = (int)str1.size(), m =(int)str2.size();
    string shortestCommonSupersequence(string str1, string str2) {
