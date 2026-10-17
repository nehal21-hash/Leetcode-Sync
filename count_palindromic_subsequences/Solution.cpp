class Solution {
public:
    int countPalindromes(string s) {
        vector<string>v;
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
                for(int k=0;k<10;++k){
                    string p = to_string(i) + to_string(j) + to_string(k) + to_string(j) + to_string(i);
                    v.push_back(p);
                }
            }
        }
        long long ans =0;
        int n =(int)s.size();
        int M = 1e9+7;
        // dp[i][j] - > dp[i][j-1] + (dp[i-1][j-1] if and only if x[i] == s[j]);
        for(auto &x:v){
            cout<<x<<endl;
            vector<vector<int>>dp(5,vector<int>(n,0));
            for(int i=0;i<5;++i){
                for(int j=0;j<(int)s.size();++j){
                    if(j>0){
                        dp[i][j]+=dp[i][j-1];
                    }
                    if(s[j] == x[i]){
                        if(i ==0){
                            dp[i][j]++;
                        }
                        if(j>0 && i>0){
                            dp[i][j]+=dp[i-1][j-1];
                        }
                    }
                    dp[i][j]%=M;
                }
            }
            ans+=dp[4][n-1];
            ans%=M;
        }
        return ans;
    }
};