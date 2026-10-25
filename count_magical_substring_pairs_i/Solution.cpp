class Solution {
public:
    struct segmentTree{
        int N ;
        vector<int>tree;
        void init(int n){
            tree.resize(2*n);
            this->N = n;
            return ;
        }
        int query(int l,int r){
            l+=this->N;
            r+=this->N;
            int ans = 0;
            while(l<=r){
                if(l&1){
                    ans|=tree[l++];
                }
                if(r%2 ==0){
                    ans|=tree[r--];
                }
                l>>=1,r>>=1;
            }
            int cnt =0;
            for(int i=0;i<26;++i){
                cnt+=((1<<i)&ans)>0;
            }
            return cnt;
        }
        void update(int ind,int val){
            ind+=this->N;
            tree[ind] = val;
            ind>>=1;
            while(ind>=1){
                tree[ind] = tree[2*ind]|tree[2*ind+1];
                ind>>=1;
            }
            return ;
        }
    };
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
        segmentTree tree;
        tree.init(n);
        for(int i=0;i<n;++i){
            tree.update(i,1<<(s[i]-'a'));
        }
        int ans = 0;
        for(int i=0;i<n;++i){
            int st = 0,sizs=0;
            for(int j=i;j>=0;--j){
                if((st&(1<<(s[j]-'a'))) == 0){
                    st|=(1<<s[j]-'a');
                    sizs++;
                }
                int l = 0, h = j-1;
                int L ,R;
                if(h<0)continue;
                while(h-l>1){
                    int mid = (l+h)>>1;
                    if(tree.query(mid,j-1)>= sizs){
                        l = mid;
                    }else{
                        h = mid-1;
                    }
                }
                if(tree.query(h,j-1)==sizs){
                    L = h;
                }else if(tree.query(l,j-1)==sizs){
                    L = l;
                }else{
                    L = -1;
                }
                l = 0,h= j-1;
                while(h-l>1){
                    int mid = (l+h)>>1;
                    if(tree.query(mid,j-1)<=sizs){
                        h = mid;
                    }else{
                        l = mid+1;
                    }
                }
                if(tree.query(l,j-1)==sizs){
                    R = l;
                }else if(tree.query(h,j-1) == sizs){
                    R = h;
                }else{
                    R = -1;
                }
                if(L == -1 && R == -1)continue;
                ans+=L-R+1;
            }
        }
        return ans;
    }
};