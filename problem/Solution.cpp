        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                dp[i][j] = min(dp[i][j-1]
                +1,dp[i-1][j]+1);
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = min(dp[i]
                    [j],dp[i-1][j-1]+1);
                }
            }
        }
        int i= n,j=m;
        int val = dp[n][m];
        }
