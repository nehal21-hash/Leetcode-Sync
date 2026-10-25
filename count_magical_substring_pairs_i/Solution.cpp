class Solution {
public:
    int countMagicalPairs(string s) {
        /*
        dp[i][mask] - > no of subtring which ends at i such that the no of distinct character is j
        ----------k------[l---i]------------------
        dp[l-1][5]
        for each i
            set s which track distinct character
            for l i to 0
                s.insert(s[l]);
                ans+=dp[l-1][(int)s.size()];
        */
        int n = (int)s.size();
        int left[n][27],right[n][27];
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        for(int i=0;i<n;++i){
            int sizes =0,st =0;
            for(int j=i;j>=0;--j){
                if((st&(1<<(s[j]-'a'))) ==0){
                    st|=(1<<(s[j]-'a'));
                    sizes++;
                }
                left[i][sizes]++;
            }
        }
        for(int i=n-1;i>=0;--i){
            int sizes =0,st =0;
            for(int j=i;j<n;++j){
                if((st&(1<<(s[j]-'a'))) ==0){
                    st|=(1<<(s[j]-'a'));
                    sizes++;
                }
                right[i][sizes]++;
            }
        }
        int ans =0;
        for(int i=0;i<n-1;++i){
            for(int j=1;j<=26;++j){
                ans+=left[i][j]*right[i+1][j];
            }
        }
        return ans;
    }
};