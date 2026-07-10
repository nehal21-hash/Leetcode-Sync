class Solution {
public:
    vector<int > pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>v(n);
        vector<pair<int,int>>newNums(n);
        for(int i=0;i<n;++i){
            newNums[i] = {nums[i],i};
        }
        sort(newNums.begin(),newNums.end());
        int i=0,j=0;
        int cnt = 0;
        while(j<n){
            if(i == j){
                cnt++;
            }
            if(abs(newNums[i].first-newNums[j].first)>maxDiff){
                i++;
                continue;
            }
            v[newNums[j].second] = cnt;
            if(i != j){
                i++;
            }
            j++;
        }
        vector<int>ans;
        for(auto &x:queries){
            int dif = abs(nums[x[0]]-nums[x[1]]);
            if(dif ==0){
                if(x[0] == x[1]){
                    ans.push_back(0);
                }else{
                    ans.push_back(1);
                }
                continue;
            }
            if(maxDiff ==0){
                if(x[0] == x[1]){
                    ans.push_back(0);
                }else{
                    ans.push_back(-1);
                }
                continue;
            }
            if(v[x[0]] == v[x[1]]){
                ans.push_back((dif+maxDiff-1)/maxDiff);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};