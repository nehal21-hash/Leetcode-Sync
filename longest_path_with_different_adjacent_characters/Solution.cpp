class Solution {
public:
    vector<vector<int>>stores;
    int ans =0;
    int dfs(int node,vector<int>graph[],int parent, string &s){
        int ans =0;
        for(auto &child:graph[node]){
            if(child == parent)continue;
            int val = dfs(child,graph,node,s);
            if(s[node] != s[child]){
                ans = max(ans,val+1);
                if((int)stores[node].size() == 2){
                    if(stores[node][0]>stores[node][1]){
                        swap(stores[node][0],stores[node][1]);
                    }
                }
                if((int)stores[node].size()<2 ){
                    stores[node].push_back(val+1);
                }else if(*stores[node].begin() <val+1){
                    stores[node][0] = val+1;
                }
            }
        }
        return ans;
    }
    void dfs0(int node ,vector<int>graph[],int parent,string &s){
        if(!stores[node].empty()){
            ans = max(ans,*max_element(stores[node].begin(),stores[node].end())); 
        }
        int pVal = 0;
        if((int)stores[node].size() == 2){
            if(stores[node][0]>stores[node][1]){
                swap(stores[node][0],stores[node][1]);
            }
        }
        for(auto &child:graph[node]){
            int childVal = 0;
            if(!stores[child].empty()){
                childVal = *max_element(stores[child].begin(),stores[child].end());
            }
            if(!stores[node].empty()){
                pVal = *stores[node].rbegin();
            }
            if((int)stores[node].size()>1 && childVal+1 ==  *stores[node].rbegin() && s[child] != s[node]){
                pVal = *stores[node].begin();
            }
            if(stores[node].size() == 1 && childVal+1 == *stores[node].begin() && s[child] != s[node]){
                pVal = 0;
            }
            if(s[child] != s[node]){
                if((int)stores[child].size() == 2){
                    if(stores[child][0]>stores[child][1]){
                        swap(stores[child][0],stores[child][1]);
                    }
                }
                if((int)stores[child].size()<2){
                    stores[child].push_back(pVal+1);
                }else if(*stores[child].begin() <pVal+1){
                    stores[child][0] = pVal+1;
                }
            }
            if(child == parent)continue;
            dfs0(child,graph,node,s);
        }
        return ;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = (int)parent.size();
        vector<int>graph[n+1];
        stores.resize(n+1);
        for(int i=1;i<n;++i){
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
        ans =0;
        int p = dfs(0,graph,-1,s);
        dfs0(0,graph,-1,s);
        return ans+1;
    }
};