class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        /*
        dp[i][1] = max(dp[j][0]) if nums[i] == nums[j] or max(dp[j][1]) if nums[i] == nums[j]+1;
        dp[i][0] = max(dp[j][0]) if nums[i]-1 == nums[j] or max(dp[j][1]) if nums[i]-2 == nums[j];
        */
        int n= (int)nums.size();
        map<int,int> dp,dp1;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=1;i<=n;++i){
            int val = max({dp[nums[i-1]-1]+1,dp1[nums[i-1]-2]+1,1});
            int val2 = max({dp[nums[i-1]]+1,dp1[nums[i-1]-1]+1,1});
            dp[nums[i-1]] = max(val,dp[nums[i-1]]);
            dp1[nums[i-1]] = max(val2,dp1[nums[i-1]]);
            ans = max({ans,val,val2});
        }
        return ans;
    }
};