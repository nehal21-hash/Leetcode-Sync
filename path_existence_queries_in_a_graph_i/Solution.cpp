class Solution {
public:
    vector<int>parent;
    int find_set(int u){
        if(parent[u] == u)return u;

        return parent[u] = find_set(parent[u]);
    }
    void union_set(int a,int b){
        int u = find_set(a),v = find_set(b);
        if(u != v){
            parent[u] = v;
        }
        return ;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n+1);
        int i=0,j=0;
        for(int i=0;i<n;++i){
            parent[i] = i;
        }
        while(j<n){
            if(abs(nums[i]-nums[j])>maxDiff){
                i++;
                continue;
            }
            union_set(i,j);
            j++;
        }
        vector<bool>ans;
        for(auto &x:queries){
            ans.push_back(find_set(x[0]) == find_set(x[1]));
        }
        return ans;
    }
};