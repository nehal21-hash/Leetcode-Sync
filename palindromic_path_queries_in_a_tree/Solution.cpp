const int N = 2e5+100,M = 25;
int up[N][M],depth[N],Parent[N];
class Solution {
public:
    vector<pair<int,int>>Euler;
    int t,size;
    void dfs1(int node , vector<int>graph[],int parent){
        for(auto &child:graph[node]){
            if(child != parent){
                depth[child] = depth[node]+1;
                Parent[child] = node;
                dfs1(child,graph,node);
            }
        }
        return ;
    }
    void binaryLifting(vector<int>graph[],int n){
        for(int i=1;i<=n;++i){
            up[i][0] = Parent[i];
        }
        for(int i=1;i<M;++i){
            for(int j=1;j<=n;++j){
                up[j][i] = up[up[j][i-1]][i-1];
            }
        }
        return ;
    }
    int LCA(int a,int b){
        int deptha = depth[a],depthb = depth[b];
        if(deptha<depthb){
            swap(deptha,depthb);
            swap(a,b);
        }
        deptha-=depthb;
        for(int j=M-1;j>=0;--j){
            if(deptha>=(1<<j)){
                a = up[a][j];
                deptha-=(1<<j);
            }
        }
        if(a == b){
            return a;
        }
    
        for(int j=M-1;j>=0;--j){
            if(up[a][j] != up[b][j]){
                a = up[a][j],b=up[b][j];
            }
        }
        return up[a][0];
    }

    void dfs(int node,vector<int>graph[],int parent){
        Euler[t++].first = node;
        for(auto &child:graph[node]){
            if(child == parent)continue;

            dfs(child,graph,node);
        }
        Euler[t++].first = node;
        return ;
    }
    struct segmentTree{
        int N ;
        vector<int>tree;
        void init(int n, vector<int>&v){
            tree.resize(2*n);
            this->N = n ;
            for(int i=n;i<2*n;++i){
                tree[i] = v[i-n];
            }
            for(int i=n-1;i>=1;--i){
                tree[i] = tree[2*i]^tree[2*i+1];
            }
            return ;
        }
        void update(int ind ,int val){
            ind+=this->N;
            tree[ind] = val;
            ind>>=1;
            while(ind>=1){
                tree[ind] = tree[ind*2]^tree[2*ind+1];
                ind>>=1;
            }
            return ;
        }
        int query(int l,int r){
            l+=this->N;
            r+=this->N;
            int ans =0;
            while(l<=r){
                if(l&1){
                    ans^=tree[l++];
                }
                if(r%2 ==0){
                    ans^=tree[r--];
                }
                r>>=1,l>>=1;
            }
            return ans;
        }
    };
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<int>graph[n+1];
        Euler.resize(5*n);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        t = 0;
        dfs(0,graph,-1);
        Parent[0] = 0;
        depth[0] = 0;
        dfs1(0,graph,-1);
        binaryLifting(graph,n);
        vector<int>v;
        set<int>vis;
        map<int,int>t1,t2;
        for(int i=0;i<t;++i){
            Euler[i].second = 1<<(s[Euler[i].first]-'a');
            v.push_back(Euler[i].second);
            if(vis.find(Euler[i].first) == vis.end()){
                t1[Euler[i].first] = i;
                vis.insert(Euler[i].first);
            }else{
                t2[Euler[i].first] = i;
            }
        }
        segmentTree tree;
        tree.init((int)v.size(),v);
        vector<bool>ans;
        //cout<<t1[1]<<endl;
        for(auto &x:queries){
            if(x[0] == 'u'){
                int node = 0;
                int m = (int)x.size();
                int j = 7;
                while(j<m && x[j] != ' '){
                    node*=10;
                    node+=x[j]-'0';
                    j++;
                }
                j++;
                s[node] = x[j];
                int val = 1<<(x[j]-'a');
                tree.update(t1[node],val);
                tree.update(t2[node],val);
                v[t1[node]] = val;
                v[t2[node]] = val;
            }else{
                int m = (int)x.size();
                int j = 6;
                int u = 0,v=0;
                while(j<m && x[j] != ' '){
                    u*=10;
                    u+=x[j]-'0';
                    j++;
                }
                j++;
                while(j<m && x[j] !=' '){
                    v*=10;
                    v+=x[j]-'0';
                    j++;
                }
                int T1 = t1[u],T2 = t1[v];
                int tempans = tree.query(0,T1);
                tempans^=tree.query(0,T2);
                tempans^=1<<(s[LCA(u,v)]-'a');
                cout<<LCA(u,v)<<endl;
                int cnt =0;
                for(int i=0;i<26;++i){
                    if((1<<i)&tempans){
                        cnt++;
                    }
                }
                ans.push_back(cnt <=1);
            }
        }
        return ans;
    }
};