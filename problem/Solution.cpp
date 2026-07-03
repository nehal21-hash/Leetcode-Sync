class Solution {
public:
    string shortestCommonSupersequence
    (string str1, string str2) {
        int n = (int)str1.size(), m =(int)
        str2.size();
        vector<vector<int>>dp(n+1,
        vector<int>(m+1,1e7));
        dp[0][0] = 0;
        for(int i=0;i<=m;++i){
            dp[0][i] = i;
        }
