class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>v(n);
        int i=0,j=0;
        int cnt = 0;
        while(j<n){
            if(i == j){
                cnt++;
            }
            if(abs(nums[i]-nums[j])>maxDiff){
                i++;
                continue;
            }
            v[j] = cnt;
            if(i != j){
                i++;
            }
            j++;
        }
        vector<bool>ans;
        for(auto &x:queries){
            ans.push_back(v[x[0]] == v[x[1]]);
        }
        return ans;
    }
};