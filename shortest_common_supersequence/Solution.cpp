
                }
            }
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
                val = dp[i][j-1];
                j--;
                continue;
            }
            if(i>0 && j>0 && str1[i-1] == str2[j-1]  && dp[i-1][j-1] +1 == val){
                ans.push_back(str1[i-1]);
                val = dp[i-1][j-1];
                i--,j--;
                continue;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};